#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


int segnali[1000000];

fstream in;
fstream out;




main()
{
	in.open("input.txt", ios::in);
	out.open("output.txt", ios::out | ios::trunc);


	int Ncase;
	in>>Ncase;

	for(int T=0; T<Ncase;T++)
	{
		int ris =0,nFuori =0,nDentro=0;
		int nSeganli;
		in>>nSeganli;




		 for(int N =0; N<nSeganli;N++)
            in>>segnali[N];


        for(int N =0; N<nSeganli;N++)
           {
               if(segnali[N]== 1 )
               {
                   if(nFuori ==0)
                      {
                          nDentro++;
                      }
                   else
                   {
                        nDentro++;
                        nFuori--;
                   }
               }
               else
               {
                    if(nDentro ==0)
                        {
                            nFuori++;
                        }
                    else
                    {
                        nDentro--;
                        nFuori++;

                    }
               }
           }

		out<< "Case #"<<T+1<<": "<< nFuori +nDentro <<endl;


	}

}
