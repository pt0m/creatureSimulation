#include "Medium.h"

#include <cstdlib>
#include <ctime>


const T    Medium::white[] = { (T)255, (T)255, (T)255 };


Medium::Medium( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Medium" << endl;

   std::srand( time(NULL) );

}


Medium::~Medium( void )
{

   cout << "dest Medium" << endl;

}


void Medium::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Creature>::iterator it = listCreatures.begin() ; it != listCreatures.end() ; ++it )
   {

      it->action( *this );
      it->draw( *this );

   } // for

}


int Medium::nbNeighbours( const Creature & b )
{

   int         nb = 0;


   for ( std::vector<Creature>::iterator it = listCreatures.begin() ; it != listCreatures.end() ; ++it )
      if ( !(b == *it) && b.iSeeYou(*it) )
         ++nb;

   return nb;

}
