/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   position.cpp
 * Author: b1
 *
 * Created on February 18, 2018, 8:00 PM
 */

#include <cstdlib>
#include "position.hpp"

using namespace std;

/*
 * 
 */
float Position::diff() const
{
    return (close_price - open_price)*type;
}

float Position::gain() const
{
    return diff() * lots - (abs(diff())*lots*fee);
}

