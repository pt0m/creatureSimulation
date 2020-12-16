#include "Config.h"

#include <string>
#include <iostream>
#include <fstream> // Used for reading files

Config *Config::singleton = nullptr;

Config *Config::get_instance() {
  if (singleton == nullptr) {
    singleton = new Config;
  }
  return singleton;
}

Config::Config() {
  load_configuration("configuration.conf");
}

void Config::load_configuration(std::string filename) {
  std::ifstream config_file(filename);
  std::string delimiter = ":";
  std::string line = "";
  while (getline(config_file, line)) {
    if(line != ""){
      int delimiter_pos = line.find(delimiter);
      this->variable_names.push_back(line.substr(0, delimiter_pos));
      this->variable_values.push_back(line.substr(delimiter_pos + delimiter.length()));
    }
  }
  config_file.close();
}

std::string Config::get_config_string(std::string variable_name) {
  int var_index = -1;
  int found = 0;
  for (unsigned int i = 0; i != this->variable_names.size(); i++) {
    if (variable_name.compare(this->variable_names[i]) == 0) {
      var_index = i;
      found = 1;
    }
  }
  if (found == 0) {
    cout << "(!) CONFIG MANQUANTE : " << variable_name << endl;
    return "";
  }
  std::string variable_value = this->variable_values[var_index];
  return variable_value;
}

int Config::get_config_int(std::string variable_name) {
  std::string value = this->get_config_string(variable_name);
  return std::stoi(value);
}

float Config::get_config_float(std::string variable_name) {
  std::string value = this->get_config_string(variable_name);
  return std::stof(value);
}
