
#include "villain.h"

Villain::Villain() {
    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "Enter type of weapon: ";
    std::cin >> weapon_type;

    std::cout << "Enter the crime: ";
    std::cin >> crime;

    std::cout << "Enter the habitat: ";
    std::cin >> habitat;

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

Villain::Villain(std::ifstream& in) {
    in >> name;
    in >> weapon_type;
    in >> crime;
    in >> habitat;
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

Villain::Villain(const Villain& copy) {
    strcpy_s(name, 64, copy.name);
    strcpy_s(weapon_type, 64, copy.weapon_type);
    strcpy_s(crime, 64, copy.crime);
    strcpy_s(habitat, 64, copy.habitat);
    lvl = copy.lvl;
    this->number_of_skills = copy.number_of_skills;
    for (int i = 0; i < this->number_of_skills; ++i) {
        strcpy_s(skills[i], 64, copy.skills[i]);
    }
}

Villain::~Villain() {
    for (int i = 0; i < number_of_skills; ++i) {
        delete[] skills[i];
    }
    delete[] skills;
}

void Villain::show() {
    std::cout << "Villain." << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Type of weapon: " << weapon_type << std::endl;
    std::cout << "Crime: " << crime << std::endl;
    std::cout << "Habitat: " << habitat << std::endl;
    std::cout << "Villian lvl: " << lvl << std::endl;
    std::cout << "Number of skills: " << number_of_skills << std::endl;
    std::cout << "Skills: " << std::endl;
    for (int i = 0; i < number_of_skills; ++i) {
        std::cout << i + 1 << ". " << skills[i] << std::endl;
    }
    std::cout << "\n";

}

void Villain::edit() {
    std::cout << "Select field: \n" <<
        "1. Name\n" <<
        "2. Type of weapon\n" <<
        "3. Crime\n" <<
        "4. Habitat\n" <<
        "5. Lvl\n" <<
        "6. Skill" << std::endl;

    int selection = getInt();

    if (selection <= 0 || selection >= 7) throw "There is no such field";

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
        std::cout << "New crime: ";
        std::cin >> crime;
        break;
    case 4:
        std::cout << "New habitat: ";
        std::cin >> habitat;
        break;
    case 5:
        std::cout << "New LvL: ";
        lvl = getInt();
        break;
    case 6:
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

void Villain::save(std::ofstream& out) {
    out << VILLAIN << std::endl;
    out << name << std::endl;
    out << weapon_type << std::endl;
    out << crime << std::endl;
    out << habitat << std::endl;
    out << lvl << std::endl;
    out << number_of_skills << std::endl;
    for (size_t i = 0; i < number_of_skills; i++) {
        out << skills[i] << std::endl;
    }

}

const char* Villain::getName() {
    return name;
}

int Villain::getLvl() {
    return lvl;
}

