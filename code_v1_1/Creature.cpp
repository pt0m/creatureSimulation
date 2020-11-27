#include "Creature.h"

#include "Medium.h"

#include <cstdlib>
#include <cmath>


const double      Creature::AFF_SIZE = 8.;
const double      Creature::MAX_SPEED = 10.;
const double      Creature::LIMIT_VIEW = 30.;

int               Creature::next = 0;


Creature::Creature( void )
{

   identity = ++next;

   cout << "const Creature (" << identity << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   speed = static_cast<double>( rand() )/RAND_MAX*MAX_SPEED;

   color = new T[ 3 ];
   color[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   color[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   color[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

}


Creature::Creature( const Creature & b )
{

   identity = ++next;

   cout << "const Creature (" << identity << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   speed = b.speed;
   color = new T[ 3 ];
   memcpy( color, b.color, 3*sizeof(T) );

}


Creature::~Creature( void )
{

   delete[] color;

   cout << "dest Creature" << endl;

}


void Creature::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Creature::move( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos( orientation )*speed;
   double         dy = -sin( orientation )*speed;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}


void Creature::action( Medium & myMedium )
{

   move( myMedium.getWidth(), myMedium.getHeight() );

}


void Creature::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., color );
   support.draw_circle( xt, yt, AFF_SIZE/2., color );

}


bool operator==( const Creature & b1, const Creature & b2 )
{

   return ( b1.identity == b2.identity );

}


bool Creature::iSeeYou( const Creature & b ) const
{

   double         dist;


   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMIT_VIEW);

}
