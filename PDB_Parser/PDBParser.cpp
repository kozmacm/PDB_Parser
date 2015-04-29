//
//  PDBParser.cpp
//  Final Project
//
//  Created by Eric Hatch & Chris Kozma on 5/5/13.
//  Copyright (c) 2013 Eric Hatch & Chris Kozma. All rights reserved.
//

#include "PDBParser.h"

PDBParser::PDBParser(string inName, string outName, string atom1, string atom2, int separation){
    
    //Opening files
    input.open(inName.c_str());
    if (input.fail( )){
        cout << "Input file opening failed.\n";
        exit(1);
    }
    
    output.open(outName.c_str());
    if (output.fail( )){
        cout << "Output file opening failed.\n";
        exit(1);
    }

    
    //Populating the 3 MyArrays with data from the input file
    
    string next;
       
    getline(input,next);
    
    while (! input.eof( )){
        
        unsigned temp = next.find("ATOM");
        
        if (temp==0){//if we are looking at an "ATOM" line.
            
            string Res=next.substr(22,5);//Pulling just the Res col from PDB file
            string Atom=next.substr(11,5);//Pulling just the Atom col from PDB file
            Atom.erase(remove(Atom.begin(),Atom.end(),' '),Atom.end()); //Removes whitespace
            string data=next.substr(30,25);//Pulling the X,Y,Z data from PDB file
            
         
            
            ResArray.addAtEnd(Res);
            AtomArray.addAtEnd(Atom);
            dataArray.addAtEnd(data);
            
            
        }
        getline(input,next);
        

        
    }
    input.close();
    
    
    //Finding the Pairs
    int curRes=atoi(ResArray(0).c_str());//Setting the Current Res number to the first one in the array. (b/c it is not always 1)
    int atom2Res;
    string Atom1out;
    string Atom2out;
    string out;
    
    //Looping though the arrays to find the pairs.
    for(int i=0; i<ResArray.GetSize(); i++){
        
         atom2Res=curRes+separation;
        
        if(atoi(ResArray(i).c_str())==curRes && AtomArray(i)==atom1){
           
            
            Atom1out=dataArray(i);
            
            for(int k=i; k<ResArray.GetSize();k++){
                if(atoi(ResArray(k).c_str())==atom2Res && AtomArray(k)==atom2){
                    Atom2out=dataArray(k);
                }
                
            }
            
            if (Atom2out.empty()) {
                out="999 999 999 999 999 999";//Setting the output to 999 999... when a pair is not found. 
            }
            else{
                out=Atom1out+Atom2out;
                Atom1out.clear();
                Atom2out.clear();
            }
            output<<out<<endl;//Writing the data to the output file. 
           
            curRes++;
           
        }
        
        
    }
    
    
    output.close();
    
}
