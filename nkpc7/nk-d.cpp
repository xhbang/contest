#include<iostream>
using namespace std;

int main()
{
/*	int N,M,i,j,a,Q,u;

	cin>>N>>M>>Q;
	int **Edge;
	int *dis,*s;
	dis=new int[N];
	s=new int[N];
	Edge=new int*[N];
	for(i=0;i<N;i++)
	{
		Edge[i]=new int[N];
	}
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
            Edge[i][j]=100001;
		for(i=0;i<M;i++)
		{
			int F,T,D;
			cin>>F>>T>>D;
			if(D<Edge[F][T])
				Edge[F][T]=D;
			Edge[T][F]=Edge[F][T];
			
		}
	for(i=0;i<Q;i++)
	{
	
		int F,T;
		cin>>F>>T;
		for(j=0;j<N;j++)
		{
			dis[j]=Edge[F][j];
			s[j]=0;
		}
		s[F]=1;
		dis[F]=0;
		for(j=0;j<N-1;j++)
		{
	         u=F;
				int min=100002;
			for(a=0;a<N;a++)
				if((!s[a])&&dis[a]<min)
				{
					u=a;
					min=dis[a];
				}
				s[u]=1;
				for(int w=0;w<N;w++)
				{
					if((!s[w])&&(Edge[u][w]<100002)&&(dis[u]+Edge[u][w]<dis[w]))
						dis[w]=dis[u]+Edge[u][w];
				}
		}
	
		cout<<dis[T]<<endl;
	}
		for(i=0;i<N;i++)
			delete []Edge[i];
		delete []Edge;
		delete []s;
		delete []dis;*/

	return 0;
}




















