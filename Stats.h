//
//  Stats.hpp
//  FlexProject
//
//  Created by Erwin Goscin on 4/9/19.
//  Copyright © 2019 Erwin Goscin. All rights reserved.
//

#ifndef Stats_hpp
#define Stats_hpp

#include <stdio.h>
#include <string>

class Stats{
private:

protected:
    int height;
    int weight;
    std::string level;
    
public:
    Stats(int, int, std::string);
    virtual std::string get_description() const; // virtual function to be overwritten
};

#endif /* Stats_h */
