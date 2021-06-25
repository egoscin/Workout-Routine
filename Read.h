//
//  ExerciseIO.h
//  FlexProject
//
//  Created by Erwin Goscin on 4/19/19.
//  Copyright © 2019 Erwin Goscin. All rights reserved.
//

#ifndef ExerciseIO_hpp
#define ExerciseIO_hpp

#include <stdio.h>
#include "Exercise.h"
#include <string>
#include <vector>

class Read
{
public:
    Read() {}
    // declare static function
    static std::vector<Exercise> read();
};
#endif /* ExerciseIO_h */
