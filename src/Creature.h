#ifndef CREATURE_H
#define CREATURE_H

#include "ICreature.h"
#include "IBehaviour.h"
#include "Medium.h"
#include "UImg.h"

class Creature : public ICreature {

 private:
  static uint NEXT_IDENTITY;

 private:
  unique_ptr<IBehaviour> behaviour;
  float camouflage;
  int identity;
  int lifetime;
  float orientation;
  float size;
  float speed;
  float vx;
  float vy;
  int x;
  int y;

  T *color;

 public:

  Creature(unique_ptr<IBehaviour> behaviour, T *color, int lifetime,
           float speed, float size, int x, int y);

  Creature(const Creature &c);

  ~Creature();

  void action(Medium &myMedium) override;

  void draw(UImg &support) const override;

  float get_camouflage() const override;

  int get_lifetime() const override;

  float get_speed() const override;

  int get_x() const override;

  int get_y() const override;

  float get_vx() const override;

  float get_vy() const override;

  bool is_collision_deadly() const override;

  bool is_detected(const ICreature &c) const override;

  void set_coords(const int x, const int y) override;

  void set_lifetime(const int new_val) override;

  void set_vx_vy(const int vx, const int vy) override;

};

#endif //CREATURE_H

