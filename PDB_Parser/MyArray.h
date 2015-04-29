//
//  MyArray.h
//  Final Project
//
//  Created by Eric Hatch & Chris Kozma on 5/5/13.
//  Copyright (c) 2013 Eric Hatch & Chris Kozma. All rights reserved.
//

#ifndef MYARRAY_H
#define	MYARRAY_H

#include <iostream>
#include <string>
using namespace std;

class MyArray{
    
public:
    //Constructor- builds an array with size zero.
    MyArray();
  
   
    //Destructor-deletes the array
    virtual ~MyArray();
    
    //Makes the array one bigger and adds the given value to the end of the array. 
    void addAtEnd(string value);
    
    //Returns the size of the array
    int GetSize();
    
   
    //Getter- Returns the string held in the array at the givin index
    string operator()(int);
    
private:
    
    int size;//The current size of the array
    string *array;//The string array.
    
};

#endif	/* MYARRAY_H */

