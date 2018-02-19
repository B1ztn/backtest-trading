/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tick.hpp
 * Author: b1
 *
 * Created on February 18, 2018, 6:23 PM
 */
#include <string>
#ifndef TICK_HPP
#define TICK_HPP
using namespace std;

class Tick
{
public:
    int time;
    float bid, ask;
    float bid_volume, ask_volumn;
};


#endif /* TICK_HPP */

