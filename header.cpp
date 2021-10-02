#include "header.h"
#include <iostream>
#include <string>
#include <time.h>
Pokemon::Pokemon(int hp, float attack, int speed, float defense, std::string name)
{
    this->stats.hp = hp;
    this->stats.attack = attack;
    this->stats.speed = speed;
    this->stats.defense = defense;
    this->stats.name = name;
}


void Pokemon::setmovestats(float x, float y, float z, float t, std::string a, std::string b, std::string c, std::string d)
{
    moves.move1 = x;
    moves.move2 = y;
    moves.move3 = z;
    moves.move4 = t;
    moves.name1 = a;
    moves.name2 = b;
    moves.name3 = c;
    moves.name4 = d;
}

Moveset Pokemon::getmovestats()
{
    return moves;
}

features Pokemon::getstats()
{
    return stats;
}

int choosemove(Pokemon team)
{
    while(true)
    {
        int choice;
        std::cout << "choose the move by entering corresponding no.\n";
        std::cout << "1." << team.getmovestats().name1 << "\n"<< "2." << team.getmovestats().name2 << "\n"; 
        std::cout << "3." << team.getmovestats().name3 << "\n"<< "4." << team.getmovestats().name4 << "\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            return team.getmovestats().move1;
            break;
        case 2:
            return team.getmovestats().move2;
            break;
        case 3:
            return team.getmovestats().move3;
            break;
        case 4:
            return team.getmovestats().move4;
            break;
        default:
            std::cout << "wrong response!";
        }
    }
    
}

int enemymove(Pokemon enemy)
{
    srand ( time(NULL) );
    int moveno = rand() % 4; //generates a random number between 0 and 2
    switch (moveno)
        {
        case 0:
            return enemy.getmovestats().move1;
            break;
        case 1:
            return enemy.getmovestats().move2;
            break;
        case 2:
            return enemy.getmovestats().move3;
            break;
        case 3:
            return enemy.getmovestats().move4;
            break;
        default:
            std::cout << "wrong response!";
        }

}

void declare(int victory)
{
    if (victory == 1 )
    {
        std::cout << "you win! ^_^" << std::endl;
    }

    else std::cout << "you lose! :( \n";
}

void battlepokemon(Pokemon team, Pokemon enemy)
{
    int victory;
    std::cout << "you sent: " << team.getstats().name << "\n";
    std::cout << "enemy sent: " << enemy.getstats().name << "\n";

    float health = team.getstats().hp;
    float enemyhealth = enemy.getstats().hp;

    std::cout << team.getstats().name << " Health: " << health << "\t";
    std::cout << enemy.getstats().name << "Health: " << enemyhealth << std::endl;
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;

    while(health > 0 && enemyhealth > 0)
    {
        float damage = choosemove(team);
        float enemydamage = enemymove(enemy);
        if (team.getstats().speed >= enemy.getstats().speed)
        {
            std::cout << "TEAM " << team.getstats().name << " attacked!\n";
            enemyhealth = enemyhealth - (damage * team.getstats().attack * enemy.getstats().defense);
            std::cout << team.getstats().name << " Health: " << health << "\t";
            std::cout << enemy.getstats().name << " Health: " << enemyhealth << "\n";

            std::cout << "ENEMY " << enemy.getstats().name << " attacked!\n";
            health = health - (enemydamage * enemy.getstats().attack * team.getstats().defense );
            std::cout << team.getstats().name << " Health: " << health << "\t";
            std::cout << enemy.getstats().name << " Health: " << enemyhealth << "\n";
            std::cout << "------------------------------------------" << std::endl;


            if (enemyhealth <= 0)
            {
                std::cout << enemy.getstats().name << "fainted!";
                victory = 1;
                break;
            }
            else if (health <= 0)
            {
                std::cout << team.getstats().name << "fainted!";
                victory = 0;
                break;
            }
        }
        else 
        {
            std::cout << "ENEMY" << enemy.getstats().name << " attacked First!\n";
            health = health - (enemydamage * enemy.getstats().attack * team.getstats().defense );
            std::cout << team.getstats().name << " Health: " << health << "\t";
            std::cout << enemy.getstats().name << " Health: " << enemyhealth << "\n";


            std::cout << "TEAM" << team.getstats().name << " attacked!\n";
            enemyhealth = enemyhealth - (damage * team.getstats().attack * enemy.getstats().defense);
            std::cout << team.getstats().name << " Health: " << health << "\t";
            std::cout << enemy.getstats().name << " Health: " << enemyhealth << "\n";
            std::cout << "------------------------------------------" << std::endl;
            if (health <= 0)
            {
                std::cout << team.getstats().name << "fainted!";
                victory = 0;
                break;
            }
            else if (enemyhealth <= 0)
            {
                std::cout << enemy.getstats().name << "fainted!";
                victory = 1;
                break;
            }
            
        }
        //enemymove()
    }
    
    declare(victory);
    std::cout << team.getstats().name << " Health: " << health << "\t";
    std::cout << enemy.getstats().name << " Health: " << enemyhealth << "\t";
    

}

