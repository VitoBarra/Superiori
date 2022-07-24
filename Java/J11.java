package Esercizi;

import java.util.Scanner;

public class J11 
{
	
	public static Scanner in = new Scanner(System.in);
	public Persona[] per;
	public int n;
	
	public void  main(String Args[])
	{
		
		System.out.println("quante persone vuoi registrare: ");
		n = in.nextInt();
		
		
		per = new Persona[n];
		
		for (int i =1 ; i<n;i++)
		{
			System.out.println("dammi il nome delle persona (come, cognome , email): ");
			per[i].SetNome(in.next());
			per[i].SetCognome(in.next());
			per[i].SetEmail(in.next());
		}
		for (int i =1 ; i<n;i++)
			System.out.print("il  dati della persona:\n nome: " + per[i].GetNome() + "\ncongnome : " + per[i].GetCognome()+"\nemail :"+per[i].GetEmail());
		
	}

}
