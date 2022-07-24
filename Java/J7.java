//Vito Barra
//Fibonacci
package Esercizi;

import java.util.Scanner;

public class J7 
{
	
	public static Scanner in = new Scanner(System.in);
	
	
	public static void main(String[] Args)
	{
		System.out.print("numero serie fibonocci:  ");
		System.out.print(Fib(in.nextInt())); 
	}
	
	public static int Fib(int n)
	{
		if(n==0)
			return n;
		else if(n==1)
			return n;
		else 
			return Fib(n-1) + Fib(n-2);
	}
}
