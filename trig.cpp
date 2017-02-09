//
//  main.cpp
//  Fractions
//
//  Created by Vincenzo Marconi on 9/22/13.
//  Copyright (c) 2013 Vincenzo Marconi. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <fstream>
#include <math.h>

using namespace std;



int gcd(int a, int b);
string randCoeff();
string randTrig();


int main(int argc, const char **argv) {
    
    if (argc < 0 || 2 < argc )
        return 0;
    
    int run = 0;
    
    if (argc == 2){
        char l = *argv[1];
        run = atoi(&l);
    } else {
        run = 1;
    }


    char fileName[10];
    
    srand((unsigned int)time( NULL ));
    
    while (--run >= 0) {
    
        ofstream fp;
        
        snprintf(fileName,10, "trig%d.tex",run);
        
        fp.open(fileName);
       
        
        fp << "\\documentclass[12pt]{article}" << endl;
        fp << "\\begin{document}" << endl;
        fp << "\n\n\nEvaluate the following:\n\\\\\\\\\n" << endl;
        
        int i,j;
        for (i = 1; i <= 10; i++) {
            
            fp << (2*i-1) << ".) $" << randTrig() << "(" << randCoeff() << ") = $ \\underline{\\hspace{2cm}} ";
            j = 4;
            while (j-- > 0) fp << "\\indent";
            fp << (2*i) << ".) $" << randTrig() << "(" << randCoeff() << ") = $ \\underline{\\hspace{2cm}} ";
            fp << "\\\\\n" << endl;
            
        }
        
        fp << "\\end{document}\n" << endl;
        
        fp.close();

        
    }
    
    
    return 0;
}




int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}


string randCoeff(){
    
    int n = -1;
    
    if ( (rand()%10) < 8) {
        int d = 5;
        
        while (d == 5)
            d = abs(rand()%5)+2;
  
        while (gcd(n, d) != 1)
            n = abs(rand()%12)+1;
    
        if ( (rand()%4) == 0) n *= -1;
        
        if (n == 1) return "\\frac{\\pi}{"+ to_string(d)+"}";
        else if(n == -1) return "\\frac{-\\pi}{"+ to_string(d)+"}";
        else return "\\frac{"+ to_string(n) +"\\pi}{"+ to_string(d)+"}";
        
    }
    else{
        n = rand()%13;
        
        switch (n) {
            case -1:
                return "-\\pi";
            case 0:
                return "0";
            case 1:
                return "\\pi";
            default:
                    return (to_string(n) + "\\pi");
        }
        
    }
    
    
}





string randTrig(){
    
    int x = abs(rand())%3;
    
    switch(x){
        case 0:
            return "\\sin";
        case 1:
            return "\\cos";
        case 2:
            return "\\tan";
    }
    
    return "\\sin";
}











