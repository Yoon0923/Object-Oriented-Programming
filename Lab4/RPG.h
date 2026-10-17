
#ifndef RPG_H
#define RPG_H

#include <iostream>
#include <string>
#include <random>

using namespace std;

#define HIT_FACTOR 0.5

class RPG
{
private:
    string name;
    int hits_taken;
    float luck;
    float exp;
    int level;

public:
   
    RPG();
    RPG(string name, int hits_taken, float luck, float exp, int level);

    bool isAlive() const;
    string getName() const;
    int getHitsTaken() const;
    float getLuck() const;
    float getExp() const;
    int getLevel() const;

    void setHitsTaken(int new_hits);
    void setName(string name);

    void updateExpLevel();
    void attack(RPG* opponent);
    void printStats();

    ~RPG();
};

#endif

