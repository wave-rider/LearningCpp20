#include <stdexcept>
#include <functional>
#include <iostream>
using namespace std;

class ReptileEgg;

class Reptile
{
public:
    virtual ~Reptile() {};
    virtual ReptileEgg* lay() = 0;
};

class ReptileEgg
{
public:
    ReptileEgg()
    {
        std::cout << "Reptile egg " << is_hatched;
    }
    ReptileEgg(std::function<Reptile* ()> createReptile)
    {
        create_reptile = createReptile;
    }

    Reptile* hatch()
    {
        if (is_hatched == true) {
            throw std::logic_error("The egg has been already hatched.");
        }
        is_hatched = true;
        return create_reptile();
    }
private:
    std::function<Reptile* ()> create_reptile;
    bool is_hatched;// = false;
};


class FireDragon : public Reptile
{
public:
    FireDragon()
    {
    }

    ReptileEgg* lay()
    {
        return new ReptileEgg([]() {  return new FireDragon(); });
    }
};

#ifndef RunTests
int main()
{
    ReptileEgg egg2;
    Reptile* fireDragon = new FireDragon();

    ReptileEgg* egg = fireDragon->lay();
    Reptile* childDragon = egg->hatch();
}
#endif