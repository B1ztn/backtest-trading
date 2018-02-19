/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   simple_pips_diff_trigger.hpp
 * Author: b1
 *
 * Created on February 18, 2018, 8:44 PM
 */
#include "strategy.hpp"

class SimplePipsDiffTrigger: public Strategy
{
public:

  SimplePipsDiffTrigger(float trigger = 1);
  void tick(const Tick& tick);

private:

  float min;
  float max;
  float trigger;
};

