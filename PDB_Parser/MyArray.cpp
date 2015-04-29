//
//  MyArray.cpp
//  Final Project
//
//  Created by Eric Hatch & Chris Kozma on 5/5/13.
//  Copyright (c) 2013 Eric Hatch & Chris Kozma. All rights reserved.
//


#include "MyArray.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Constructors******************


MyArray::MyArray() {
    
    size=0;
    
    
    array=new string[size];
    for(int i=0;i<size;i++)
    {
        array[i]="0";
    }
}



//Destructor******************
MyArray::~MyArray()
{
    delete[] array;
    
    
}


//Copys old array into a temp one to hold the values. Deletes old array and creates a new one 1 size bigger. inputs value at the end and copyes old data.
void MyArray::addAtEnd(string value)
{
    string *temp = new string[size+1];
    for(int i=0;i<size;i++)
    {
        temp[i] = array[i];
    }
    temp[size]=value;
    delete[] array;
    array = new string[size+1];
    size += 1;
    for(int i=0;i<size;i++)
    {
        array[i] = temp[i];
    }
    delete[] temp;
    
}



int MyArray::GetSize()
{
    return size;
}





//Operators**************
string MyArray::operator()(int i){
    
    if(i>size-1 || i<0){
        cout<<"Error: Out of Bounds"<<endl;
        exit(1);
    }
    
    return array[i];
    
}
