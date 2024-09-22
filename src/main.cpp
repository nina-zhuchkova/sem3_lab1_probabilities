#include<Dice.h>
#include<expected_value.h>

unsigned SEED = 42;
unsigned number_of_rolls = 1e8;

#include <iostream>
int main() {
    Dice d(6, SEED);
    ThreeDicePool tdp(d, d, d);
    std::cout << "матожидание кубика: " << expected_value(d, number_of_rolls) << '\n';
    std::cout << "матожидание трех кубиков: " << expected_value(tdp, number_of_rolls) << '\n';
    return 0;
}