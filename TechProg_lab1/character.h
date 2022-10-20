#ifndef CHARACTER_H
#define CHARACTER_H

#include <fstream>

enum CHARACTER {
    HERO = 1,
    VILLAIN,
    MONSTER
};

class Character {
public:

    virtual void show() = 0;
    virtual void edit() = 0;
    virtual void save(std::ofstream& out) = 0;
    virtual int getLvl() = 0;
    virtual const char* getName() = 0;
};

#endif //CHARACTER_H
