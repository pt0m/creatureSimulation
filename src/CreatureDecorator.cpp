#include "CreatureDecorator.h"
#include <iostream>

CreatureDecorator::CreatureDecorator(ICreature *c) : decoree(c) {};

// Default implementations of methods that can be decorated

const bool CreatureDecorator::is_detected(const ICreature *c) {
    return decoree->is_detected(*c);
};

const double CreatureDecorator::get_camouflage() {
    std::cout << "This is the base camouflage" << std::endl;
    return decoree->get_camouflage();
};

const double CreatureDecorator::get_speed() {
    return decoree->get_speed();
};

const bool CreatureDecorator::is_collision_deadly() {
    return decoree->is_collision_deadly();
};

