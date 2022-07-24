//Vito Barra
//lettura e stampa array

package Esercizi;

import java.util.Scanner;

public class J3 
{
	public static int[] vec;
	public static int n;
	public static Scanner in = new Scanner(System.in);

	
	public static void main(String[] Args)
	{
		System.out.print("dammi il numero di elementi:  ");
		n = in.nextInt();
		
		InputVec();
		
		System.out.println("numeri: ");
		
		OutVec();
	}
	



	public static void InputVec()
	{
		vec = new int[n];
		for(int i = 0;i<n ;i++)
				vec[i] = in.nextInt();
	}
	
	public static void OutVec()
	{
		for(int i = 0;i<n ;i++)
			System.out.print(vec[i]+ " "); 
	}
}