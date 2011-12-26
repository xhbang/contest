/*
 * Copyleft:	Hang xie
 * Email:		sonicisdreaming@gmail.com
 * Blog:		xhbang.com
 * File:		"HowEasy.cpp"
 * Please feel free to use and improve it
 */

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <algorithm>

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;
typedef vector<string> VS;
typedef vector<double> VD;

#define INF (1<<29)
#define fort(i,a) for(typeof a.begin() i=a.begin(); i!=a.end(); ++i)
#define PB push_back
#define MP make_pair
#define sz(x) int(x.size())

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

using namespace std;

class HowEasy
{
	public:
		 int pointVal(string param0)
	{
		$CARETPOSITION$
	}
	// *** WARNING *** No test cases defined for this problem
};

/*
 * Copyleft:	Hang xie
 * Email:		sonicisdreaming@gmail.com
 * Blog:		xhbang.com
 * File:		"HowEasy.cpp"
 * Please feel free to use and improve it
 */

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <algorithm>

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;
typedef vector<string> VS;
typedef vector<double> VD;

#define INF (1<<29)
#define fort(i,a) for(typeof a.begin() i=a.begin(); i!=a.end(); ++i)
#define PB push_back
#define MP make_pair
#define sz(x) int(x.size())

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

using namespace std;

class HowEasy
{
	private:
		int next(string param0, bool flag, int &idx);
	public:
		int pointVal(string param0)
		{
			$CARETPOSITION$
		}
		
		// *** WARNING *** No test cases defined for this problem
};

int HowEasy::next(string param0, bool flag, int &idx){
	int ans = 0;
	flag = false;

	//skip blank
	while (param0[idx] == ' ')
		idx += 1;

	//ends with string or word
	while (param0[idx] != ' ' && param[idx] != '\0') {
		if ( ('a' <= param0[idx] && param[idx] <= 'z')
				||('A' <= param0[idx] && param0 <= 'Z')
				||('.' == param0[idx] && param0 == '\0'))
		{
		}
		else{
			ans = 0;
			flag = true;
		}

		if (!flag)
			ans++;
		if (param0[idx] != '\0')
			idx++;
	}

	if (param0[idx] != ' ')
		idx++;

	return ans;

	}
}


int HowEasy::pointVal(string param0){
	int nchars = 0;
	int nwords = 0;
	int idx = 0;
	bool flag = false;
	while (param0[idx] != '\0'){
		nchars += this->next(param0,flag,idx);
		if (!flag)
			nwords++;
		else{
			nwords = 0;
			break;
		}
	}
	if (nwords == 0)
		return 250;
	else if (nchars / nwords <= 3)
		return 250;
	else if (nchars / nwords >= 4 && nchars / nwords <= 5)
		return 500;
	else if (nchars / nwords >=6)
		return 100;
	else
		return 250;
}

int main()
{
	HowEasy ___test;
	___test.run_test(-1);
	return 0;
}
