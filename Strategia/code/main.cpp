#include <iostream>
#include <climits>

using namespace std;

class Classifier {
public:
    virtual void train(int X_train, int y_train) = 0;
    virtual void test(int X_test, int y_test) = 0;
    virtual void predict(int X) = 0;
};


class KNN : public Classifier {
public:
    void train(int X_train, int y_train) override{
        cout << "KNN Classifier is training:\n";
        for(int i=0; i<10; i++){
            cout << "[";
            for(int j=0; j<i; j++){
                cout << ">";
            }
            for(int j=0; j<(10-i-1); j++){
                cout << "-";
            }
            cout << "] accuracy: " << (float(rand()) / float(INT16_MAX) + float(i)) / 11.0 << "\n";
        }
    }

    void test(int X_test, int y_test) override{
        cout << "KNN accuracy on testing set: " << (float(rand()) / float(INT16_MAX) + 4.0) / 5.0 * 100.0 << " %\n";
    }

    void predict(int X) override{
        cout << "KNN is predicting\n";
    }
};


class SVM : public Classifier {
public:
    void train(int X_train, int y_train) override{
        cout << "SVM Classifier is training:\n";
        for(int i=0; i<10; i++){
            cout << "[";
            for(int j=0; j<i; j++){
                cout << ">";
            }
            for(int j=0; j<(10-i-1); j++){
                cout << "-";
            }
            cout << "] accuracy: " << (float(rand()) / float(INT16_MAX) + float(i)) / 11.0 << "\n";
        }
    }

    void test(int X_test, int y_test) override{
        cout << "SVM accuracy on testing set: " << (float(rand()) / float(INT16_MAX) + 4.0) / 5.0 * 100.0 << " %\n";
    }

    void predict(int X) override{
        cout << "SVM is predicting\n";
    }
};


class RandomForest : public Classifier {
public:
    void train(int X_train, int y_train) override{
        cout << "RandomForest Classifier is training:\n";
        for(int i=0; i<10; i++){
            cout << "[";
            for(int j=0; j<i; j++){
                cout << ">";
            }
            for(int j=0; j<(10-i-1); j++){
                cout << "-";
            }
            cout << "] accuracy: " << ((float(rand()) / float(INT16_MAX)) + float(i)) / 11.0 << "\n";
        }
    }

    void test(int X_test, int y_test) override{
        cout << "RandomForest accuracy on testing set: " << (float(rand()) / float(INT16_MAX) + 4.0) / 5.0 * 100.0 << " %\n";
    }

    void predict(int X) override{
        cout << "RandomForest is predicting\n";
    }
};


class ClassificationML {
public:
    ClassificationML(string data){
        this->data = move(data);
    }

    void setClassifier(Classifier* clasiffier){
        this->classifier = clasiffier;
    }

    void trainAndTest(){
        this->classifier->train(1, 1);
        this->classifier->test(1, 1);
    }

    void predict(){
        this->classifier->predict(5);
    }

private:
    string data;
    Classifier* classifier = nullptr;
};


int main() {
    KNN knn = KNN();
    SVM svm = SVM();
    RandomForest randomForest = RandomForest();

    ClassificationML experiment = ClassificationML("secret data: {doge prices}");

    cout << "Trying diffecrent algos:\n\n";

    experiment.setClassifier(&knn);
    experiment.trainAndTest();
    cout << "\n";

    experiment.setClassifier(&svm);
    experiment.trainAndTest();
    cout << "\n";

    experiment.setClassifier(&randomForest);
    experiment.trainAndTest();


    return 0;
}
