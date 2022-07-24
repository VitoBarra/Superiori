#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;




fstream in;
fstream out;





int main()
{
	in.open("input.txt", ios::in);
	out.open("output.txt", ios::out | ios::trunc);


	int Ncase;
	in>>Ncase;

	for(int N=0; N<Ncase;N++)
	{

        int nf =0;
        int nc=0;
		int spazioRim,filmDim , canzoniDim;
		in>>spazioRim;
		in>>filmDim;
		in>>canzoniDim;




		while(spazioRim>=canzoniDim || spazioRim>=filmDim)
		     {
                if(spazioRim >=filmDim)
                 {
                     nf++;
                     spazioRim -= filmDim;

                 }
                 else if(spazioRim >=canzoniDim)
                 {
                     nc++;
                     spazioRim -= canzoniDim;
                 }
            }

		out<< "case #"<<N+1<<": "<<nf <<" "<<nc<<endl;
	}

	return 0;

	}
