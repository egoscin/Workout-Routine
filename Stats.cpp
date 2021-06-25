//
//  Stats.cpp
//  FlexProject
//
//  Created by Erwin Goscin on 4/9/19.
//  Copyright © 2019 Erwin Goscin. All rights reserved.
//

#include "Stats.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
// Stats constructor
Stats::Stats(int height_, int weight_, string level_){
    height = height_;
    weight = weight_;
    level = level_;
}
// get_description() function that will be overwritten by same function in Person
string Stats:: get_description() const{
    string description;
    string height_string = std::to_string(height);
    string weight_string = std::to_string(weight);
    description = "\n|Your Statistics|\n\nHeight: " + height_string + "\nWeight: " + weight_string + "\nActiviy Level: " + level;
    return description;
}
