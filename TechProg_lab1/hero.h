#ifndef HERO_H
#define HERO_H

#include "character.h"
#include <fstream>
#include <iostream>
#include "get_int.h"
#include <cstring>

class Hero : public Character {
private:
    char name[64];
    char weapon_type[64];

    int number_of_skills;
    char** skills;

    int lvl;

public:

    Hero();
    explicit Hero(std::ifstream& in);
    Hero(const Hero& copy);
    ~Hero();

    void show() override;
    void edit() override;
    void save(std::ofstream& out) override;
    const char* getName() override;
    int getLvl() override;

};


#endif //HERO_H
