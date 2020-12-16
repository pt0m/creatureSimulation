#include "Aquarium.h"

#include <iostream>

int main(){
   Aquarium aquarium("./src/configuration.conf");
   aquarium.run();

   return 0;
}
