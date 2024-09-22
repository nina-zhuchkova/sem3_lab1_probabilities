#pragma once
#include <random>

class AbstractDice {
public:
    virtual unsigned roll();
    virtual ~AbstractDice() = 0; //виртуальный деструктор делает класс чисто виртуальным
};



class Dice : public AbstractDice{
public:
    Dice(unsigned max, unsigned seed);
    Dice();
    unsigned roll() override;

private:
    unsigned max;
    std::uniform_int_distribution<unsigned> dstr;
    std::default_random_engine reng;
};

class ThreeDicePool : public Dice {
public:
    ThreeDicePool(AbstractDice &d1, AbstractDice &d2, AbstractDice &d3);
    unsigned roll() override;

private:
    AbstractDice &d1, &d2, &d3;
};