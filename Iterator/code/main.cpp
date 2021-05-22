#include <iostream>
#include <vector>


class Iterator {
public:
    virtual char getNext() = 0;
    virtual bool isNext() = 0;
};


class Iterable {
public:
    virtual Iterator* getIterator() = 0;
};


class MyString : public Iterable {
public:
    explicit MyString(std::vector<char> characters){
        this->characters = characters;
    }

    std::vector<char> getCharacters(){
        return this->characters;
    }

    Iterator* getIterator() override;
private:
    std::vector<char> characters;
};


class StringIterator : public Iterator {
public:
    explicit StringIterator(MyString *myString){
        this->myString = myString;
        this->i = 0;
    }

    bool isNext() override{
        return this->i < myString->getCharacters().size();
    }

    char getNext() override{
        if(this->isNext()){
            return myString->getCharacters()[i++];
        }

        return 0;
    }

private:
    MyString* myString;
    int i;
};

Iterator* MyString::getIterator() {
    return new StringIterator(this);
}

using namespace std;

int main() {
    vector<char> text = {'H', 'a', 'l', 'o', '.'};

    MyString superString = MyString(text);

    Iterator* iterator = superString.getIterator();

    while(iterator->isNext()){
        cout << iterator->getNext() << "\n";
    }
    return 0;
}
