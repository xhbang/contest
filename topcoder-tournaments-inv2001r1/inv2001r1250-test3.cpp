//howeasy
#include <iostream>
#include <string>
using namespace std;

class HowEasy{
	public:
		int pointVal(string str){
			int point=0;
			int awlength=0;
			int words=0;
			int letters=0;
			char end='';
			bool flag=false;
			basic_string<char>::iterator iter;
			for(iter=str.begin();iter!=str.end();iter++){
				char temp=*iter;
				if(temp<='z'&&temp>='a')||(temp<='Z'&&temp>='A'){
					letters++;
					flag=true;
				}else{
					flag=false;
				}
				if(temp=='')
					words++;
			}

			iter=str.end();
			end=*(iter-1);
			if(end=='.'&&flag!=true)
				words++;
			if(flag==true&&end!='.')
				words++;
			if(words!=0)
				awlength=letters/words;

			if(awlength<=3&&awlength>=0)
				point=250;
			else if(awlength==4||awlength==5)
				point=500;
			else if(awlength>=6)
				point=1000;
			return point;
		}
}
		int main()
		{

			 HowEasy he;
			  cout<<”Please input the string:”<<endl;
			   string str;
			    getline(cin, str, ‘\n’);

				 int length = he.pointVal(str);
		}
