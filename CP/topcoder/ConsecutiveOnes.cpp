#include<bits/stdc++.h>
using namespace std;

class ConsecutiveOnes {
public:
		long long get(long long n, int k) {
		long long ans = 1LL<<52;
		for(int i=0; i<50; i++) {
			if(i+k>50) break;
			long long x = (1LL<<(i+k))-(1LL<<i);
			if((n&x)==x) {
				ans = min(ans, n);
			}else {
				ans = min(ans, (n|x)&(~((1LL<<i)-1)));
			}
		}
		return ans;
	}
	
	/*
 long long get2(long long n, int k) {
		std::string s = std::bitset<50>(n).to_string();
		int ns = s.size();
		long long ma = 0;
		long long ans = n;
		int ma_left = 0, ma_right = 0;
		for(int i=0; i<ns; i++) {
			int j = i;
			while(j<ns && s[j]=='1') {
				++j;
			}
			if(j-i>=ma) {
				ma = j-i;
				ma_left = i;
				ma_right = j;
			}
		}
		if(k>ma) {
			// fill right
			int rest = k-ma;
			int i = ma_right;
			if(i+rest-1<ns) {
				for(;i<=i+rest-1;i++) {
					s[i] = '1';
				}

			}else {
				for(int i=ma_right; i<ns; i++) {
					s[i] = '1';
				}
				rest -= ns-i;

				// fill left
				i = ma_left-1;
				while(rest && i>=0) {
					s[i] = '1';
					i--;
					--rest;
				}
			}

			// reduce the redundant ones
			ma = 0;
			ma_left = 0;
			ma_right = 0;
			for(int i=0; i<ns; i++) {
				int j = i;
				while(j<ns && s[j]=='1') {
					++j;
				}
				if(j-i>=ma) {
					ma = j-i;
					ma_left = i;
					ma_right = j;
				}
			}
			if(ma>k) {
				int rest = ma-k;
				int i = ma_right-1;
				while(rest) {
					s[i] = '0';
					--rest;
					i--;
				}
			}
			ans = stoll(s, nullptr, 2);

		}

		return ans;
	}
*/
};

