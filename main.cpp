#include "FromString.h"
#include <cmath>

int main() {

    std::string str = "-2147483649";
    std::cout << FromString<int>(str);
    return 0;
}