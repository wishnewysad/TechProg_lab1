#include <iostream>
#include "get_int.h"
#include "Keeper.h"

void tryDownload(Keeper& keeper) {
    std::cout << "Do you want to download data from file?\n" <<
        "1. Yes\n" <<
        "2. No" << std::endl;
    int choice = getInt();

    if (choice == 1) {
        try {
            keeper.download();
        }
        catch (const char* msg) {
            std::cout << msg << std::endl;
        }
    }

}

void tryAdd(Keeper& keeper) {
    try {
        keeper.addCharacter();
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void tryDelete(Keeper& keeper) {
    try {
        keeper.removeCharacter();
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void tryShow(Keeper& keeper) {
    try {
        keeper.showCharacters();
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void trySave(Keeper& keeper) {
    try {
        keeper.save();
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void tryEdit(Keeper& keeper) {
    try {
        keeper.editInformation();
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void tryDuel(Keeper& keeper) {
    try {
        keeper.duel();
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void mainLoop() {
    Keeper keeper;
    bool work = true;
    tryDownload(keeper);
    int choice;

    do {
        std::cout << "Select action:\n" <<
            "1. Add character\n" <<
            "2. Delete character\n" <<
            "3. Edit information\n" <<
            "4. Show all characters\n" <<
            "5. Save to file\n" <<
            "6. Load save\n" <<
            "7. Duel\n" <<
            "8. Exit" << std::endl;

        choice = getInt();

        switch (choice)
        {
        case 1:
            tryAdd(keeper);
            break;
        case 2:
            tryDelete(keeper);
            break;
        case 3:
            tryEdit(keeper);
            break;
        case 4:
            tryShow(keeper);
            break;
        case 5:
            trySave(keeper);
            break;
        case 6:
            tryDownload(keeper);
            break;
        case 7:
            tryDuel(keeper);
            break;
        default:
            work = false;
            break;
        }

    } while (work);
}

int main() {
    srand(time(NULL));
    mainLoop();
    return 0;
}