/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   circular_buffer_test.cpp
 * Author: b1
 *
 * Created on February 19, 2018, 9:41 AM
 */

#include <cstdlib>
#include <assert.h>
#include "circular_buffer.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    CircularBuffer<int> cb(3);
    //push item 
    cb.insert(1);
    assert(cb.get(0)== 1);
    //push again 
    cb.insert(2);
    assert(cb.get(0)==2);
    assert(cb.get(0)==1);
    //push again 
    cb.insert(3);
    assert(cb.get(0)==3);
    assert(cb.get(1)==1);
    assert(cb.get(2)==2);
    //cycles 
    cb.insert(4);
    assert(cb.get(0)==4);
    assert(cb.get(1)==3);
    assert(cb.get(2)==2);
    
}

