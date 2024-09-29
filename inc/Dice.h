#pragma once
#include <random>

class AbstractDice {
public:
    virtual unsigned roll() = 0;
    virtual ~AbstractDice() = default; //чисто виртуальный деструктор
};

class Dice : public AbstractDice{
public:
    Dice(unsigned max, unsigned seed);
    unsigned roll() override;

private:
    unsigned max;
    std::uniform_int_distribution<unsigned> dstr;
    std::default_random_engine reng;
};

class ThreeDicePool : public AbstractDice {
public:
    ThreeDicePool(AbstractDice &d1, AbstractDice &d2, AbstractDice &d3);
    unsigned roll() override;

private:
    AbstractDice &d1, &d2, &d3;
};

class PenaltyDice : public virtual AbstractDice {
public: 
    PenaltyDice(AbstractDice &d);
    unsigned roll() override;

private:
    AbstractDice &d;
};

class BonusDice : public virtual AbstractDice {
public: 
    BonusDice(AbstractDice &d);
    unsigned roll() override;
    
private:
    AbstractDice &d;
};

class DoubleDice : public BonusDice, PenaltyDice {
public:
    DoubleDice(AbstractDice &d);
    unsigned roll() override;
};

/* реализация без множественного наследования
class DoubleDice : public AbstractDice {
public:
    DoubleDice(AbstractDice &d);
    unsigned roll() override;

private:
    AbstractDice $d;
};
*/