#ifndef MEDIUM_H
#define MEDIUM_H

#include "UImg.h"
#include "Factory.h"
#include "Config.h"

class Medium : public UImg {

 private :
  static const T white[];
  int width, height;
  List<ICreature> listCreatures;
  Factory creatureFactory;
  int max_birth;
  float proba_clone;

 public :
  Medium(int _width, int _height);

  ~Medium(void);

  void addCreature(const ICreature &c);

  void collide(ICreature &c1, ICreature &c2);

  int getHeight(void) const;

  int getWidth(void) const;

  void killCreature(ICreature &c);

  std::unique_ptr<List<ICreature>> listNeighbours(const ICreature &c) const;

  int nbNeighbours(const ICreature &c) const;

  void step(void);
};

#endif
