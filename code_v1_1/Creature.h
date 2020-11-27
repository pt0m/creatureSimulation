#ifndef _CREATURE_H_
#define _CREATURE_H_


#include "UImg.h"

#include <iostream>

using namespace std;


class Medium;


class Creature
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_SPEED;
   static const double     LIMIT_VIEW;

   static int              next;

private :
   int               identity;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            speed;

   T               * color;

private :
   void move( int xLim, int yLim );

public :                                           // Forme canonique :
   Creature( void );                               // Constructeur par defaut
   Creature( const Creature & b );                 // Constructeur de copies
   ~Creature( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Medium & myMedium );
   void draw( UImg & support );

   bool iSeeYou( const Creature & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Creature & b1, const Creature & b2 );

};


#endif
