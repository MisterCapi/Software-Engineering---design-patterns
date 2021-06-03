#include <iostream>
#include <utility>

using namespace std;


class Texture {
public:
    explicit Texture(string path){
        this->path = move(path);
    }

    string path;
};


class TextureLoader {
public:
    static Texture* getTexture(string path){
        return new Texture(move(path));
    }
};


class Object {
public:
    explicit Object(Texture* texture){
        this->texture = texture;
    }

    Texture* texture;
};


class SteelObject : public Object {
protected:
    explicit SteelObject(Texture *texture) : Object(texture) {}
};


class SteelBolt : public SteelObject {
public:
    explicit SteelBolt(Texture *texture) : SteelObject(texture) {}
};


class SteelWrench : public SteelObject {
public:
    explicit SteelWrench(Texture *texture) : SteelObject(texture) {}
};


int main() {
    Texture* steelTexture = TextureLoader::getTexture("steel.png");

    SteelBolt steelBolt = SteelBolt(steelTexture);
    SteelWrench steelWrench = SteelWrench(steelTexture);

    cout << "Address of Steel Bolt's texture: " << steelBolt.texture << "\nAddress of Steel Wrench's texture: " << steelWrench.texture;

    /* Output:
     * Address of Steel Bolt's texture: 0xf2a830
     * Address of Steel Wrench's texture: 0xf2a830
     * */

    return 0;
}
