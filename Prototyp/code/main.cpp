#include <iostream>
#include <utility>

using namespace std;


class CarPrototype {
public:
    CarPrototype(int speed, string name){
        cout << "CarPrototype Constructor was called with: speed - " << speed << ", name - " << name << "\n";
        this->name = move(name);
        this->speed = speed;
    }

    explicit CarPrototype(CarPrototype* carToCpy){
        cout << "CarPrototype Copying Constructor was called with: speed - " << carToCpy->speed << ", name - " << carToCpy->name << "\n";
        this->name = carToCpy->name;
        this->speed = carToCpy->speed;
    }

    virtual CarPrototype* clone() = 0;

private:
    int speed;
    string name;
};


class FastCar : public CarPrototype {
public:
    FastCar(int speed, string name, bool turbo) : CarPrototype(speed, name) {
        cout << "FastCar Constructor was called with: speed - " << speed << ", name - " << name << ", turbo - " << turbo << "\n";
        this->turbo = turbo;
    }

    explicit FastCar(FastCar* carToCpy) : CarPrototype(carToCpy){
        cout << "FastCar Copying Constructor was called with: turbo - " << carToCpy->turbo << "\n";
        this->turbo = carToCpy->turbo;
    }

    FastCar* clone() override{
        return new FastCar(this);
    }

private:
    bool turbo;
};


int main() {
    cout << "Creating original car:\n";
    FastCar* porshe = new FastCar(298, "Porshe 991", true);
    cout << "\nCopying the car:\n";
    FastCar* my2ndPorshe = porshe->clone();

    cout << "\nProof that objects have been copied:\n";
    cout << "Original car address: " << porshe << "\n";
    cout << "Copied car address: " << my2ndPorshe << "\n";

    return 0;
}
