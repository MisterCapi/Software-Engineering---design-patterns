#include <iostream>

using namespace std;

class Enemy {
public:
    void heal(){
        this->health += 10;
    }

    static void move(){
        cout << "swift move\n";
    }

    virtual void attack() = 0;
private:
    int health = 100;
};


class RangedEnemy : public Enemy {
public:
    void attack() override{
        RangedEnemy::move();
        cout << "ranged attack\n";
        RangedEnemy::move();
    }
};


class MeleeEnemy : public Enemy {
public:
    void attack() override{
        MeleeEnemy::move();
        cout << "melee attack\n";
        MeleeEnemy::move();
    }
};


int main() {
    RangedEnemy re = RangedEnemy();
    MeleeEnemy me = MeleeEnemy();

    cout << "Ranged enemy:\n";
    re.attack();

    cout << "\nMelee enemy:\n";
    me.attack();

    return 0;
}
