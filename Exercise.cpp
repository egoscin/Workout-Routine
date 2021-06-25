//
//  Exercise.cpp
//  FlexProject
//
//  Created by Erwin Goscin on 4/9/19.
//  Copyright © 2019 Erwin Goscin. All rights reserved.
//

#include "Exercise.h"
#include "Read.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cctype>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
// Exercise constructor
Exercise::Exercise(string name_, string weight_, string sets_, string reps_, string day_){
}
// prompt for input to add an exercise to the plan.txt file
void Exercise:: add(){
    Exercise exercise;
    string name, weight, sets, reps, day;
    std::ofstream outfile;
    
    outfile.open("plan.txt", std::ios_base::app);
    // get exercise information
    cout << "Enter exercise name: ";
    getline(cin, name);
    exercise.set_name(name);        // encapsulation using setter functions
    cout << "Enter weight: ";
    cin >> weight;
    exercise.set_weight(weight);    
    cout << "Enter sets: ";
    cin >> sets;
    exercise.set_sets(sets);
    cout << "Enter reps: ";
    cin >> reps;
    exercise.set_reps(reps);
    while(true){
        cout << "Enter day: ";
        cin >> day;
        exercise.set_day(day);
        if(day!="Monday" && day!= "monday" && day!= "MONDAY" && day!="Tuesday" && day!= "tuesday"&& day!= "TUESDAY" && day!="Wednesday" && day!= "wednesday" && day!= "WEDNESDAY" && day!="Thursday" && day!= "thursday"&& day!= "THURSDAY" && day!="Friday" && day!= "friday" && day!="FRIDAY" && day!= "Saturday" && day!="saturday" && day!= "SATURDAY" && day!= "Sunday" && day!= "Sunday" && day!= "SUNDAY"){
            cout << "Please enter a day of the week\n";
        }else break;
    }
    // assign variables to exercise object data members
    exercise.get_name() = name; // encapsulation using get functions
    exercise.get_weight() = weight;
    exercise.get_sets() = sets;
    exercise.get_reps() = reps;
    exercise.get_day() = day;
    // write to file
    outfile << exercise.get_name() + "\t" + exercise.get_weight() + "\t" + exercise.get_sets() + "\t" + exercise.get_reps() + "\t" + exercise.get_day() + "\n";
    outfile.close();
}

void Exercise:: remove(){
    string day, name;
    int index='a'; // will be used to avoid writing exercise index that should be ignored/deleted
    std::ofstream outfile;
    std::vector<Exercise> exercise_list = Read::read();
    outfile.open("plan.txt");
        cout << "Enter exercise name to remove: ";
        getline(cin,name);
        cout << "Enter exercise day to remove: ";
        getline(cin,day);
    
        for(int i=0; i<exercise_list.size();++i){   // loop to erase corresponding fields of the indicated exercise object index
            if("\n" + name == exercise_list[i].name && day == exercise_list[i].get_day()) {
                exercise_list[i].name.erase(0,100);
                exercise_list[i].weight.erase(0,100);
                exercise_list[i].sets.erase(0,100);
                exercise_list[i].reps.erase(0,100);
                exercise_list[i].day.erase(0,100);
                index = i;
            }
        }
    outfile << "\n";
    
    for(int i=0; i<exercise_list.size();++i){
        if(i!=index){   // only write exercises that were not equal to the index to be removed
            exercise_list[i].name.erase(0,1);   // erase extra newline
            outfile << exercise_list[i].name + "\t" + exercise_list[i].weight + "\t" + exercise_list[i].sets + "\t" + exercise_list[i].reps + "\t" + exercise_list[i].day << "\n";
        }
    }
        outfile.close();
}

std::string Exercise::get_name(){
    return name;
}

void Exercise::set_name(std::string name_){
    name = name_;
}
std::string Exercise::get_weight(){
    return weight;
}

void Exercise::set_weight(std::string weight_){
    weight = weight_;
}

std::string Exercise::get_sets(){
    return sets;
}

void Exercise::set_sets(std::string sets_){
    sets = sets_;
}
std::string Exercise::get_reps(){
    return reps;
}

void Exercise::set_reps(std::string reps_){
    reps = reps_;
}
std::string Exercise::get_day(){
    return day;
}

void Exercise::set_day(std::string day_){
    day = day_;
}
