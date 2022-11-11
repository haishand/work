#include<string>
#include<algorithm>
using namespace std;
class MaximumBalances {
public:
	int solve(string s) {
		int o=0, c =0, ans;
		for(int i=0; i<s.length(); i++) {
			if(s[i] == '(') ++o;
			else ++c;
		}
		ans = min(o, c) * (min(o, c)+1)/2 ;
		return ans;
	};
};