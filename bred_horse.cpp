#include <iostream>
#include <string>
#include <ctime>
#include "horse.h"
#include "userhorse.h"
#include "bred_horse.h"
using namespace std;

bred_horse::bred_horse() {
  this->name = "";
  this->max_speed = 0;
  this->min_speed = 0;
  this->level = 1;
  this->points = 0;
  this->num_wins = 0;
  this-> generation = "";
}

void bred_horse::set_bred_horse(string _name, double max, double min) {
  this->name = _name;
  this->max_speed = max;
  this->min_speed = min;
}

void bred_horse::set_parents(string d_name, double d_max, double d_min, string m_name, double m_max, double m_min) {
  this->dad_name = d_name;
  this->dad_max_speed = d_max;
  this->dad_min_speed = d_min;

  this->mum_name = m_name;
  this->mum_max_speed = m_max;
  this->mum_min_speed = m_min;
}