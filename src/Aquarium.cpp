#include "Aquarium.h"
#include "Medium.h"
#include "ICreature.h"
#include "Config.h"

Aquarium::Aquarium() : CImgDisplay() {
  Config *config_singleton = Config::get_instance();
  int screen_width = 1280; //screen_width();
  int screen_height = 1024; //screen_height();
  int width = config_singleton->get_config_int("width");
  int height = config_singleton->get_config_int("height");
  int delay = config_singleton->get_config_int("delay");

  std::cout << "const Aquarium" << std::endl;
  aqua = new Medium(width, height);

  // from CImg library
  assign(*aqua, "Simulation d'ecosysteme");
  move(static_cast<int>((screen_width - width) / 2), static_cast<int>((screen_height - height) / 2));

}

Aquarium::~Aquarium(void) {
  delete aqua;
  std::cout << "dest Aquarium" << std::endl;
}

void Aquarium::run(void) {
  std::cout << "running Aquarium" << std::endl;
  while (!is_closed()) {
    if (is_key()) {
      std::cout << "Vous avez presse la touche " << static_cast<unsigned char>( key());
      std::cout << " (" << key() << ")" << std::endl;
      this->user_interaction(static_cast<unsigned char>(key()));
      if (is_keyESC()) close();
    }
    aqua->step();
    display(*aqua);
    wait(delay);
  } // while
}

/**
 * define all the user interaction according to the key pressed
 *
 * @param key pressed, as an unsigned char
 * @return void
 */
void Aquarium::user_interaction(unsigned char key) {
  // TODO : reimplement function
  switch (key) {
    case 'l':
      std::cout << "l case" << std::endl;
//      std::list < ICreature > *aqua->get_list_creatures();
//      std::list<ICreature>::iterator it = aqua->end() //we remove and destroy the last element
//      std::list.erase(it);
      break;
    case 'f':
      std::cout << "f case" << std::endl;
//      std::list < ICreature > *aqua->get_list_creatures();
//      std::list<ICreature>::iterator it = aqua->begin() //we remove and destroy the first element
//      std::list.erase(it);
      break;
  }
}