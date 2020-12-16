#ifndef MEDIUM_H
#define MEDIUM_H

#include "ICreature.h"
#include "UImg.h"
#include "Factory.h"

#include <memory>       // std::unique_ptr
#include <list>

class ICreature;
class Factory;

class Medium : public UImg {

 private :
  static const T white[];
  int width, height;
  std::list<ICreature *> list_creatures;
  Factory* creature_factory;
  int max_birth;
  float proba_clone;

 public :
  Medium(int width, int height);

  ~Medium(void);

  void add_creature(const ICreature &c);

  void collide(ICreature &c1, ICreature &c2);

  std::unique_ptr<std::list<ICreature *>> get_creatures_list();

  int get_height(void) const;

  int get_width(void) const;

  void kill_creature(ICreature &c);

  std::unique_ptr<std::list<ICreature *>> list_neighbours(const ICreature &c) const;

  int nb_neighbours(const ICreature &c) const;

  void step(void);
};

#endif // MEDIUM_H
