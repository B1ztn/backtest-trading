/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Strategy.cpp
 * Author: b1
 *
 * Created on February 18, 2018, 8:08 PM
 */
#include "strategy.hpp"
#include <cstdlib>

using namespace std;

/*
 * 
 */
Strategy::Strategy()
{
    this->_gain = 0;
    this->fee = 0.0026; // 0.26%
    this->_name = "Strategy";
}

void Strategy::new_trick(const Tick& tick)
{
    last_ticks.insert(tick);
    this->tick(tick);
}

float Strategy::gain()const
{
    return _gain;
}

const vector<Position>& Strategy::positions()const
{
    return history;
}

const string& Strategy::name()
{
    return _name;
}

void  Strategy::buy(float lots)
{
  Position pos;

  pos.type = Position::Type::LONG;
  pos.open_price = last_ticks.get(0).ask;
  pos.open_time = last_ticks.get(0).time;
  pos.lots = lots;
  pos.fee = this->fee;

  long_positions.push_back(pos);
}

void Strategy::sell(float lots)
{
    Position pos;
    pos.type = Position.type.SHORT;
    pos.open_price = last_ticks.get(0).bid;
    pos.lots = lots;
    pos.open_time = last_ticks.get(0).time;
    pos.fee = this->fee;
    short_positions.push_back(pos);
}

void Strategy::close_buy()
{
    Position pos = long_positions.back();
    long_positions.pop_back();
    pos.close_price = last_ticks.get(0).bid;
    pos.close_time = last_ticks.get(0).time;
    history.push_back(pos);
    _gain += pos.gain();
    
}

void Strategy::close_sell()
{
    Position pos = short_positions.back();
    short_positions.pop_back();
    pos.close_price = last_ticks.get(0).ask;
    pos.close_time = last_ticks.get(0).time;
    history.push_back(pos);
    _gain += pos.gain();
}