#ifndef ICREATURE_H
#define ICREATURE_H

#include "Medium.h"
#include "UImg.h"

// Mutual inclusion
class Medium;

class ICreature {
  // Define operations that can be altered by decorators
 public:
  virtual ~ICreature() {};

  virtual void action(Medium &myMedium, ICreature* creature) = 0;

  virtual ICreature *clone() = 0;

  virtual void draw(UImg &support) const = 0;

  virtual float get_camouflage() const = 0;

  virtual int get_identity() const = 0;

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

  virtual void set_lifetime(const int new_lifetime) = 0;

  virtual void set_vx_vy(const float vx, const float vy) = 0;

  virtual void set_color(T* new_color) = 0;
};

#endif //ICREATURE_H
