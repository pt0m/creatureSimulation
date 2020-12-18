#include "Aquarium.h"

#include <iostream>

int main(){

   Aquarium deco1("camouflage.conf");
   deco1.run();
   Aquarium deco2("ears.conf");
   deco2.run();
   Aquarium deco3("eyes.conf");
   deco3.run();
   Aquarium deco4("fin.conf");
   deco4.run();
   Aquarium deco5("shell.conf");
   deco5.run();

   Aquarium behav1("farsighted.conf");
   behav1.run();
   Aquarium behav2("fearful.conf");
   behav2.run();
   Aquarium behav3("gregarious.conf");
   behav3.run();
   Aquarium behav4("kamikaze.conf");
   behav4.run();
   Aquarium behav5("schizophrenics.conf");
   behav5.run();

   Aquarium clonage("clonage.conf");
   clonage.run();

   return 0;
}
