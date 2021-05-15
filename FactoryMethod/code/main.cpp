#include <iostream>
#include <vector>

using namespace std;

class GPU {
public:
    virtual void computeSomeMatrices() = 0;
};


class RTX3070 : public GPU {
public:
    RTX3070(string name){
        this->name = name;
    }

    void computeSomeMatrices(){
        cout << name << " is computing matrices\n";
    }

private:
    string name;
};


class RTX3080 : public GPU {
public:
    RTX3080(string name){
        this->name = name;
    }

    void computeSomeMatrices(){
        cout << name << " is computing matrices very fast\n";
    }

private:
    string name;
};


class GPUProductionLine {
public:
    virtual GPU* makeGPU() = 0;
};


class RTX3080ProductionLine : public GPUProductionLine {
public:
    GPU* makeGPU(){
        cout << "RTX3080\n";
        return new RTX3080("RTX3080");
    }
};


class RTX3070ProductionLine : public GPUProductionLine {
public:
    GPU* makeGPU(){
        cout << "RTX3070\n";
        return new RTX3070("RTX3070");
    }
};


class GPUFactory {
public:
    static GPU* makeGPU(GPUProductionLine* productionLine){
        cout << "Factory is starting a production line for: ";
        return productionLine->makeGPU();
    }
};


class PC {
public:
    PC(string name, vector<GPU*> gpus){
        this->name = move(name);
        this->gpus = move(gpus);
    }

    void useGpusToCompute(){
        cout << "PC (" << name << ") is using GPUs to compute\n";
        for(unsigned int i=0; i<gpus.size(); i++){
            gpus[i]->computeSomeMatrices();
        }
    }

private:
    string name;
    vector<GPU*> gpus;
};


int main() {
    GPUProductionLine* rtx3080ProdLine = new RTX3080ProductionLine();
    GPUProductionLine* rtx3070ProdLine = new RTX3070ProductionLine();

    GPU* gpu1 = GPUFactory::makeGPU(rtx3080ProdLine);
    GPU* gpu2 = GPUFactory::makeGPU(rtx3070ProdLine);

    vector<GPU*> connected_gpus = {gpu1, gpu2};

    PC strongPC = PC("strong_PC", connected_gpus);
    strongPC.useGpusToCompute();

    return 0;
}
