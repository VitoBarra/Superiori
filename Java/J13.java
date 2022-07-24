package Esercizi;

import java.util.ArrayList;
import java.util.Scanner;

public class J13 
{
	
	public static ArrayList<Libro> bib = new ArrayList<Libro>();
	
	public static Scanner in = new Scanner(System.in);
	

	public static void main(String[] Args)
	{
		boolean con = true;
		
		
		while(con)
		{
			int sel;
			System.out.println("1)Aggiungi libro");
			System.out.println("2)Rimuvi libro");
			System.out.println("3)Prestito libro");
			System.out.println("4)Restituzione Libro");
			System.out.println("5)stampa lista libri");
			System.out.println("6)exit\n");
			System.out.println("opsioni: ");
			sel = in.nextInt();
		
			switch(sel)
			{	
			case 1:
				System.out.println("inserisci i seguenti dati:");
				System.out.println("Titolo, nome autore, nome editore, Data(gg,mm,aaaa)");
			
				bib.add(new Libro(in.next(),in.next(),in.next(),new Data(in.nextInt(),in.nextInt(),in.nextInt())));
				break;
			case 2:
				{
					System.out.println("inserire il titolo del libro da eliminare");
					String tempTitolo = in.next();
				
					for(int i =0; i<bib.size() ;i++)
					{
						if(bib.get(i).titolo.equalsIgnoreCase(tempTitolo))
						{
							bib.remove(i);
							break;
						}
					}
					break;
				}
			case 3:
			{	
				
				System.out.println("inserire il titolo del libro da prestare");
				String tempTitolo = in.next();
				
				for (Libro next : bib) 
				{
					if(next.titolo.equalsIgnoreCase(tempTitolo))
					{
						System.out.println("inserire la Data(gg,mm,aaaa) dal prestito");
						next.prestato = new Prestito( true, new Data(in.nextInt(),in.nextInt(),in.nextInt()));
						break;
					}
				}
				
				break;
			}	
			case 4:
			{
				System.out.println("inserire il titolo del libro da prestare");
				String tempTitolo = in.next();
				
				for (Libro next : bib)
				{
					if(next.titolo.equalsIgnoreCase(tempTitolo) && next.prestato.stato)
						{
							next.prestato.stato = false;
							break;
						}
				}
				
			}
			
			case 5:
				
				for (Libro nextLib : bib) 
						nextLib.Stampa();
				break;
			
			case 6:
				con = false;
				break;

			}
		}
	}
}
