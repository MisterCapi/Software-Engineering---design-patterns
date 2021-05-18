#include <iostream>

using namespace std;


class IKeyboard {
public:
    virtual void type() = 0;
};


class Keyboard : public IKeyboard {
public:
    Keyboard(string make){
        this->make = move(make);
    }

    void type(){
        cout << "Keyboard " << make << " has been used to type all the words you desired\n\n";
    }

private:
    string make;
};


class KeyboardDecorator : public IKeyboard {
public:
    KeyboardDecorator(Keyboard* base_keyboard){
        this->base_keyboard = base_keyboard;
    }

    void type(){
        base_keyboard->type();
    }

private:
    Keyboard* base_keyboard;
};


class LEDKeyboard : public KeyboardDecorator {
public:
    LEDKeyboard(Keyboard* base_keyboard) : KeyboardDecorator(base_keyboard){};

    void type() override{
        cout << "The keyboard flashes its bright lights, illuminating nearby objects likewise Aurora borealis would\n";
        KeyboardDecorator::type();
    }
};


class MechanicalKeyboard : public KeyboardDecorator{
public:
    MechanicalKeyboard(Keyboard* base_keyboard) : KeyboardDecorator(base_keyboard){};

    void type() override{
        cout << "Swift fingers of the typer create a strange but familiar sound to thy ears\n";
        KeyboardDecorator::type();
    }
};


int main() {
    Keyboard normal_keyboard1 = Keyboard("Logitech");
    Keyboard* normal_keyboard2 = new Keyboard("SteelSeries");
    Keyboard* normal_keyboard3 = new Keyboard("Razer");

    MechanicalKeyboard mechanical_keyboard = MechanicalKeyboard(normal_keyboard2);
    LEDKeyboard led_keyboard = LEDKeyboard(normal_keyboard3);

    normal_keyboard1.type();
    mechanical_keyboard.type();
    led_keyboard.type();

    return 0;
}
