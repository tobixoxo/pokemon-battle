#pragma once
#include <string>
int choosepokemon();
int choosemove(class team);
void declare(int victory);
void battlepokemon(class Pokemon, class Pokemon);


struct Moveset
{
    float move1, move2, move3, move4;
    std::string name1, name2, name3, name4;                                       //move damages range from 0-10
};

struct features
{
    std::string name;
    int hp,  speed;
    float attack, defense;

};

class Pokemon
{
    features stats;
    Moveset moves ;                                                    //max hp for level 1 = 35
    public:                                                     // attack parameter will effect the damage of move
    Pokemon (int hp, float attack, int speed, float defense, std::string name);   // speed is on a level of 1-10
    void setmovestats(float x, float y, float z, float t,  std::string name1, std::string name2, std::string name3, std::string name4) ; 
    features getstats();
    Moveset getmovestats();
};

