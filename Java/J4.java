//Vito Barra
//minimo di un array
package Esercizi;

import java.util.Scanner;

public class J4 
{
	public static int[] vec;
	public static int n, min;
	public static Scanner in = new Scanner(System.in);

	
	public static void main(String[] Args)
	{
		System.out.print("dammi il numero di elementi:  ");
		n = in.nextInt();
		vec = new int[n];
		
		
		vec[0] = in.nextInt();
		min =vec[0];
		for(int i = 1;i<n ;i++)
			{
				vec[i] = in.nextInt();
				if(vec[i]<min)
					min =vec[i];
			}
		
		System.out.println("numero minimo: "+ min);
	}
}