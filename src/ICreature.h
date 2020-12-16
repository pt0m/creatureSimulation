#ifndef ICREATURE_H
#define ICREATURE_H

#include "Medium.h"
#include "UImg.h"

// Mutual inclusion
class Medium;

class ICreature {
  // Define operations that can be altered by decorators
 public:
  ~ICreature() = default;

  virtual void action(Medium &myMedium) = 0;

  virtual void draw(UImg &support) const = 0;

  virtual float get_camouflage() const = 0;

  virtual int get_lifetime() const = 0;

  virtual float get_size() const = 0;

  virtual float get_speed() const = 0;

  virtual int get_x() const = 0;

  virtual int get_y() const = 0;

  virtual float get_vx() const = 0;

  virtual float get_vy() const = 0;

  virtual bool is_collision_deadly() const = 0;

  virtual bool is_detected(const ICreature &c) const = 0;

  virtual void set_coords(const int x, const int y) = 0;

  virtual void set_vx_vy(const int vx, const int vy) = 0;
};

#endif //ICREATURE_H
