
#include "get_int.h"

int getInt() {
    int my_int;
    std::cin >> my_int;
    while (std::cin.fail() || std::cin.get() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.sync();
        std::cin >> my_int;
    }
    return my_int;
}