//
//  PDBParser.h
//  Final Project
//
//  Created by Eric Hatch & Chris Kozma on 5/5/13.
//  Copyright (c) 2013 Eric Hatch & Chris Kozma. All rights reserved.
//


#ifndef PDBPARSER_H
#define	PDBPARSER_H

#include <iostream>
#include <string>
#include <fstream>
#include "MyArray.h"



using namespace std;

class PDBParser{
    
public:
    

     //Consturctor-all code is located within the consturctor. It handles all the parsing. 
     PDBParser(string inName, string outName, string atom1, string atom2, int separation);
    
    
    
    
private:
    
   //In each of the MyArray objects the index of the array coresponds to a row from the PDB file. 
    MyArray ResArray;//MyArray Object holding just the Residue number col for each atom.
    MyArray AtomArray;//MyArray Object holding just the Atom element name for each atom.
    MyArray dataArray;//MyArray Object holding the X,Y,Z data for each atom.
     
    
    
    
    
    
    //Input and Output data streams
    ifstream input;
    ofstream output;
    
    
    
    
};


#endif	/* PDBPARSER_H */

