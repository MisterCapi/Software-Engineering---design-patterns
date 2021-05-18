#include <iostream>

using namespace std;


class SUV {
};


class Sedan {
};


class Corolla : public Sedan {
};


class Focus : public Sedan {
};


class RAV4 : public SUV {
};


class Bronco : public SUV {
};


class CarFactory {
public:
    virtual SUV makeSUV() = 0;
    virtual Sedan makeSedan() = 0;
};


class ToyotaCarFactory : public CarFactory {
public:
    SUV makeSUV(){
        cout << "Toyota factory created Toyota RAV4\n";
        return RAV4();
    }

    Sedan makeSedan(){
        cout << "Toyota factory created Toyota Corolla\n";
        return Corolla();
    }
};


class FordCarFactory : public CarFactory {
public:
    SUV makeSUV(){
        cout << "Ford factory created Ford Bronco\n";
        return Bronco();
    }

    Sedan makeSedan(){
        cout << "Ford factory created Ford Focus\n";
        return Focus();
    }
};


int main() {
    ToyotaCarFactory toyota_car_factory = ToyotaCarFactory();
    FordCarFactory ford_car_factory = FordCarFactory();

    SUV car1 = toyota_car_factory.makeSUV();
    SUV car2 = ford_car_factory.makeSUV();
    Sedan car3 = toyota_car_factory.makeSedan();
    Sedan car4 = ford_car_factory.makeSedan();

    return 0;
}
