/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   strategy.hpp
 * Author: b1
 *
 * Created on February 18, 2018, 6:52 PM
 */

#include <vector>
#include "circular_buffer.hpp"
#include "tick.hpp"
#include "position.hpp"

using namespace std;


class Strategy
{
public:
    Strategy();
    //called when a new trick on the market.....
    void new_trick(const Tick& tick);
    float gain() const;
    const vector<Position>& positions() const;
    const string& name();
protected:
    //methods dedicated to implementations (subclasses)
    virtual void tick(const Tick tick) = 0;
    void buy(float lots = 1);
    void sell(float lots = 1);
    void close_buy();
    void close_sell();
    
    
    CircularBuffer<Tick> last_ticks;
    vector<Position> long_positions;
    vector<Position> short_positions;
    string _name;
private:
    vector<Position> history;
    float _gain;
    float fee;
};

