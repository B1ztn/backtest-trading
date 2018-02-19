/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   simple_pips_diff_trigger.cpp
 * Author: b1
 *
 * Created on February 18, 2018, 9:23 PM
 */

#include <cstdlib>
#include "simple_pips_diff_trigger.hpp"
#include <stdio.h>
using namespace std;

/*
 * 
 */
SimplePipsDiffTrigger::SimplePipsDiffTrigger(float trigger)
{
    this->trigger = trigger;
    this->min = 1000000;
    this->max = 0;
    char buff[100];
    sprintf(buff, "t=%.3f", trigger);
    this->_name = buff;
}


void SimplePipsDiffTrigger::tick(const Tick& tick)
{
    if(short_positions.empty() && tick.bid < (max-trigger))//go short
    {
        if(!long_positions.empty())
            close_buy();
        sell();
        max = 0;
    }
    if(long_positions.empty() && tick.ask>(min+trigger))// go long 
    {
        if(!short_positions.empty())
            close_sell();
        buy();
        min=1000000;
    }
    if(tick.ask<min)
        min = tick.ask;
    if(tick.bid > max)
        max = tick.bid;
}
