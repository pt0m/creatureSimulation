#ifndef _MEDIUM_H_
#define _MEDIUM_H_


#include "UImg.h"
#include "Creature.h"

#include <iostream>
#include <vector>

using namespace std;


class Medium : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<Creature>   listCreatures;

public :
   Medium( int _width, int _height );
   ~Medium( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( const Creature & b ) { listCreatures.push_back(b); listCreatures.back().initCoords(width, height); }
   int nbNeighbours( const Creature & b );

};


#endif
