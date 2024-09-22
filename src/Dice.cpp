#include <random>

#include <Dice.h>

unsigned AbstractDice::roll() {return 0;}
AbstractDice::~AbstractDice() {};

Dice::Dice(unsigned max, unsigned seed) : max(max), dstr(1, max), reng(seed) {}
Dice::Dice() : Dice(1, 42) {}

unsigned Dice::roll() {return dstr(reng);}

ThreeDicePool::ThreeDicePool(AbstractDice &d1, AbstractDice &d2, AbstractDice &d3) : d1(d1), d2(d2), d3(d3) {}
unsigned ThreeDicePool::roll() {return d1.roll() + d2.roll() + d3.roll();}

