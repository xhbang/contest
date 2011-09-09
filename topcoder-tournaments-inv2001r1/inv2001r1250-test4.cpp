#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class HowEasy {
public:
	int val; // point value

	bool isLetter(char chr);
	int isWord(char* str);
	int calWordLen(char* word);
	vector<string> splitString(string str);
	int pointVal(string param0);
};
bool HowEasy::isLetter(char chr) // determine if a character is a letter
{
return ((chr>=’a'&&chr<=’z') || (chr>=’A'&&chr<=’Z'));
			}
int HowEasy::isWord(char* str) // determine if a string is a word
{
	int flag = 0, i, len = strlen(str);
	if (len <= 0)
		return 0;
	for (i = 0; i < len - 1; i++)
		if (!isLetter(str[i]))
			return 0;
	if (isLetter(str[len - 1]))
		return 1;
	else if (str[len-1]==’.’ && len>1)
		return 2;
	else
		return 0;
	return flag;
}
vector<string> HowEasy::splitString(string str) // split a string into words
{
	string buf;
	vector < string > WordVector;
	stringstream ss(str);
	while (ss >> buf)
		WordVector.push_back(buf);
	vector<string>::const_iterator i;
	for (i = WordVector.begin(); i != WordVector.end(); i++)
		return WordVector;
}
int HowEasy::pointVal(string param0) {
	int i, strsize, LetterCount = 0, WordCount = 0, AveWordLen, WordFlag, pVal =
			0;
	char *buf;
	if (param0.size() <= 0)
		return 0;cout << “\nProblem statement: ” << “\”" << param0 << “\”" << endl << endl;
	vector < string > words = splitString(param0);
	for (i = 0; i < words.size(); i++) {
		strsize = words[i].size();
		buf = new char[strsize + 1];
		buf[strsize] = 0;
		memcpy(buf, words[i].c_str(), strsize);
		WordFlag = isWord(buf);
		switch (WordFlag) {
		case 0:
			cout << ” \”" << buf << “\”" << ” is not a word.” << endl; break;
		case 1: // a word
			WordCount++;
			LetterCount += strsize;
			cout << ” \”" << buf << “\”" << ” is a word of ” << strsize << ” letters.” << endl;
			break;
		case 2: // a word with a period
			WordCount++;
			LetterCount += strsize - 1;
			cout<< ” \”" << buf << “\”" << ” is a word of ” << “\”" << strsize << ” letters.” << endl;
		break;
		}
	}
	delete []buf;
	cout << “\n Number of Words: ” << WordCount << “\n Sum of Word Lengths: ” << LetterCount << endl;
	if (WordCount <= 0 || LetterCount <= 0)
		{pVal = 250; AveWordLen = 0;}
	else
		AveWordLen = LetterCount/WordCount;
	cout << ” Average Word Length: ” << AveWordLen << endl;
	if(AveWordLen<=3)
		pVal = 250;
	else if(AveWordLen==4 || AveWordLen == 5)
		pVal = 500;
	else if(AveWordLen>=6)
		pVal = 1000;
	if (pVal <= 0)
		cout << “\n This is not a valid problem statement.” << endl;
	else
		cout << “\n This is a ” << pVal << ” point problem.” << endl;
	return pVal;
}

int main() {
	HowEasy a;
	a.val = a.pointVal(“This is a problem statement”);
	a.val = a.pointVal(“523hi.”);
	a.val = a.pointVal(“Implement a class H5 which contains some method.”);
	a.val = a.pointVal(“no9 . wor7ds he8re. hj..”);
	return 0;
}
