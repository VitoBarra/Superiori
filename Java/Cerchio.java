//Vito Barra
package Esercizi;



public class Cerchio
{
	public double raggio;
	
	
	public Cerchio(double _raggio)
	{
		raggio = _raggio;
	}
	
	public double GetRaggio()
	{
		return raggio;
	}
	public void SetRaggio(double _raggio)
	{
		raggio = _raggio;
	}

	
	public double GetArea()
	{
		return raggio *raggio*3.14;
	}

}