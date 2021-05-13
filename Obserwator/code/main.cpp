#include <iostream>
#include <vector>

using namespace std;

class Observer {
public:
    virtual int attackPlayerIfInRange() = 0;
};

class Tower : public Observer {
public:
    Tower(float damage){
        this->damage = damage;
    }

    int attackPlayerIfInRange(){
        if(rand() > RAND_MAX/2){
            return damage;
        }
        return 0;
    }

private:
    float damage;
};

class Mob : public Observer {
public:
    Mob(string name, float damage){
        this->name = move(name);
        this->damage = damage;
    }

    int attackPlayerIfInRange(){
        if(rand() > RAND_MAX/2){
            return damage;
        }
        return 0;
    }

private:
    string name;
    float damage;
};

class Player {
public:
    Player(){
        this->health = 200;
        this->xp = 0;
        this->level = 1;
    }

    void checkObservers(){
        for(int i=0; i<observers.size(); i++){
            if(health > 0) {
                int damage = observers[i]->attackPlayerIfInRange();

                if (damage) {
                    health -= damage;
                    cout << "Player has lost " << damage << " HP, now has " << (health < 0 ? 0 : health) << " HP\n";
                }
            }
            else{
                cout << "Player is dead!\n";
                break;
            }
        }
    }

    void addObserver(Observer* observer){
        observers.push_back(observer);
    }

    bool isAlive(){
        return health > 0;
    }

private:
    int health;
    float xp;
    int level;
    vector<Observer*> observers;
};

int main() {
    Observer* mob1 = new Mob("Orc", 7);
    Observer* mob2 = new Mob("Werewolf", 16);
    Observer* tower1 = new Tower(26);
    Observer* tower2 = new Tower(24);

    Player player = Player();

    player.addObserver(mob1);
    player.addObserver(mob2);
    player.addObserver(tower1);
    player.addObserver(tower2);

    while(player.isAlive())
        player.checkObservers();

    return 0;
}
