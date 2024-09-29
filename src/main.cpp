#include<Dice.h>
#include <value_functions.h>
#include <limits.h>

unsigned SEED = 42;
unsigned number_of_rolls = 1e8;

#include <iostream>
#include <fstream>
int main() {

    // 1-st exercise
    Dice d1(6, SEED);
    ThreeDicePool tdp(d1, d1, d1);
    /*
    std::ofstream expected_values;
    expected_values.open("files/expected_values.txt");
    if (expected_values.is_open()) {
        std::cout << "expected_values is open\n";
    } else {
        std::cout << "expected_values is NOT open\n";
        exit(1);
    }

    expected_values << "Six-sided dice expected value: " << expected_value(d1, number_of_rolls) << '\n';
    expected_values << "Three six-sided dices expected value: " << expected_value(tdp, number_of_rolls) << '\n';
    expected_values.close();
    */

    // 2-nd exercise
    int n = 100;
    Dice d2(n, SEED);
    BonusDice bd(d2);
    PenaltyDice pd(d2);

    std::ofstream bonus, penalty, ordinary, three;

    bonus.open("files/BonusDice_probability.csv");
    penalty.open("files/PenaltyDice_probability.csv");
    ordinary.open("files/Dice_probability.csv");
    //three.open("files/ThreeDicePool_probability.csv");


    if (bonus.is_open()){
        std::cout << "bonus is open\n";
    } else {
        std::cout << "bonus is NOT open\n";
        exit(1);
    }

    if (penalty.is_open()){
        std::cout << "penalty is open\n";
    } else {
        std::cout << "penalty is NOT open\n";
        exit(1);
    }

    if (ordinary.is_open()){
        std::cout << "ordinary is open\n";
    } else {
        std::cout << "ordinary is NOT open\n";
        exit(1);
    }

    /*
    if (three.is_open()){
        std::cout << "three is open\n";
    } else {
        std::cout << "three is NOT open\n";
        exit(1);
    }*/

    bonus << "Value, Probability" << '\n';
    penalty << "Value, Probability" << '\n';
    ordinary << "Value, Probability" << '\n';
    //three << "Value, Probability" << '\n';

    for (unsigned i = 1; i <= 1; ++i) {
        bonus << i << ", " << value_probability(i, bd, number_of_rolls) << '\n'; 
        penalty << i << ", " << value_probability(i, pd, number_of_rolls) << '\n'; 
        ordinary << i << ", " << value_probability(i, d2, number_of_rolls) << '\n'; 
    }

    bonus.close();
    penalty.close();
    ordinary.close();

    /*
    for (unsigned i = 1; i <= 6 * 3; ++i) {
        three << i << ", " << value_probability(i, tdp, number_of_rolls) << '\n'; 
    }

    three.close();
    */
    

    // 3-rd exercise
    DoubleDice dd(d2);
    std::ofstream double_dice;
    double_dice.open("files/DoubleDice_probability.csv");

    if (double_dice.is_open()){
        std::cout << "double_dice is open\n";
    } else {
        std::cout << "double_dice is NOT open\n";
        exit(1);
    }

    double_dice << "Value, Probability" << '\n';
    for (unsigned i = 1; i <= 1; ++i) {
        double_dice << i << ", " << value_probability(i, dd, number_of_rolls) << '\n'; 
    }
    double_dice.close();
    return 0;
}