#ifndef VILLAIN_H
#define VILLAIN_H

#include "character.h"
#include <fstream>
#include <iostream>
#include "get_int.h"
#include <cstring>

class Villain : public Character {
private:
    char name[64];
    char weapon_type[64];
    char crime[64];
    char habitat[64];

    int number_of_skills;
    char** skills;

    int lvl;


public:

    Villain();
    explicit Villain(std::ifstream& in);
    Villain(const Villain& copy);
    ~Villain();

    void show() override;
    void edit() override;
    void save(std::ofstream& out) override;
    const char* getName() override;
    int getLvl() override;


};


#endif //VILLAIN_H
