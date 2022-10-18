#include <iostream>
#include <string>
#include <ctime>
#include "horse.h"
#include "userhorse.h"
#include "bred_horse.h"
using namespace std;

//constructor
bred_horse::bred_horse() {
  this->name = "";
  this->max_speed = 0;
  this->min_speed = 0;
  this->level = 1;
  this->num_wins = 0;
  this->generation = 0;
  
  this->dad_name = "";
  this->dad_max_speed = 0;
  this->dad_min_speed = 0;
  this->dad_name = "";
  this->mum_max_speed = 0;
  this->mum_min_speed = 0;;

}

//function to set variables during breedings
void bred_horse::set_bred_horse(string _name, double max, double min, int _generation) {
  this->name = _name;
  this->max_speed = max;
  this->min_speed = min;
  this->generation = _generation;
}

//function to set variables during breedings
void bred_horse::set_parents(string d_name, double d_max, double d_min, string m_name, double m_max, double m_min) {
  this->dad_name = d_name;
  this->dad_max_speed = d_max;
  this->dad_min_speed = d_min;

  this->mum_name = m_name;
  this->mum_max_speed = m_max;
  this->mum_min_speed = m_min;
}

//printing parents
void bred_horse::print_parents() {
  cout << "Parent 1 Name: "<< dad_name <<"   Parent 1 Max Speed: "<< dad_max_speed << endl;
  cout << "Parent 2 Name: "<< mum_name <<"   Parent 2 Max Speed: "<< mum_max_speed << endl;
}