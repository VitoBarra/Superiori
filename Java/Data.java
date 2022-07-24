package Esercizi;


public class Data
{
	public enum Format {aaaa_mm_gg, mm_gg_aaaa, gg_mm_aaaa }
	
	public int aaaa;
	public int mm;
	public int gg;
	
	public String DataStr;
	
	
	public Data(int _gg, int _mm, int _aaaa)
	{
		aaaa = _aaaa;

		if (_mm > 12)
			mm = 1;
		else mm = _mm;

		if (Giorni31(_mm))
		{
			if (_gg > 31)
				gg = 1;
			else gg = _gg;
		}
		else if (Giorni30(_mm))
		{

			if (_gg > 30)
				gg = 1;
			else gg = _gg;
		}
		else if (Bifestile(_aaaa))
		{
			if (_gg > 29)
				gg = 1;
			else
				gg = _gg;
		}
		else if (_gg > 28)
			gg = 1;
		else gg = _gg;

	}
	
	public boolean Giorni31(int _gg) { return _gg == 1 || _gg == 3 || _gg == 5 || _gg == 7 || _gg == 8 || _gg == 10 || _gg == 12; }
	public boolean Giorni30(int _gg) { return _gg == 4 || _gg == 6 || _gg == 9 || _gg == 11; }
	public boolean Bifestile(int _aaaa) { return _aaaa % 4 == 0; }

	
	
	public String DataFormat(Format form)
	{
		switch(form)
		{
		 
		case mm_gg_aaaa:
			return (String)(mm+"/"+gg+"/"+aaaa);
		case gg_mm_aaaa:
			return (String)(gg+"/"+mm+"/"+aaaa);
		case aaaa_mm_gg:
		default:
			return (String)(aaaa+"/"+mm+"/"+gg);	
			
		}
	}
	
	
	
	
	
	public String Stampa(Format form)
	{
		return DataFormat(form);
	}
}
