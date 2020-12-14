#include <cstdlib>      // std::rand()

#include "utils.h"



/* The precision is the number of points between inf and sup. The returned
// value is one on these values. 
*/
float rand_range(float inf, float sup, int precision){
    return (std::rand()%precision)*(sup-inf)/precision+inf;
}
