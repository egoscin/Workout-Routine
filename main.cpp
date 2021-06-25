/*
 * Author: Erwin Goscin
 * Purpose: This program reads, writes and designs a workout routine for the user
 */

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "Exercise.h"
#include "Read.h"
#include "Stats.h"
#include "Person.h"

using namespace std;
void menu();
void display(vector<Exercise>);
void add();
void remove();
void show_stats(const Stats&);
void change();

int main(){
    // call menu function to display choices
    menu();
    // open file read file
    vector<Exercise> exercise_list = Read::read();

    //switch menu
    char command = 'v';
    while (command != 'x'){
        cout << "Command: ";
        cin >> command;
        cin.ignore(1000, '\n');
        
        switch (command){
            case 'a':
                add();
                break;
            case 'c':
                change();
                break;
            case 'r':
                remove();
                break;
            case 'v':
                display(exercise_list);
                break;
            case 'x':
                cout << "Bye!\n\n";
                break;
            default:
                cout << "Not a valid command. Please try again.\n\n";
                break;
        }
    }
}

// menu
void menu(){
    cout << "Workout Routine\n\n"
    << "a - add exercise\n"
    << "c - change routine\n"
    << "r - remove exercise\n"
    << "v - View Current Routine\n"
    << "x - Exit\n\n\n";
}
// view function
void display(vector<Exercise> exercise_list){
    exercise_list = Read::read();
    cout << exercise_list;
}
// add exercise
void add(){
    Exercise::add();
}
// remove exercise
void remove(){
    Exercise::remove();
}
//
void show_stats(const Stats& s){
    cout << s.get_description();
}
// change exercies based on stats
void change(){
    double weight=0, height=0, bmi=0;
    string activity, type;
    
    while(true){
        cout << "\nEnter Height(in): ";
        cin >> height;
        if(!cin){
            cout << "Please enter a number";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else break;
    }
    while(true){
        cout << "\nEnter Weight(lbs): ";
        cin >> weight;
        if(!cin){
            cout << "Please enter a number";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else break;
    }
    // calculate bmi
     bmi = weight/(height*height)*703; // bmi variable which will be used in find_type()
    
    while(true){
        cout << "\nEnter activity level(low or high): ";
        cin >> activity;
        if(activity != "low" && activity != "Low" && activity != "LOW" && activity != "high" && activity != "High" && activity != "HIGH"){
            cout << "You entered: " << activity <<"\n";
            cout << "Please enter low or high";
        }
        else{
            break;
        }
    }
    // store result from find_type()
    type = Person::find_type(bmi, activity);
    // create Person object
    Person p(height, weight, activity, bmi, type);
    // call show stats (polymorphism example)
    show_stats(p);
    
    cout << endl << endl;
    // call change() function
    Person::change(type);
    
    cout << "Sets has been adjusted to type\n\n";
}
