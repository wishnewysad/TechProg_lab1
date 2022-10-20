

#include "Keeper.h"

Keeper::Keeper() {
    characters = nullptr;
    number_of_characters = 0;
}

Keeper::~Keeper() {
    for (size_t i = 0; i < number_of_characters; i++) {
        delete characters[i];
    }
    delete[] characters;
}

void Keeper::addCharacter() {
    //выбрать тип персонажа и создать его
    //добавить этого персондажа в общий список персонажей
    Character* new_character = createCharacter();

    characters = appendToArray(new_character);
}

void Keeper::removeCharacter() {
    //вывести список персонажей
    //выбрать персонажа
    //удалить персонажа из общего списка персонажей
    if (number_of_characters == 0) throw "There are no characters";

    int choice = selectCharacter();

    characters = deleteFromArray(choice);
}

void Keeper::showCharacters() {
    //вывести всех персонажей
    if (number_of_characters == 0) throw "There are no characters";

    for (size_t i = 0; i < number_of_characters; ++i) {
        std::cout << i + 1 << "." << std::endl;
        characters[i]->show();
    }
}

void Keeper::editInformation() {
    //вывести всех персонажей
    //выбрать персонажа
    //изменить данные у конкретного персонажа
    if (number_of_characters == 0) throw "There are no characters";

    int choice = selectCharacter();

    characters[choice - 1]->edit();
}

void Keeper::save() {
    //сохранить всех персонажей в файл
    std::ofstream out("characters.txt");
    if (!out.is_open())
        throw "The file does not open";

    out << number_of_characters << std::endl;

    for (size_t i = 0; i < number_of_characters; i++) {
        characters[i]->save(out);
    }

    std::cout << "Data saved\n" << std::endl;
}

void Keeper::download() {
    if (characters != nullptr) 
        clear();

    std::ifstream in("characters.txt");
    if (!in.is_open())
        throw "File does not exist";
    int how_many_characters;
    in >> how_many_characters;
    int type;
    for (size_t i = 0; i < how_many_characters; i++) {
        in >> type;
        Character* new_character = nullptr;
        switch (type)
        {
        case HERO:
            new_character = new Hero(in);
            break;

        case VILLAIN:
            new_character = new Villain(in);
            break;

        case MONSTER:
            new_character = new Monster(in);
            break;
        }
        characters = appendToArray(new_character);
    }
    std::cout << "Successful download\n" << std::endl;
}

void Keeper::duel() {
    int first_fighter, second_fighter;

    std::cout << "Select first fighter" << std::endl;
    first_fighter = selectCharacter();

    std::cout << "Select second fighter" << std::endl;
    second_fighter = selectCharacter();

    
    std::cout << characters[first_fighter - 1]->getName() << " takes the initiative " << std::endl;
    Sleep(2000);
    std::cout << characters[second_fighter - 1]->getName() << " skillfully parries " << std::endl;
    Sleep(2000);
    std::cout << characters[first_fighter - 1]->getName() << " keeps the pressure " << std::endl;
    Sleep(2000);
    std::cout << characters[second_fighter - 1]->getName() << " counterattacks " << std::endl;
    Sleep(2000);

    std::cout << characters[first_fighter - 1]->getName() <<
                " and " << 
                characters[second_fighter - 1]->getName() <<
                " preparing for their final attack, and..." << std::endl;

    Sleep(4000);
    std::cout << "Result" << std::endl;

    if (getResulOfDuel(characters[first_fighter-1], characters[second_fighter - 1])) {
        std::cout << characters[second_fighter - 1]->getName() << " is dead!" << std::endl;
        characters = deleteFromArray(second_fighter);
    }
    else {
        std::cout << characters[first_fighter - 1]->getName() << " is dead!" << std::endl;
        characters = deleteFromArray(first_fighter);
    }
    std::cout << "The duel is over" << std::endl;
}

bool Keeper::getResulOfDuel(Character* first_fighter, Character* second_fighter) {
    int lvl_diff = first_fighter->getLvl() - second_fighter->getLvl();
    if (lvl_diff > 10) {
        return true;
    }
    else if (lvl_diff < -10) {
        return false;
    }
    else {
        int chance = RAND_MAX/2 + RAND_MAX/20*lvl_diff;
        return chance > rand();
    }
}

void Keeper::clear() {
    for (size_t i = 0; i < number_of_characters; i++) {
        delete characters[i];
    }
    delete[] characters; 
    number_of_characters = 0;
}

int Keeper::selectCharacter() {
    int choice;
    showCharacters();
    std::cout << "Select character: ";
    choice = getInt();
    if (choice <= 0 || choice > number_of_characters) throw "Out of range";

    return choice;
}

Character* Keeper::createCharacter() {
    int choice;

    std::cout << "Select type of character: \n" <<
        "1. Hero\n" <<
        "2. Villain\n" <<
        "3. Monster" << std::endl;

    choice = getInt();

    if (choice <= 0 || choice >= 4) throw "There is no such character";

    Character* new_character = nullptr;

    switch (choice)
    {
    case HERO:
        new_character = new Hero();
        break;

    case VILLAIN:
        new_character = new Villain();
        break;

    case MONSTER:
        new_character = new Monster();
        break;
    }


    return new_character;
}

Character** Keeper::appendToArray(Character* new_character) {
    ++number_of_characters;
    Character** new_characters = new Character * [number_of_characters];

    if (number_of_characters == 1) {
        new_characters[0] = new_character;
    }
    else {
        for (size_t i = 0; i < number_of_characters - 1; i++) {
            new_characters[i] = characters[i];
        }

    }
    new_characters[number_of_characters - 1] = new_character;
    delete[] characters;

    return new_characters;
}

Character** Keeper::deleteFromArray(int choice) {
    --number_of_characters;
    Character** new_characters = new Character * [number_of_characters];
    for (size_t i = 0, j = 0; i < number_of_characters + 1; i++) {
        if (i == choice - 1) continue;
        new_characters[j++] = characters[i];
    }
    delete[] characters;
    return new_characters;
}

