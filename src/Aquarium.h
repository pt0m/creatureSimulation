#ifndef AQUARIUM_H
#define AQUARIUM_H

#include <iostream>
#include <CImg.h>
#include <list>

using namespace std;
using namespace cimg_library;

class Medium;

class Aquarium : public CImgDisplay {

 private :
  Medium *aqua;

  int delay;

  void user_interaction(unsigned char key);

 public :
  Aquarium();
  ~Aquarium(void);

  Medium &getMedium(void) { return *aqua; }

  void run(void);

};

#endif
