#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class ShipMediator;

class BattleShip {
public:
    BattleShip(int init_position, ShipMediator* mediator){
        this->mediator = mediator;
        this->position = init_position;
    }

    void move();
    void shoot(int position);

    int position;
private:
    ShipMediator* mediator;
};


class ShipMediator {
public:

    void add_ships(vector<BattleShip*> ships) {
        this->all_ships = move(ships);
    }

    void make_action(string action, int pos){
        if (action == "move"){
            int ships_in_pos = 0;
            for(auto ship : all_ships){
                if (ship->position == pos){
                    ships_in_pos += 1;
                }
            }
            if (ships_in_pos > 1)
                cout << "Ships have crashed\n";
            else
                cout << "Ship can move freely\n";
        }
        else if (action == "shoot"){
            for(auto ship : all_ships){
                if (ship->position == pos){
                    cout << "Enemy ship was hit by attack\n";
                }
            }
                cout << "Allied ship stopped firing\n";
        }
    }
private:
    vector<BattleShip*> all_ships;
};

void BattleShip::move(){
    if (rand() % 2)
        position -= 1;
    else
        position += 1;
    position %= 25;

    mediator->make_action("move", position);
}

void BattleShip::shoot(int position){
    mediator->make_action("shoot", position);
}

int main() {
    ShipMediator mediator = ShipMediator();
    vector<BattleShip*> my_ships;

    for (int i=0; i<10; i++){
        auto* ship = new BattleShip(i, &mediator);
        my_ships.push_back(ship);
    }

    mediator.add_ships(my_ships);

    for (int i=0; i<20; i++){
        cout << "SHIP #" << i%10 << " :: ";
        if (rand() % 2)
            my_ships[i%10]->move();
        else
            my_ships[i%10]->shoot(i%25 + 1);
    }
    return 0;
}
