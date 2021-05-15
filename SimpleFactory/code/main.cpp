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


class GPUFactory {
public:
    static GPU* makeGPU(string gpuName){
        if(gpuName == "RTX3080"){
            return new RTX3080(gpuName);
        }
        else if(gpuName == "RTX3070"){
            return new RTX3070(gpuName);
        }
        else{
            throw "Passed wrong GPU name";
        }
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
    GPU* gpu1 = GPUFactory::makeGPU("RTX3080");
    GPU* gpu2 = GPUFactory::makeGPU("RTX3070");

    vector<GPU*> connected_gpus = {gpu1, gpu2};

    PC strongPC = PC("strong_PC", connected_gpus);
    strongPC.useGpusToCompute();

    return 0;
}
