/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   position.hpp
 * Author: b1
 *
 * Created on February 18, 2018, 6:53 PM
 */
#include <string>
#include <cmath>

using namespace std;

class Position
{
public:

  enum Type { SHORT = -1, LONG = 1 };

  float     diff() const;
  float     gain() const;

  Type      type;
  int       open_time, close_time;
  float     open_price, close_price;
  float     lots;
  float     fee;
};

