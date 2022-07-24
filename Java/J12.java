package Esercizi;

import java.util.Scanner;

public class J12 
{
	public static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args)
	{
		System.out.println("dammi il numero degli elementi e la grandezza della copia:");
		
		int n = in.nextInt();
		int k = in.nextInt();

		System.out.println((MyMath.Fat(n))/(MyMath.Fat(k)*MyMath.Fat(n-k)));
	}
}
