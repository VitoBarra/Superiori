#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

fstream in;
fstream out;


struct Cpu
{
    int prezzo ;
    int core;
};

const int MAX_RIS =1000000;
Cpu Ris[MAX_RIS];



main()
{
	in.open("input.txt", ios::in);
	out.open("output.txt", ios::out | ios::trunc);


	int Ncase;
	in>>Ncase;

	for(int T=0; T<Ncase;T++)
	{


		int NIns,budcget;
		Cpu  ins[3000];


		  for(int i = 0 ; i< MAX_RIS ; i++)
            {
                Ris[i].core =0;
                Ris[i].prezzo =0;
            }
        for(int i = 0 ; i< 3000 ; i++)
            {
                ins[i].core =0;
                ins[i].prezzo =0;
            }



		in>>NIns;
		in>>budcget;





		 for(int i =0; i<NIns;i++)
            {
                in>> ins[i].core;
                in>> ins[i].prezzo;
            }


            int posRisIndex=0;

            for(int i =0; i<NIns-1;i++)
            {
                for(int j = i+1; j<NIns;j++)
                {
                    Ris[posRisIndex].core = ins[i].core;
                    Ris[posRisIndex].prezzo = ins[i].prezzo;

                    for(int k =0 ;k<NIns;k++)
                        if(Ris[posRisIndex].prezzo +ins[j+k].prezzo <= budcget)
                        {
                            //cout<<(Ris[posRisIndex].prezzo + ins[j+k].prezzo)<<" \n";
                            //system("pause");
                            Ris[posRisIndex].core +=ins[j+k].core;
                            Ris[posRisIndex].prezzo +=ins[j+k].prezzo;
                        }else
                        {
                            // cout<<Ris[posRisIndex].core<<" " <<Ris[posRisIndex].prezzo<<" "<<i<<" "<<posRisIndex<<" "<<parBig<<" \n";
                            // system("pause");
                             posRisIndex++;
                             break;
                        }
                }

            }

                int MaxCore =0;

                for(int i =0; i<posRisIndex; i++)
                {
                          //cout<<Ris[i].core<<" " <<MaxCore<<" \n";
                    if(Ris[i].core>MaxCore)
                      {
                        MaxCore =Ris[i].core;
                      }

                }

		out<< "Case #"<<T+1<<": "<< MaxCore <<endl;


	}

}
