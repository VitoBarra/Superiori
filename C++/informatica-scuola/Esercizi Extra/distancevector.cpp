#include <iostream>
using namespace std;

struct Nodo
{
	int p; //partenza
	int d; //destinazione
	int c; //costo
};

int mat[100][100];
int ids[100][100];
Nodo nodo[29600];

void LeggiMat(int r, int c)
{
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			cin>>mat[i][j];
}


int Grafo(int r, int c)
{
	int mid=((c*(r-1))+(r*(c-1)));
	int max=mid*2;
	int x=0;
	int id=0;

	for(int i=0; i<r ; i++)
	{
		for(int j=0 ; j<c ; j++)
		{
			ids[i][j]=id++;
		}
	}

	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
			cout<<ids[i][j]<<" ";
		cout<<endl;
	}

	cout<<endl<<endl;

	for(int i=0;i<r;i++)
	{
		for(int j=0; j<c; j++)
		{
			if(mat[i+1][j]!=0)
				{
					nodo[x].p=ids[i][j];
					nodo[x].d=ids[i+1][j];
					nodo[x].c=(mat[i][j]-mat[i+1][j])*(mat[i][j]-mat[i+1][j]);
					x++;
				}
			if(mat[i][j+1]!=0)
				{
					nodo[x].p=ids[i][j];
					nodo[x].d=ids[i][j+1];
					nodo[x].c=(mat[i][j]-mat[i][j+1])*(mat[i][j]-mat[i][j+1]);
					x++;
				}
		}
	}

	for(int i=0; i<mid;i++)
	{
		nodo[mid+i].p=nodo[i].d;
		nodo[mid+i].d=nodo[i].p;
		nodo[mid+i].c=nodo[i].c;
	}

	for(int i=0 ;i<max; i++)
		cout<<nodo[i].p<<" "<<nodo[i].d<<" "<<nodo[i].c<<endl;

	cout<<endl<<endl;

	return max;
}

void BellmanFord(int r, int c, int max)
{
    int V = r*c;

    int E = max;

    int StoreDistance[V];

    int i,j;

    int source=0;

    // This is initial step that we know , we initialize all distance to infinity except source.
	// We assign source distance as 0(zero)

    for (i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;

    StoreDistance[source] = 0;

    //The shortest path of graph that contain V vertices, never contain "V-1" edges. So we do here "V-1" relaxations
    for (i = 0; i<V ; i++)
    {
        for (j = 0; j<E; j++)
        {
            int u = nodo[j].p;
            int v = nodo[j].d;
            int weight = nodo[j].c;

            if (StoreDistance[u] + weight < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
        }
    }

    // Actually upto now shortest path found. But BellmanFord checks for negative edge cycle. In this step we check for that
    // shortest distances if graph doesn't contain negative weight cycle.

    // If we get a shorter path, then there is a negative edge cycle.
    for (i = 0; i < E; i++)
    {
        int u = nodo[j].p;
        int v = nodo[j].d;
        int weight = nodo[j].c;

        if (StoreDistance[u] + weight < StoreDistance[v])
            cout<<"\nThis graph contains negative edge cycle\n";
    }

 	int x=0;
	for(int i=0; i<r ; i++)
	{
		for(int j=0; j<c ; j++)
			cout<<StoreDistance[x++]<<" ";

		cout<<endl;
	}

    return;
}




main()
{
	//freopen("input.txt","r",stdin);
	int r, c;
	cin>>r>>c;

	LeggiMat(r, c);
	int max = Grafo(r,c);
	BellmanFord(r, c, max);


}
