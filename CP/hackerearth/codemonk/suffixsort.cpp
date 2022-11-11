#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> vs;
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    for(int i=0; i<s.size(); i++) {
        string t = s.substr(i, n-i);
        vs.push_back(t);
    }
    sort(vs.begin(), vs.end());
	cout << vs[k-1] << endl;
    return 0;
}
