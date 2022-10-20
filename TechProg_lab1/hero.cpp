
#include "hero.h"

Hero::Hero() {
    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "Enter type of weapon: ";
    std::cin >> weapon_type;

    std::cout << "Enter hero lvl: ";
    lvl = getInt();

    std::cout << "How many skills does the hero have: ";
    number_of_skills = getInt();
    if (number_of_skills <= 0) throw "There are no heroes without skills";

    skills = new char* [number_of_skills];
    for (int i = 0; i < number_of_skills; ++i) {
        skills[i] = new char[64];
    }
    std::cout << "Skills: " << std::endl;
    for (int i = 0; i < number_of_skills; ++i) {
        std::cout << i + 1 << ". ";
        //std::cin.get(skills[i], 64);
        std::cin >> skills[i];
    }

}

Hero::Hero(std::ifstream& in) {
    in >> name;
    in >> weapon_type;
    in >> lvl;
    in >> number_of_skills;
    skills = new char* [number_of_skills];
    for (int i = 0; i < number_of_skills; ++i) {
        skills[i] = new char[64];
    }
    for (size_t i = 0; i < number_of_skills; i++) {
        in >> skills[i];
    }
}

Hero::Hero(const Hero& copy) {
    strcpy_s(name, 64, copy.name);
    strcpy_s(weapon_type, 64, copy.weapon_type);
    lvl = copy.lvl;

    this->number_of_skills = copy.number_of_skills;
    for (int i = 0; i < this->number_of_skills; ++i) {
        strcpy_s(skills[i], 64, copy.skills[i]);
    }
}

Hero::~Hero() {
    for (int i = 0; i < number_of_skills; ++i) {
        delete[] skills[i];
    }
    delete[] skills;
}

void Hero::show() {
    std::cout << "Hero." << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Type of weapon: " << weapon_type << std::endl;
    std::cout << "Hero lvl: " << lvl << std::endl;
    std::cout << "Number of skills: " << number_of_skills << std::endl;
    std::cout << "Skills: " << std::endl;
    for (int i = 0; i < number_of_skills; ++i) {
        std::cout << i + 1 << ". " << skills[i] << std::endl;
    }
    std::cout << "\n";
}

void Hero::edit() {
    std::cout << "Select field: \n" <<
        "1. Name\n" <<
        "2. Type of weapon\n" <<
        "3. Lvl\n" <<
        "4. Skill" << std::endl;

    int selection = getInt();

    if (selection <= 0 || selection >= 5) throw "There is no such field";

    switch (selection)
    {
    case 1:
        std::cout << "New name: ";
        std::cin >> name;
        break;
    case 2:
        std::cout << "New type of weapon: ";
        std::cin >> weapon_type;
        break;
    case 3:
        std::cout << "New LvL: ";
        lvl = getInt();
        break;
    case 4:
        int choice;
        std::cout << "1. Add new skill\n" <<
            "2. Delete skill\n" << 
            "3. Change curent skill" << std::endl;
        choice = getInt();
        if (choice <= 0 || choice >= 3) throw "Out of range";

        if (choice == 1) {
            ++number_of_skills;
            char** new_skills = new char* [number_of_skills];
            for (size_t i = 0; i < number_of_skills; i++) {
                new_skills[i] = new char[64];
;           }
            for (size_t i = 0; i < number_of_skills - 1; i++) {
                new_skills[i] = skills[i];
            }
            delete[] skills;
            std::cout << "New skill: ";
            std::cin >> new_skills[number_of_skills - 1];
            skills = new_skills;

            break;
        }
        if (choice == 2) {
            std::cout << "Select skill: " << std::endl;
            for (size_t i = 0; i < number_of_skills; i++) {
                std::cout << i + 1 << ". " << skills[i] << std::endl;
            }
            int selection = getInt();
            if (selection <= 0 || selection > number_of_skills) throw "There is no such skill";
            
            --number_of_skills;
            char** new_skills = new char* [number_of_skills];
            for (size_t i = 0; i < number_of_skills; i++) {
                new_skills[i] = new char[64];
            }
            for (size_t i = 0, j = 0; i < number_of_skills + 1; i++) {
                if (i == selection - 1) continue;
                new_skills[j++] = skills[i];
            }
            delete[] skills;
            skills = new_skills;

            break;
        }
        if (number_of_skills == 1) {
            std::cout << "New skill: ";
            std::cin >> skills[0];
        }
        else {
            std::cout << "Select skill: " << std::endl;
            for (size_t i = 0; i < number_of_skills; i++) {
                std::cout << i + 1 << ". " << skills[i] << std::endl;
            }
            int selection = getInt();
            if (selection <= 0 || selection > number_of_skills) throw "There is no such skill";

            std::cout << "New skill: ";
            std::cin >> skills[selection - 1];
        }

        break;
    }
}

void Hero::save(std::ofstream& out) {
    out << HERO << std::endl;
    out << name << std::endl;
    out << weapon_type << std::endl;
    out << lvl << std::endl;
    out << number_of_skills << std::endl;
    for (size_t i = 0; i < number_of_skills; i++) {
        out << skills[i] << std::endl;
    }
}

const char* Hero::getName() {
    return name;
}

int Hero::getLvl() {
    return lvl;
}
