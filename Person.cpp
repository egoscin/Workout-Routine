//
//  Person.cpp
//  FlexProject
//
//  Created by Erwin Goscin on 4/9/19.
//  Copyright © 2019 Erwin Goscin. All rights reserved.
//

#include "Person.h"
#include "Exercise.h"
#include "Read.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
// Person class inheriting Stats class
Person::Person(int height_, int weight_, std:: string level_, int bmi_, std::string type_) : Stats(height_, weight_, level_) {
    bmi = bmi_;
    type = type_;
}
// Function will overwrite function from stats
string Person:: get_description() const{
    string description;
    string height_string = std::to_string(height);
    string weight_string = std::to_string(weight);
    string bmi_string = std::to_string(bmi);
    description = "\n|Your Statistics|\n\nHeight: " + height_string + " in" + "\nWeight: " + weight_string + " lbs" + "\nActiviy Level: " + level + "\nBody Mass Index: " + bmi_string + "\nType: " + type;
    return description;
}
// find type(normal, athete, sedentary) by comparing bmi and activity level (low or high)
string Person::find_type(int bmi_, string level_){
    string type;
    
    if(bmi_<=24 && (level_ == "low" || level_ == "Low" || level_ == "LOW")){
        type = "normal";
    }else if(bmi_<=24 && (level_ == "high" || level_ == "High" || level_ == "HIGH")){
        type = "athlete";
    }else if(bmi_>24 && (level_ == "low" || level_ == "Low" || level_ == "LOW")){
        type = "sedentary";
    }else if (bmi_>24 && (level_ == "high" || level_ == "High" || level_ == "HIGH")){
        type = "normal";
    }
    return type;
}
// change sets and reps based on type(normal, athlete, sedentary)
void Person::change(string type_){
    
    string type = type_;
    // store contents of file in vector called exerise list, then adjust sets and reps and write to file
    std::vector<Exercise> exercise_list = Read::read();
    if(type == "normal"){
        for(int i=0; i<exercise_list.size();++i){
            exercise_list[i].set_sets("4");
            exercise_list[i].set_reps("8");
        }
        std::ofstream outfile;
        outfile.open("plan.txt");
        outfile << "\n";
        for(int i=0; i<exercise_list.size();++i){
            exercise_list[i].name.erase(0,1);
            outfile << exercise_list[i].get_name() + "\t" + exercise_list[i].get_weight() + "\t" + exercise_list[i].get_sets() + "\t" + exercise_list[i].get_reps() + "\t" + exercise_list[i].get_day() << "\n";
        }
    }else if(type == "athlete"){
        for(int i=0; i<exercise_list.size();++i){
            exercise_list[i].set_sets("5");
            exercise_list[i].set_reps("6");
        }
        std::ofstream outfile;
        outfile.open("plan.txt");
        outfile << "\n";
        for(int i=0; i<exercise_list.size();++i){
            exercise_list[i].name.erase(0,1);
            outfile << exercise_list[i].get_name() + "\t" + exercise_list[i].get_weight() + "\t" + exercise_list[i].get_sets() + "\t" + exercise_list[i].get_reps() + "\t" + exercise_list[i].get_day() << "\n";
        }
    }else if(type == "sedentary"){
        for(int i=0; i<exercise_list.size();++i){
            exercise_list[i].set_sets("6");
            exercise_list[i].set_reps("15");
        }
        std::ofstream outfile;
        outfile.open("plan.txt");
        outfile << "\n";
        for(int i=0; i<exercise_list.size();++i){
            exercise_list[i].name.erase(0,1);
            outfile << exercise_list[i].get_name() + "\t" + exercise_list[i].get_weight() + "\t" + exercise_list[i].get_sets() + "\t" + exercise_list[i].get_reps() + "\t" + exercise_list[i].get_day() << "\n";
        }
    }
}

