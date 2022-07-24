package Esercizi;

import java.util.Scanner;

public class J9 
{
	
	public static Scanner in = new Scanner(System.in);
	public Persona per;
	
	
	public void  main(String Args[])
	{
		
		System.out.println("dammi il nome delle persona (come, cognome , email): ");
		
		per = new Persona(in.next(),in.next(),in.next());
		System.out.print("il  dati della persona:\n nome: " + per.GetNome() + "\ncongnome : " + 
		per.GetCognome()+"\nemail :"+per.GetEmail());
	}
		
}
