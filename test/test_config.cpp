#include <iostream>
#include "../Config.hpp"

int test_config()
{
  std::cout << "test Class Conig ..." << '\n';

  // test that the signleton return is always the same instance
  Config* config_singleton = Config::get_instance();
  Config* config_singleton2 = Config::get_instance();
  // we compare the pointer
  if(config_singleton != config_singleton2){
    std::cout << "error : singleton instance returned should always be the same !" << '\n';
    return 1;
  }
  config_singleton->load_configuration("configuration.conf");
  int v1 = config_singleton->get_config_int("variable_name_1");
  if(v1 != 223){
    std::cout << "error: int value of 'varaible_name_1' is wrong" << '\n';
    return 1;
  }
  int v2 = config_singleton->get_config_float("variable_name_2");
  if(v2 != 3.14){
    std::cout << "error: float value of 'varaible_name_2' is wrong. given "<< v2 << "instead of 3.14"<<'\n';
    return 1;
  }
  return 0;
}


int main()
{
  return test_config();
}
