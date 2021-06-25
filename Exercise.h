//
//  Exercise.h
//  FlexProject
//
//  Created by Erwin Goscin on 4/9/19.
//  Copyright © 2019 Erwin Goscin. All rights reserved.
//

#ifndef Exercise_hpp
#define Exercise_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cctype>
#include <fstream>

class Exercise{
private:
    std::string weight;
    std::string sets;
    std::string reps;
    std::string day;
public:
    std::string name;
    Exercise() {};

    Exercise(std::string, std::string, std::string, std::string, std::string);
    static void add();
    static void remove();
    std::string get_name();
    void set_name(std::string);

    std::string get_weight();
    void set_weight(std::string);
    std::string get_sets();
    void set_sets(std::string);
    std::string get_reps();
    void set_reps(std::string);
    std::string get_day();
    void set_day(std::string);
    // friend function allows ostream << operator to work with Exercise
    friend std::ostream& operator<<(std::ostream& out, const std::vector<Exercise>& exercise_list){
        out << "\n                       |Monday|\n";
        out << "----------------------------------------------------";
        out << "\n|Exercise Name|      |Weight(lbs)|  |Sets|    |Reps|\n";
        out << "----------------------------------------------------";
        for(int i=0; i<exercise_list.size();++i){
            // use if day = monday then print
            if(exercise_list[i].day == "Monday"){
                out << std::left << std::setw(27) << exercise_list[i].name;
                out << std::left << std::setw(12) << exercise_list[i].weight;
                out << std::left << std::setw(10) << exercise_list[i].sets;
                out << std::left << std::setw(6) << exercise_list[i].reps;
            }
        }
        
        out << "\n\n                      |Tuesday|\n";
        out << "----------------------------------------------------";
        out << "\n|Exercise Name|      |Weight(lbs)|  |Sets|    |Reps|\n";
        out << "----------------------------------------------------";
        for(int i=0; i<exercise_list.size();++i){
            // use if day = Tuesday then print
            if(exercise_list[i].day == "Tuesday"){
                out << std::left << std::setw(27) << exercise_list[i].name;
                out << std::left << std::setw(12) << exercise_list[i].weight;
                out << std::left << std::setw(10) << exercise_list[i].sets;
                out << std::left << std::setw(6) << exercise_list[i].reps;
            }
        }
        
        out << "\n\n                     |Wednesday|\n";
        out << "----------------------------------------------------";
        out << "\n|Exercise Name|      |Weight(lbs)|  |Sets|    |Reps|\n";
        out << "----------------------------------------------------";
        for(int i=0; i<exercise_list.size();++i){
            // use if day = Wednesday then print
            if(exercise_list[i].day == "Wednesday"){
                out << std::left << std::setw(27) << exercise_list[i].name;
                out << std::left << std::setw(12) << exercise_list[i].weight;
                out << std::left << std::setw(10) << exercise_list[i].sets;
                out << std::left << std::setw(6) << exercise_list[i].reps;
            }
        }
        
        out << "\n\n                      |Thursday|\n";
        out << "----------------------------------------------------";
        out << "\n|Exercise Name|      |Weight(lbs)|  |Sets|    |Reps|\n";
        out << "----------------------------------------------------";
        for(int i=0; i<exercise_list.size();++i){
            // use if day = Thursday then print
            if(exercise_list[i].day == "Thursday"){
                out << std::left << std::setw(27) << exercise_list[i].name;
                out << std::left << std::setw(12) << exercise_list[i].weight;
                out << std::left << std::setw(10) << exercise_list[i].sets;
                out << std::left << std::setw(6) << exercise_list[i].reps;
            }
        }

        out << "\n\n                       |Friday|\n";
        out << "----------------------------------------------------";
        out << "\n|Exercise Name|      |Weight(lbs)|  |Sets|    |Reps|\n";
        out << "----------------------------------------------------";
        for(int i=0; i<exercise_list.size();++i){
            // use if day = Friday then print
            if(exercise_list[i].day == "Friday"){
                out << std::left << std::setw(27) << exercise_list[i].name;
                out << std::left << std::setw(12) << exercise_list[i].weight;
                out << std::left << std::setw(10) << exercise_list[i].sets;
                out << std::left << std::setw(6) << exercise_list[i].reps;
            }
        }
        
        out << "\n\n                      |Saturday|\n";
        out << "----------------------------------------------------";
        out << "\n|Exercise Name|      |Weight(lbs)|  |Sets|    |Reps|\n";
        out << "----------------------------------------------------";
        for(int i=0; i<exercise_list.size();++i){
            // use if day = Friday then print
            if(exercise_list[i].day == "Saturday"){
                out << std::left << std::setw(27) << exercise_list[i].name;
                out << std::left << std::setw(12) << exercise_list[i].weight;
                out << std::left << std::setw(10) << exercise_list[i].sets;
                out << std::left << std::setw(6) << exercise_list[i].reps;
            }
        }
        
        out << "\n\n                       |Sunday|\n";
        out << "----------------------------------------------------";
        out << "\n|Exercise Name|      |Weight(lbs)|  |Sets|    |Reps|\n";
        out << "----------------------------------------------------";
        for(int i=0; i<exercise_list.size();++i){
            // use if day = Friday then print
            if(exercise_list[i].day == "Sunday"){
                out << std::left << std::setw(27) << exercise_list[i].name;
                out << std::left << std::setw(12) << exercise_list[i].weight;
                out << std::left << std::setw(10) << exercise_list[i].sets;
                out << std::left << std::setw(6) << exercise_list[i].reps;
            }
        }
        out << std::endl;
        out << "\nWorkout Plan\n"           // print menu again after routine is printed
        << "a - add exercise\n"
        << "c - change routine\n"
        << "r - remove exercise\n"
        << "v - View Current Routine\n"
        << "x - Exit\n\n\n";
        return out;
    }
};
#endif /* Exercise_h */
