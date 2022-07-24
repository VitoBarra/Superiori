//Vito Barra
// bubblesort array
package Esercizi;

import java.util.Scanner;

public class J5 
{
	public static int[] vec;
	public static int n;
	public static Scanner in = new Scanner(System.in);
	public static boolean scambi = true;
	
	
	
	public static void main(String[] Args)
	{
		System.out.print("dammi il numero di elementi:  ");
		n = in.nextInt();
		
		InputVec();
		
		System.out.println("array non ordinato: ");
		OutVec();
		
		
		BubbleSort();
		
		System.out.println();
		System.out.println("array ordinato: ");
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
	
	
	public static void BubbleSort()
	{
		while(scambi)
		{
			scambi = false;
			for(int i = 0 ; i<vec.length-1 ;i++)
			{
				if(vec[i]>vec[i+1])
				{
					int n = vec[i];
					vec[i] = vec[i+1];
					vec[i+1] = n;
					scambi = true;
				}
			}
		}
	}
}
