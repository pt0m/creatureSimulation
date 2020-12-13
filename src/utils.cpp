#include <cstdlib>      // std::rand()

#include "utils.h"


float rand_range(float inf, float sup, int precision){
    return (std::rand()%precision)*(sup-inf)/precision+inf;
}
