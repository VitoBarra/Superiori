package Esercizi;

public class Quadrato 
{
	public double lato;
	
	Quadrato(double _lato)
	{
		lato = _lato;
	}
	
	public void SetLato(double _lato)
	{
		lato = _lato;
	}
	
	public double GetLato()
	{
		return lato;
	}
	
	
	public double GetArea()
	{
		return lato*lato;
	}
	
}
