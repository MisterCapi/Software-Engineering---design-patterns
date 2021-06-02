#include <iostream>

using namespace std;


class PackageInterface {
public:
    virtual void makeCalculations(int json_data) = 0;
};


class SuperCalc {
public:
    static void makeCalculationsCSVData(int csv_data){
        cout << "I am doing calculations for csv file\n";
    }

};


class super_adapter : public PackageInterface {
public:
    void makeCalculations(int json_data) override{
        cout << "I am converting json data to csv format\n";
        int csv_data = json_data;
        SuperCalc::makeCalculationsCSVData(csv_data);
    }

private:
    SuperCalc adaptee = SuperCalc();
};


int main() {
    cout << "Normal calc on csv\n";
    SuperCalc::makeCalculationsCSVData(5);

    cout << "\nCalculation on json trough adapter\n";
    super_adapter adap = super_adapter();
    adap.makeCalculations(15);

    return 0;
}
