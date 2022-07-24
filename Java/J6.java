//Vito Barra
//bubblesort matrice
package Esercizi;

import java.util.Scanner;

public class J6 
{
	public static int[][] matrix ;
	public static int[] vec;
	public static int y, x;
	public static Scanner in = new Scanner(System.in);
	public static boolean scambi = true;

	
	public static void main(String[] Args)
	{
		System.out.print("dammi il numero di riga e colonna:  ");
		y = in.nextInt();
		x = in.nextInt();
		
		inputMat();
		MatrixToVect();
		BubbleSort();
		OutVec();
		MatrixToVect();
		
	}
	
	
	

	
	public static void OutVec()
	{
		for(int i = 0;i<(x*y) ;i++)
			System.out.print(vec[i]+ " "); 
	}
	
	
	public static void inputMat()
	{
		matrix = new int[y][x];
		
		for(int i = 0; i<y ; i++)
			for(int j = 0; j<x ; j++) 
				matrix[i][j]= in.nextInt(); 
	}
	
	
	public static void MatrixToVect()
	{
		vec = new int[y*x];
		
		
		for(int i = 0; i<y ;i++)
			for(int j = 0; j<x ;j++) 
				vec[i*x+j] = matrix[i][j];  //0*3 +0 ;0*3 +1;0*3 + 2 // 1*3 +0 ; 1*3 +1 ; 1*3 +2 //2*3 +0 ; 2*3 +1 ; 2*3 +2
	} 
	
	
	public static void VectToMatrix()
	{
		for(int i = 0; i<y ;i++)
			for(int j = 0; j<x ; j++) 
				 matrix[i][j] = vec[i*y+j];
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
