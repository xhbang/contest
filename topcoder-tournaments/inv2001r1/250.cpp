#include <string>
#include <iostream>
using namespace std;

class HowEasy
{
public:

	int pointVal(string param0){
		int i = 0, j = 0, k = 0, t = 0, ac = 0;
		//param0[0]is unknow,but it's not 0 still,alright u can check cout<<param0[-1]<<endl;
		for (; param0[i-1] != '\0'; i++){
			//string end with '\0'
			if (param0[i] =='\0' || param0[i] == ' '){
				//j++;
				//k is char valid input,t is check if char is legal
				ac += (t == 0) * k;
				if(t==0)
					j++;
				t = k = 0;
			}
			else
			if (t == 0)
				//if (param0[i] >=65 &&param0[i]<=122)	//65=A,122=z
				if(param0[i]>57)
					//input is number,char,space and period only
					k++;
				else
				if (!(param0[i] == '.' && param0[i + 1] == 0 && k > 0)
						&& !(param0[i] == '.' && param0[i + 1] == ' ' && k > 0)){
					t = 1;
					//except for [a-zA-z][a-zA-z]*.?,may be followed by space or '\0'
					//for debut:cout<<param0[i]<<endl;
				}
		}
		//cout<<"j ist"<<j<<"n"<<"ac ist"<<ac<<endl;
		if (j == 0)
			return (250);
		if (ac / j <= 3)
			return (250);
		if (ac / j <= 5)
			return (500);
		return (1000);
	}
};

//for test only
int main(){
	HowEasy how;
	string input;
	cout<<"input nown";
	getline(cin,input,'n');
	cout<<how.pointVal(input)<<endl;
	return 0;
}
