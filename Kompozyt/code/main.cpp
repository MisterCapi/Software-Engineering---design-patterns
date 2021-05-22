#include <iostream>
#include <vector>

using namespace std;


class IComputingDevice {
public:
    virtual void computeSomething() = 0;
};


class ComputingCluster : public IComputingDevice {
public:
    void addComputer(IComputingDevice* computer){
        this->computers.push_back(computer);
    }

    void computeSomething() override{
        cout << "Computing cluster is working\n";
    }

private:
    vector<IComputingDevice*> computers;
};


class Computer : public IComputingDevice {
public:
    explicit Computer(int computingPower){
        this->computingPower = computingPower;
    }

    void computeSomething() override{
        cout << "Single Computer is working\n";
    }

private:
    int computingPower;
};


int main() {
    IComputingDevice* comp1 = new Computer(5);
    IComputingDevice* comp2 = new Computer(5);
    IComputingDevice* comp3 = new Computer(5);

    comp3->computeSomething();

    ComputingCluster cluster = ComputingCluster();
    cluster.addComputer(comp1);
    cluster.addComputer(comp2);
    cluster.addComputer(comp3);

    cluster.computeSomething();
    return 0;
}
