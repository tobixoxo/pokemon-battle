#include <iostream>
#include "header.h"
#include <iostream>
#include <string>


int main()
{
    Pokemon charmander(29,0.81,8, 0.91, "Charmander");
    charmander.setmovestats(7.3, 6.7, 7.9, 8.0,"ember","tackle","fireDance", "heatblast");
    Pokemon pikachu(27, 0.85, 9,0.95, "Pikachu");
    pikachu.setmovestats(7.5, 6.2, 8.3, 7.5,"thunder","quickattack","electricBeam","shockwave");

    //choosepokemon();
    battlepokemon(charmander, pikachu);
    return 0;
}