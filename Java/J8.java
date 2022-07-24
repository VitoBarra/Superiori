

package Esercizi;

import java.util.Scanner;

public class J8 
{
	public static Cerchio cer; 
	public static Scanner in = new Scanner(System.in);
	
	public static void  main(String Args[])
	{
		System.out.println("dammi il raggio del cerchio: ");
		cer = new Cerchio(in.nextDouble());
		System.out.print("il raggio e' " + cer.GetRaggio() + " area: " + cer.GetArea());
	}
	
}
