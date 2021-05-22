#include <iostream>

using namespace std;


class DataStorage {
public:
    virtual void SQLQuerry(string querry) = 0;
};


class DataBase : public DataStorage {
public:
    DataBase(string valuableData){
        this->valuableData = move(valuableData);
    }

    void SQLQuerry(string querry) override{
        if(querry == "DROP DATABASE"){
            cout << "DROP DATABASE was executed, the valuable data is lost :O\n";
        }
        else{
            cout << "Normal querry was executed\n";
        }
    }

private:
    string valuableData;
};


class DataBaseProxy : public DataStorage {
public:
    DataBaseProxy(DataBase* database){
        this->database = database;
    }

    void SQLQuerry(string querry){
        if(querry == "DROP DATABASE"){
            cout << "DROP DATABASE was caught by proxy, the valuable data is safe :)\n";
        }
        else{
            database->SQLQuerry(querry);
        }
    }

private:
    DataBase* database;
};


int main() {
    DataBase myDB = DataBase("Future DOGE price");
    DataBaseProxy dbAPI = DataBaseProxy(&myDB);

    cout << "Direct call to the database:\n";
    myDB.SQLQuerry("SELECT * FROM future_doge_price");
    myDB.SQLQuerry("DROP DATABASE");

    cout << "\nCalling database trough proxy:\n";
    dbAPI.SQLQuerry("SELECT * FROM future_doge_price");
    dbAPI.SQLQuerry("DROP DATABASE");

    return 0;
}
