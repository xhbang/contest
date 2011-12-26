/*
 * Copyleft:	Hang xie
 * Email:		sonicisdreaming@gmail.com
 * Blog:		xhbang.com
 * File:		250.cpp
 * Date:		Wed 21 Dec 2011 08:55:28 PM CST
 *
 * Please feel free to use and improve it
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#define sz(x) int(x.size())
#define PB push_back
#define MP make_pair

using namespace std;

public class MatchMaker{
	public:
		vector<string> getBestMatches(vector<string> member, string user, int sf){
		
			char gender = 'M';
			int N = member.size();
			string name,sg,dg;
			//get current line match to user
			for(int i = 0; i < N; ++i){
				istringstream sm(member[i]);
				sm>>name>>sg>>dg;
				if (user == name2){
					gender = dg[0];
					string ts;
					while (sm >> ts)
						match += ts;
					break;
				}
			}

			vector< pair<int, pair<int,string> > > vec;
			for (int i = 0; i < N; ++i){
				istringstream iss(member[i]);
				iss >> name >> sg >> dg;
				if (name == user)
					continue;
				if (sg[0] != gender)
					continue;
				int count = 0, pos = i;
				string lett;
				int x = 0;
				while (iss >> lett){
					if (x < sz(match) && lett[0] == match[x++])
							count++;
				}
				if (count >= sf)
					vec.PB(make_pair(-count,make_pair(pos,name)));
			}
			sort(vec.begin(), vec.end());
			vector<string> ans;
			for (int i = 0; i < sz(vec); ++i)
				ans.PB(vec[i].second.second);
			return ans;
		}
}

