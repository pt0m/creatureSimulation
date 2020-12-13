#ifndef MEDIUM_H
#define MEDIUM_H

#include "UImg.h"
#include "Factory.h"
#include "Config.h"

#include <memory>
#include <list>

using namespace std;

class Medium : public UImg {

 private :
  static const T white[];
  int width, height;
  list<ICreature *> list_creatures;
  Factory creature_factory;
  int max_birth;
  float proba_clone;

 public :
  Medium(int _width, int _height);

  ~Medium(void);

  void add_creature(const ICreature &c);

  void collide(ICreature &c1, ICreature &c2);

  unique_ptr<list<ICreature *>> get_creatures_list();

  int get_height(void) const;

  int get_width(void) const;

  void kill_creature(ICreature &c);

  unique_ptr<list<ICreature *>> list_neighbours(const ICreature &c) const;

  int nb_neighbours(const ICreature &c) const;

  void step(void);
};

#endif // MEDIUM_H
