#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

fstream in;
fstream out;


struct Tutor
{
    int indiceSup;
    int compe;
    bool promoted;
};



main()
{
	in.open("input.txt", ios::in);
	out.open("output.txt", ios::out | ios::trunc);


	int Ncase;
	in>>Ncase;

	for(int T=0; T<Ncase;T++)
	{
		int scambi,nTutor,  ;
		Tutor to[1000];

		in>>nTutor;




		 for(int N =0; N<nTutor;N++)
            {
                in>>to[N].indiceSup;
                in>>to[N].compe;
                in>>to[N].promoted = false;
            }


            while()
            {
                int maxInd;
                int relMax =0;

            for(int N =0; N<nTutor;N++)
               {
                   if(!to[N].promoted && to[N].compe > relMax)
                   {
                       relMax = to[N].compe;
                       maxInd = N;
                   }
               }



               for(int N =0; N<nTutor;N++)
               {
                   if(to[])
                   {
                       relMax = to[N].compe;
                       maxInd = N;
                   }
               }

            }




		out<< "Case #"<<T+1<<": "<< scambi <<endl;


	}

}
