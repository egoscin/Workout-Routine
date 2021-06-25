//
//  ExerciseIO.cpp
//  FlexProject
//
//  Created by Erwin Goscin on 4/19/19.
//  Copyright © 2019 Erwin Goscin. All rights reserved.
//

#include "Read.h"
#include "Exercise.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;
string name, weight, sets, reps, day;
const string filename = "plan.txt";
// read function
vector<Exercise> Read::read(){
    
    Exercise exercise;
    vector<Exercise> exercise_list;
    
    const string filename = "plan.txt";
    ifstream input_file(filename);
    
    if (input_file){
        while (getline(input_file, name, '\t') >> weight >> sets >> reps >> day){
            exercise.set_name(name);
            exercise.set_weight(weight);
            exercise.set_sets(sets);
            exercise.set_reps(reps);
            exercise.set_day(day);
            exercise_list.push_back(exercise);// add each field to vector of exercise objects
        }
    }
    input_file.close();
    return exercise_list;
}

