#include <iostream>
#include <string>
#include <vector>
using namespace std; 
 
class SquareDigits { 
	public: 
	 
	int So(int n){ 
		int yu; 
		int shang=n; 
		int so=0; 
		do 
		{ 
			yu=shang%10; 
			so+=yu*yu; 
			shang=shang/10; 
		}while (shang!=0); 
		return so; 
 
	} 
	void T(int n){ 
		int so=n; 
	     
		do 
		{ 
			 
			so=So(so); 
			my.push_back(so); 
 
		}while (so!=n&&so>=10); 
	 
	} 
	int smallestResult(int param0) { 
		 
		if (param0>199||param0<0) 
		{ 
			cout<<"your param0 isn't in the range."<<endl; 
			return 0; 
		} 
		 
		int b=0; 
		bool ibool=1; 
		vector<int>::iterator check; 
		 
		do 
		{  			 
			T(b); 
			 
			check=my.begin(); 
			do 
			{	 
				if (*check==param0) 
				{ 
					ibool=0; 
				} 
				 
					check++;    
				 
			}while((check!=my.end())&&(ibool!=0)); 
			++b; 
			my.clear(); 
			 
		}while (ibool); 
		return --b; 
	} 
	public: 
    vector<int>my; 
 
}; 
