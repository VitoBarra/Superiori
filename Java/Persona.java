package Esercizi;

public class Persona 
{

	private String nome ;
	private String cognome;
	private String email;
	private boolean rec = false;
	
	
	Persona(String _nome,String _cognome)
	{
		nome = _nome;
		cognome =_cognome;
	}
	Persona(String _nome,String _cognome,String _email)
	{
		nome = _nome;
		cognome =_cognome;
		email = _email;
		rec = true;
	}
	
	
	public String GetNome()
	{
		return nome;
	}
	public String GetCognome()
	{
		return cognome;
	}
	public String GetEmail()
	{
		return email;
	}
		
	public void SetNome(String _nome )
	{
		nome =_nome;
	}
	public void SetCognome(String _cognome)
	{
		cognome =_cognome;
	}
	public void SetEmail(String _email)
	{
		rec = true;
		if(rec)
			email =_email;
	}
	
}
