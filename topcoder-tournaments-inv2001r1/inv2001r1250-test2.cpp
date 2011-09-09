1 #include <string>
 2 #include <sstream>
 3 #include <algorithm>
 4 using namespace std;
 5 
 6 class HowEasy
 7 {
 8     private:
 9         inline bool isValid(string &token);
10 
11     public:
12         int pointVal(string problemStatement);
13 };
14 
15 const static string g_LegalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
16 
17 bool HowEasy::isValid(string &token)
18 {
19 
20     if(token.empty())
21     {
22         return false;
23     }
24 
25     size_t pos = token.find_first_not_of(g_LegalChars);
26 
27     return (pos == string::npos);
28 }
29 
30 int HowEasy::pointVal(string problemStatement)
31 {
32     string buf;
33     stringstream ss(problemStatement);
34 
35     int count = 0, sum = 0, average = 0;
36     while(ss >> buf)
37     {
38         if(buf.length())
39         {
40             if(buf[buf.length() - 1] == '.')
41             {
42                 buf.erase(buf.end()-1);
43             }
44 
45             if(isValid(buf))
46             {
47                 count++;
48                 sum += buf.length();
49             }
50         }
51     }
52 
53     if(count && sum)
54     {
55         average = sum / count;
56     }
57 
58     if(average <= 3)
59     {
60         return 250;
61     }
62     else if(average <= 5)
63     {
64         return 500;
65     }
66     else
67     {
68         return 1000;
69     }
70 }
