#pragma once
#include <Dice.h>

double expected_value(AbstractDice &d, unsigned number_of_rolls = 1);

double value_probability(unsigned value, AbstractDice &d, unsigned number_of_rolls = 1);