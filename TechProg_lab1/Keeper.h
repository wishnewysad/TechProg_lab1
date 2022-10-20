#ifndef KEEPER_H
#define KEEPER_H

#include <iostream>
#include "villain.h"
#include "hero.h"
#include "monster.h"
#include "get_int.h"
#include <windows.h>

class Keeper {
private:
    Character** characters;
    unsigned int number_of_characters;

public:
    Keeper();
    ~Keeper();

    void addCharacter();//+
    void removeCharacter();//+
    void showCharacters();//+
    void editInformation();//+
    void save();//+
    void download();//+

    void duel(); // 

private:

    void clear();
    int selectCharacter();//+
    Character* createCharacter();//+
    Character** appendToArray(Character* new_character);//+
    Character** deleteFromArray(int choice);//+

    bool getResulOfDuel(Character* first_fighter, Character* second_fighter);

};


#endif //KEEPER_H
