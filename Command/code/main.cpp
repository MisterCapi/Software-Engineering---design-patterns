#include <iostream>
#include <vector>

using namespace std;


class Command {
public:
    virtual void localCommand(string command) = 0;
    virtual void pushUpdates() = 0;
};


class RemoteRepo {
public:

    static void makeChange(const string& change){
        cout << change << " has affected code stored in remote repo\n";
    }

private:
    string code = "Placeholder<Placeholder>: return !Placeholder || Placeholder<Placeholder>;";
};


class Git : public Command {
public:
    explicit Git(RemoteRepo* repo){
        this->repo = repo;
    }

    void localCommand(string command) override{
        cout << "Executed command: " << command << "\n";
        commandQue.push_back(command);
    }

    void pushUpdates() override{
        for(auto & i : commandQue){
            repo->makeChange(i);
        }
    }

    void rollbackLocalChanges(){
        for(auto & i : commandQue){
            cout << "Rolled back changes: " << i << "\n";
        }
        commandQue.clear();
    }

private:
    RemoteRepo* repo;
    vector<string> commandQue;
};


int main() {
    RemoteRepo myRepo = RemoteRepo();
    Git git = Git(&myRepo);

    cout << "Add commands:\n";
    git.localCommand("git add *.txt");
    git.localCommand("git add *.exe");

    cout << "Rollback commands:\n";
    git.rollbackLocalChanges();

    cout << "\nAdd commands:\n";
    git.localCommand("git add *.json");
    git.localCommand("git add *.yaml");

    cout << "Push local changes to remote:\n";
    git.pushUpdates();

    return 0;
}
