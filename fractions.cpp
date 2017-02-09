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


using namespace std;



int gcd(int a, int b);
string randFraction();



int main(int argc, const char * argv[]) {

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
        
        snprintf(fileName,10, "frac%d.tex",run);
        
        fp.open(fileName);

        srand((unsigned int)time(NULL));
        
        fp << "\\documentclass[12pt]{article}" << endl;
        fp << "\\begin{document}" << endl;
        fp << "\n\n\nEvaluate the following:\n\\\\\\\\\n" << endl;
        
        int i,j;
        for (i = 1; i <= 10; i++) {
            
            fp << (2*i-1) << ".) $" << randFraction() << " + " << randFraction() << " = $ \\underline{\\hspace{2cm}} ";
            j = 4;
            while (j-- > 0) fp << "\\indent";
            fp << (2*i) << ".) $" << randFraction() << " + " << randFraction() << " = $ \\underline{\\hspace{2cm}} " << endl;
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


string randFraction(){
    
    
    int prob = rand()%10;
    
    if(prob < 9){
        int top = rand()%10+1;
        int bot = top;
        
        while (top == bot) bot = rand()%10+1;
        
        return ("\\frac{" + to_string(top) + "}{" + to_string(bot) + "}");
        
    }
    else{
        int num = rand()%5+1;
        
        return (to_string(num));
    }
    
    
}

















