#include <iostream>

using namespace std;

class Stance {
public:
    virtual string getName() = 0;
};

class HighStance : public Stance {
public:
    string getName() override{
        return "HighStance";
    }
};

class ShieldStance : public Stance {
public:
    string getName() override{
        return "ShieldStance";
    }
};

class Spin2Win : public Stance {
public:
    string getName() override{
        return "Spin2Win";
    }
};


class MeleeFighter {
public:
    void attack(){
        if (stance->getName() == "HighStance"){
            cout << "Attack with a sword using high stance\n";
        }
        else if (stance->getName() == "ShieldStance"){
            cout << "Attack hiding behind shield\n";
        }
        else if (stance->getName() == "Spin2Win"){
            cout << "Spinning attack\n";
        }
    }

    void change_stance(Stance* new_stance){
        stance = new_stance;
    }

private:
    Stance* stance;
};


int main() {
    HighStance stance1 = HighStance();
    ShieldStance stance2 = ShieldStance();
    Spin2Win stance3 = Spin2Win();

    MeleeFighter fighter = MeleeFighter();

    fighter.change_stance(&stance1);
    fighter.attack();

    fighter.change_stance(&stance2);
    fighter.attack();

    fighter.change_stance(&stance3);
    fighter.attack();
    return 0;
}
