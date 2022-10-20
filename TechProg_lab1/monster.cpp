#include "monster.h"

Monster::Monster() {
    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "Enter a description of the appearance: ";
    std::cin >> appearance;

    std::cout << "Enter monster lvl: ";
    lvl = getInt();
}

Monster::Monster(std::ifstream& in) {
    in >> name;
    in >> appearance;
    in >> lvl;
}

Monster::Monster(const Monster& copy) {
    strcpy_s(name, 64, copy.name);
    strcpy_s(appearance, 64, copy.appearance);
    lvl = copy.lvl;
}

void Monster::show() {
    std::cout << "Monster." << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Appearance: " << appearance << std::endl;
    std::cout << "Monster lvl: " << lvl << std::endl;
    std::cout << "\n";
}

void Monster::edit() {
    std::cout << "Select field: \n" <<
        "1. Name\n" <<
        "2. Appearance\n" << 
        "3. Lvl" << std::endl;

    int selection = getInt();

    if (selection <= 0 || selection >= 4) throw "There is no such field";

    switch (selection)
    {
    case 1:
        std::cout << "New name: ";
        std::cin >> name;
        break;
    case 2:
        std::cout << "New appearance: ";
        std::cin >> appearance;
        break;
    case 3:
        std::cout << "New LvL: ";
        lvl = getInt();
        break;
    }
}

void Monster::save(std::ofstream& out) {
    out << MONSTER << std::endl;
    out << name << std::endl;
    out << appearance << std::endl;
    out << lvl << std::endl;

}

const char* Monster::getName() {
    return name;
}

int Monster::getLvl() {
    return lvl;
}
