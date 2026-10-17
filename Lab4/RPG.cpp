#include "RPG.h"
#include <cstdio>


RPG::RPG()
{
    name = "NPC";
    hits_taken = 0;
    luck = 0.1;
    exp = 0.0;
    level = 1;
}

RPG::RPG(string name, int hits_taken, float luck, float exp, int level)
{
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}


bool RPG::isAlive() const
{
    return hits_taken < 3;
}

string RPG::getName() const
{
    return name;
}

int RPG::getHitsTaken() const
{
    return hits_taken;
}


float RPG::getLuck() const
{
    return luck;
}

float RPG::getExp() const
{
    return exp;
}


int RPG::getLevel() const
{
    return level;
}

void RPG::setHitsTaken(int new_hits)
{
    hits_taken = new_hits;
}

void RPG::setName(string name)
{
    this->name = name;
}


void RPG::updateExpLevel()
{
    exp += 50;

    if (exp >= 100)
    {
        level = level + 1;
        exp = 0;
        luck += 0.1;
    }
}

void RPG::attack(RPG* opponent)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    float random_num = dis(gen);

    bool hit = false;

    if (random_num > HIT_FACTOR * (*opponent).getLuck())
    {
        hit = true;
    }

    if (hit)
    {
        (*opponent).setHitsTaken(
            (*opponent).getHitsTaken() + 1
        );
    }
}

void RPG::printStats()
{
    printf("Name: %-8s Hits Taken: %d  Luck: %.6f  Exp: %.6f  Level: %d  Status: %s\n",
           name.c_str(),
           hits_taken,
           luck,
           exp,
           level,
           isAlive() ? "Alive" : "Dead");
}
RPG::~RPG()
{
}

