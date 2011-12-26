/*
 * Copyleft:	Hang xie
 * Email:		sonicisdreaming@gmail.com
 * Blog:		xhbang.com
 * File:		"CountingSeries.cpp"
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

#define INF (1<<29)
#define fort(i,a) for(typeof a.begin() i=a.begin(); i!=a.end(); ++i)
#define PB push_back
#define MP make_pair
#define sz(x) int(x.size())

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

using namespace std;

class CountingSeries
{
	private:
		LL count_linear(LL a, LL b, LL up){
			if (up >= a)
				return (up - a)/b + 1;
			else
				return 0;
		}

		LL count_geo(LL a, LL b, LL c, LL d, LL up){
			LL idx, cnt;
			cnt = 0;
			idx = c;
			while (idx <= up){
				bool flag = true;
				if (idx >= a){
					if ((idx - a) % b == 0)
						flag = false;
				}
				cnt += (flag ? 1 : 0);

				idx *= d;
				if (d == 1)
					break;
			}
			return cnt;
		}

	public:
		long long countThem(long long a, long long b, long long c, long long d, long long upperBound){
			LL ans = 0;
			ans += count_linear(a,b,upperBound);
			ans += count_geo(a,b,c,d,upperBound);
			return ans;
			return 5;
		}
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 1000LL; long long Arg5 = 1000LL; verify_case(0, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 3LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 1000LL; long long Arg5 = 343LL; verify_case(1, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 40LL; long long Arg1 = 77LL; long long Arg2 = 40LL; long long Arg3 = 100000LL; long long Arg4 = 40LL; long long Arg5 = 1LL; verify_case(2, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 452LL; long long Arg1 = 24LL; long long Arg2 = 4LL; long long Arg3 = 5LL; long long Arg4 = 600LL; long long Arg5 = 10LL; verify_case(3, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { long long Arg0 = 234LL; long long Arg1 = 24LL; long long Arg2 = 377LL; long long Arg3 = 1LL; long long Arg4 = 10000LL; long long Arg5 = 408LL; verify_case(4, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

int main()
{
	CountingSeries test;
	test.run_test(-1);
	return 0;
}
