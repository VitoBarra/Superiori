package Esercizi;

import java.util.Scanner;

public class J10
{
	public static Quadrato qua; 
	public static Scanner in = new Scanner(System.in);
	
	public static void  main(String Args[])
	{
		System.out.println("dammi il raggio del cerchio: ");
		qua = new Quadrato(in.nextDouble());
		System.out.print("il raggio e' " + qua.GetLato() + " area: " + qua.GetArea());
	}
}