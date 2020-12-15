#include "Medium.h"
#include "Config.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
const T    Medium::white[] = {(T) 255, (T) 255, (T) 255};

Medium::Medium(int width, int height) : UImg(width, height, 1, 3),
                                        width(width), height(height) {
  Config *config_singleton = Config::get_instance();
  max_birth = config_singleton->get_config_int("max_birth");
  proba_clone = config_singleton->get_config_float("proba_clone");
  cout << "const Medium" << endl;
  std::srand(time(NULL));
}

Medium::~Medium(void) {
  cout << "dest Medium" << endl;
}

void Medium::add_creature(const ICreature &c) {

  //TODO
//  c-> list_creatures.insert(0, c);
//  list_creatures.back().initCoords(width, height);
}

void Medium::collide(ICreature &c1, ICreature &c2) {
  // TODO
}
int Medium::get_height(void) const { return height; };

int Medium::get_width(void) const { return width; };

void Medium::kill_creature(ICreature &c) {
  cout << "kill creature" << endl;
}

int Medium::nb_neighbours(const ICreature &c) const {
  int nb = 0;
  // TODO : code for list of Creatures
//    for (std::vector<Creature>::iterator it = listCreatures.begin();
//         it != listCreatures.end(); ++it)
//        if (!(c == *it) && c.is_detected(*it))
//            ++nb;
  return nb;
}

std::unique_ptr<std::list<ICreature *>> Medium::list_neighbours(const ICreature &c) const {
  // TODO : code for the list of the detected creatures
  return NULL;

};

void Medium::step(void) {
//  cimg_forXY(*this, x, y)
//  fillC(x, y, 0, white[0], white[1], white[2]);
  // TODO : go through the list
  cout << "step medium" << endl;

//  for (std::vector<Creature>::iterator it = list_creatures.begin();
//       it != list_creatures.end(); ++it) {
//    it->action(*this);
//    it->draw(*this);
//  } // for
};
std::unique_ptr<std::list<ICreature *>> Medium::get_creatures_list() {
  return NULL;
}
