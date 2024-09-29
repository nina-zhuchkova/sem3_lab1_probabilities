#include <random>

#include <Dice.h>

Dice::Dice(unsigned max, unsigned seed) : max(max), dstr(1, max), reng(seed) {}

unsigned Dice::roll() {return dstr(reng);}

ThreeDicePool::ThreeDicePool(AbstractDice &d1, AbstractDice &d2, AbstractDice &d3) : d1(d1), d2(d2), d3(d3) {}
unsigned ThreeDicePool::roll() {return d1.roll() + d2.roll() + d3.roll();}

PenaltyDice::PenaltyDice(AbstractDice &d) : d(d) {}
unsigned PenaltyDice::roll() {
    return std::min(d.roll(), d.roll());
}

BonusDice::BonusDice(AbstractDice &d) : d(d) {}
unsigned BonusDice::roll() {
    return std::max(d.roll(), d.roll());
}

DoubleDice::DoubleDice(AbstractDice &d) : BonusDice(d), PenaltyDice(d) {}
unsigned DoubleDice::roll() {
    return BonusDice::roll() + PenaltyDice::roll();
}

/*реализация без множественного наследования
DoubleDice::DoubleDice(AbstractDice &d) : AbstractDice(d) {}
unsigned DoubleDice::roll() {
    return std::max(d.roll(), d.roll()) + std::min(d.roll(), d.roll());
}
*/