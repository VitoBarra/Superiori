//Vito Barra
//minimo di due numeri

package Esercizi;

import java.util.Scanner;

public class J2
{
	public static int n1, n2;
	public static Scanner in = new Scanner(System.in);
	
	
	public static void main(String[] Args)
	{
		System.out.print("dammi due numeri: ");
		n1 = in.nextInt();
		n2 = in.nextInt();
		
		if(n1<n2)
			System.out.println("minimo: " + n1 );
		else
			System.out.println("minimo: " + n2);
	}
}
