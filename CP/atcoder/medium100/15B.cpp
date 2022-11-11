#include <bits/stdc++.h>
using namespace std;
 
string ke = "keyence";

int main() {
	string s;
	cin >> s;
	int n = s.size();
	int m = ke.size();
	int found = 0;
	
	int p = s.find(ke);
	if(p==0 || (p+m)==n) {
		found = 1;
	}else {
		for(int i=0; i<m; i++) {
			string a = ke.substr(0, i);
			string b = ke.substr(i, m-i+1);
//			cout << a << ": " << b << endl;

			int p1 = s.find(a);
			int p2 = s.rfind(b);
//			cout << p1 << "# " << p2 << endl;
			if(p1==0 && p2+b.size()==n) {
				found = 1;
				break;
			}
		}
	}
	if(found) {
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
	return 0;
}
