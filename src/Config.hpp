/*
Class Config

This class is ment to read the config file and provide the config as a singleton.

T.P
*/

#ifndef CONFIG
#define CONFIG

#include <string>
#include <vector>


class Config
{
  public:
    static Config* get_instance();
    std::string get_config_string(std::string variable_name);
    float get_config_float(std::string variable_name);
    int get_config_int(std::string variable_name);
    void load_configuration(std::string filename);
  private:
    Config();
    static Config* singleton;
    void parse_str();
    std::vector<std::string> variable_names;
    std::vector<std::string> variable_values;
};

#endif
