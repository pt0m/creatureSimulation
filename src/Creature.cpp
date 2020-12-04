//
// Created by Ménard Luc on 04/12/2020.
//

#include "Creature.h"
#include "Medium.h"

#include <vector>
#include <cmath>

const double      Creature::AFF_SIZE = 8.;
const double      Creature::MAX_SPEED = 10.;
const double      Creature::LIMIT_VIEW = 30.;

Creature::Creature() {}

Creature::Creature(const Creature& c) {
    this->x = c.x;
    this->y = c.y;
    this->vx = c.vx;
    this->vy = c.vy;
    this->speed = c.speed;
    this->color = c.color;
    this->size = c.size;
    this->lifetime = c.lifetime;
    this->behaviour = c.behaviour;
    this->camouflage = c.camouflage;
}

Creature::~Creature(){}

Creature::action(const Medium& myMedium){
    this->behaviour.next_step(myMedium.list_Creature)
}

void Creature::draw( UImg & support )
{

    double xt = x + cos( orientation )*AFF_SIZE/2.1;
    double yt = y - sin( orientation )*AFF_SIZE/2.1;

    support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., color );
    support.draw_circle( xt, yt, AFF_SIZE/2., color );

}

const bool Creature::is_detected(const ICreature &) { return false }

const int Creature::get_x() { return x }

const int Creature::get_y() { return y }

const double Creature::get_vx() { return vx }

const int Creature::get_lifetime() { return lifetime }

const void Creature::get_speed() { return speed }

const double Creature::get_camouflage() { return camouflage }

void Creature::init_coords(const int x, const int y) {this->x = 0; this->y = 0}

void Creature::set_speed(const double new_val) {this->speed = new_val}

void Creature::set_camouflage(const int new_val) {this->camouflage = new_val}

int Creature::set_lifetime(const int new_val) {this->lifetime = new_val}

const bool Creature::is_collision_deadly() {return true}


