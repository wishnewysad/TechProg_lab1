#ifndef MONSTER_H
#define MONSTER_H

#include "character.h"
#include "get_int.h"
#include <fstream>
#include <cstring>
#include <time.h>
#include <random>
#include <stdlib.h>

class Monster : public Character {
private:
    char name[64];
    char appearance[64];

    int lvl;

public:

    Monster();
    explicit Monster(std::ifstream& in);
    Monster(const Monster& copy);
    ~Monster() = default;

    void show() override;
    void edit() override;
    void save(std::ofstream& out) override;
    const char* getName() override;
    int getLvl() override;


};


#endif //MONSTER_H
