package Esercizi;

import Esercizi.Data.Format;

class Prestito
{
    public Boolean stato;  
    public Data data;
    
    Prestito(boolean _prestito, int _gg, int _mm, int _aaaa )
    {
    	stato = _prestito;
    	if(stato)
    		data = new Data( _gg, _mm,_aaaa);
    }
    
    Prestito(boolean _prestito, Data _data )
    {
    	stato = _prestito;
    	if(stato)
    		data = _data;
    }
    
 };

public class Libro
{
	public String titolo;
	public String autore;
	public String editore;
	public Data publicazione;
	public Prestito prestato;
	
	
	Libro(String _titolo, String _autore, String _editore, Data _publicazione)
	{
		titolo= _titolo;
		autore=_autore;
		editore = _editore;
		publicazione = _publicazione;
		prestato = new Prestito(false,null);
	}

	Libro(String _titolo, String _autore, String _editore, Data _publicazione, Prestito _prestito)
	{
		titolo= _titolo;
		autore=_autore;
		editore = _editore;
		publicazione = _publicazione;		
		prestato =_prestito;
	}	 
	
	
	
	
	public void Stampa()
	{
		System.out.println("Titolo: "+titolo);
		System.out.println("Autore: "+autore);
		System.out.println("Editore: "+editore);
		System.out.println("publicazione: "+publicazione.Stampa(Format.aaaa_mm_gg));
		System.out.println("prestato: "+ (prestato.stato ) != null? (prestato.stato)?"prestato in data "+ prestato.data.DataFormat(Format.aaaa_mm_gg): "non prestato":"error");
		System.out.println();
	}
	
}
