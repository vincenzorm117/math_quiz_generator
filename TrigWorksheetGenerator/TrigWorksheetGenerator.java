import java.io.File;
import java.io.FileWriter;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Random;


public class Q {

	private static Random r;
	
	public static void main(String[] args) throws Exception { new Q(); }
	
	public Q() throws Exception{
		
		
		PrintStream out = new PrintStream(new File("/Users/Vincenzo/Desktop/quiz.tex"));
//		PrintWriter out = new PrintWriter(new FileWriter("/Users/Vincenzo/Desktop/quiz.txt"));
		
		r = new Random();
		
		out.println("\\documentclass[12pt]{article}");
		out.println("\\begin{document}");
		out.println("\n\n\nEvaluate the following:\n\\\\\\\\\n");
		
		// 17 problems fit in one sheet
		
		for(int i = 1; i <=6; i++){
			
			out.print(i+".) $"+Q.randTrigGen()+"("+Q.randCoeff()+") = $ \\underline{\\hspace{2cm}}");
			for(int j = 0; j < 4; j++) out.print("\\indent");
			out.println((i*2)+".) $"+Q.randTrigGen()+"("+Q.randCoeff()+") = $ \\underline{\\hspace{2cm}}");
			out.println("\\\\\n");
		}
		
		out.println("\\end{document}\n");
	}
	
	
	public static String randCoeff() throws Exception{
		
		//Determines the coefficient attached to pi
		int n = 5;
		
		//Determines whether the coefficient is a fraction or an integer
		if(r.nextBoolean()){
			
			//   Numerator: 1 2 3 4 5 6 7 8 9 10 11 12
			// Denominator: 2 3 4 6
			
			int d = 5;
			
			while(d == 5) d = Math.abs( (r.nextInt()%5))+2;
				
//			2 3 4 5 6 
			
			while(gcd(n,d) != 1) n = Math.abs((r.nextInt()%12))+1;
			
			if(r.nextBoolean()) n*= -1;

			if(n == 1) return String.format("\\frac{\\pi}{%d}",d);
			else if(n == -1) return String.format("\\frac{-\\pi}{%d}",d);
			else return String.format("\\frac{%d\\pi}{%d}", n,d);
			
			
		}
		n = (r.nextInt()%13);
		
		
			 if(n == 0) return "0";
		else if(n == 1) return "\\pi";
		else if(n == -1) return"-\\pi";
		else 			return String.format("%d\\pi", n);
		
	}
	
	
	public static int gcd(int a, int b){
		if(b == 0) return a;
		return gcd(b, a%b);
	}
	
	
	public static String randTrigGen() throws Exception{
			
		//Random value used to determine which of the 6 trig functions below to pick
		int x = Math.abs((r.nextInt()%6));
		
		//Trig function selection code
		switch(x){
		 case 0: 
			  return "\\sin";
        case 1:
            return "\\cos";
        case 2:
            return "\\tan";
        case 3:
            return "\\csc";
        case 4:
            return "\\sec";
        case 5:
            return "\\cot";   
		}
		throw new Exception("Bypassed Trig Function Switch");
	}

}
