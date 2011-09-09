#include <set>
#include <iostream>
using namespace std;

class SquareDigits{
	public:
	   	int smallestResult(int param0);
	private:
		int s(int x);
};

int SquareDigits::s(int x){ 
	int yu; 
	int ans=0; 
	do 
	{ 
	yu=x%10; 
	ans+=yu*yu; 
	x=x/10; 
	}while (x!=0); 
	return ans; 
} 
int SquareDigits::smallestResult(int param0){
	set<int> is;
	int i=1;
	for(;;i++){
		int k=i;
		is.clear();
		while(1){
			k=s(k);
			if(is.find(k)!=is.end())
				break;
			is.insert(k);
			if(k==param0)
				break;
		}
		if(k==param0)
			return i;
	}
} 
int main(){
	SquareDigits sd;
	int n;
	while(cin>>n)
		cout<<sd.smallestResult(n)<<endl;

}
