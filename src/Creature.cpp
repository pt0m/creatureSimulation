#include "Creature.h"
#include "Config.h"

#include <vector>
#include <cmath>
#include <iostream>
#include <cstdlib>

static long      Creature::NEXT_IDENTITY = 0;

Creature::Creature() {

    Config* config_singleton = Config::get_instance();
    
    // set the speed value
    int max_speed = config_singleton -> get_config_int("max_speed");
    int min_speed = config_singleton -> get_config_int("min_speed");
    this->speed = static_cast<double>(std::rand() % max_speed + min_speed);
    
    // set the size
    int max_size = config_singleton -> get_config_int("max_size");
    int min_size = config_singleton -> get_config_int("min_size");
    this->size = std::rand() % max_size + min_size;
    
    // set the first position
    int width = config_singleton -> get_config_int("width");
    int height = config_singleton -> get_config_int("height");
    this->x = rand() % width;
    this->y = rand() % height;
    
    //set the orientation
    this->orientation = 2*3.14/(std::rand() % 360);
    
    //set the lifetime
    int max_lifetime = config_singleton -> get_config_int("max_lifetime");
    int min_lifetime = config_singleton -> get_config_int("min_lifetime");
    this->lifetime = std::rand() % min_lifetime + max_lifetime;

    //set vx and vy
    this->vx = static_cast<int>((this->speed)*cos(this->orientation));
    this->vy = static_cast<int>((this->speed)*sin(this->orientation));

    //set the camouflage
    int max_camouflage = config_singleton->get_config_int("max_camouflage");
    this->camouflage = (std::rand()%max_camouflage)/100;

    //set identity
    this->identity = Creature::NEXT_IDENTITY;
    Creature::NEXT_IDENTITY = Creature::NEXT_IDENTITY + 1;

    // set the color
    color = new T[ 3 ];
   color[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   color[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   color[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

}

Creature::Creature(const Creature &c) {
    this->camouflage = c.camouflage;
    this->lifetime = c.lifetime;
    this->size = c.size;
    this->speed = c.speed;
    this->vx = c.vx;
    this->vy = c.vy;
    this->x = c.x;
    this->y = c.y;
    this->identity = Creature::NEXT_IDENTITY;
    Creature::NEXT_IDENTITY = Creature::NEXT_IDENTITY + 1;
}

void Creature::action(const Medium &myMedium) {
    std::cout << "Empty implementation";
    this->lifetime = this->lifetime - 1;
}

void Creature::draw(UImg &support) {

    double         xt = x + cos( orientation )*this->size/2.1;
    double         yt = y - sin( orientation )*this->size/2.1;


    support.draw_ellipse( x, y, this->size, his->size/5., -orientation/M_PI*180., color );
    support.draw_circle( xt, yt, this->size/2., color );
}


const float Creature::get_camouflage() { return camouflage; }

const int Creature::get_lifetime() { return lifetime; }

const int Creature::get_speed() { return speed; }

const int Creature::get_x() { return x; }

const int Creature::get_y() { return y; }

const int Creature::get_vx() { return vx; }

const int Creature::get_vy() { return vy; }



const bool Creature::is_collision_deadly() { return true; }

const bool Creature::is_detected(const ICreature &) { return false; }

void Creature::set_camouflage(const float new_val) { this->camouflage = new_val; }

void Creature::set_coords(const int x, const int y) {
    this->x = x;
    this->y = y;
}

void const Creature::st_vx_vy(int new_vx, int new_vy) {
    this->vx = new_vx;
    this->vy = new_vy;_

}

void Creature::set_lifetime(const int new_val) { this->lifetime = new_val; }

void Creature::set_speed(const int new_val) { this->speed = new_val; }

void Creature::~Creature() {};

