#include "Aquarium.h"
#include "Medium.h"
#include "Creature.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

   for ( int i = 1; i <= 20; ++i )
      ecosysteme.getMedium().addMember( Creature() );
   ecosysteme.run();


   return 0;

}
