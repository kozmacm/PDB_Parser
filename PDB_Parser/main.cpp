//
//  main.cpp
//  Final Project
//
//  Created by Eric Hatch & Chris Kozma on 5/5/13.
//  Copyright (c) 2013 Eric Hatch & Chris Kozma. All rights reserved.
//

#include <iostream>
#include <string>
#include "PDBParser.h"

using namespace std;


int main(int argc, const char * argv[])
{
           
    //Pulling the arguments from command line
    string inName=argv[1];
    string outName=argv[2];
    string atomOne=argv[3];
    string atomTwo=argv[4];
    int sep=atoi(argv[5]);
    
    //Running the PDB Parser, everything is done in Constructor
    PDBParser parser(inName, outName, atomOne, atomTwo, sep);
    
    
    
    
    
    
   
    

    return 0;
}
