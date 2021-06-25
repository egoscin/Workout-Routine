//
//  Person.h
//  FlexProject
//
//  Created by Erwin Goscin on 4/9/19.
//  Copyright © 2019 Erwin Goscin. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include "Read.h"
#include "Stats.h"
#include <string>

class Person : public Stats {
    
private:
    int bmi;
    std::string type;
    
public:
    Person(int, int, std::string, int, std::string);
    std::string get_description() const;    // will overwrite get_description from parent class Stats
    static std::string find_type(int, std::string);
    static void change(std::string);
};
#endif /* Person_h */
