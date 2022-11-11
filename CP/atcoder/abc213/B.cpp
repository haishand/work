#include<bits/stdc++.h>
using namespace std;

using ll = long long;
map<int, int> mp;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i=0; i<N; i++) {
		cin >> a[i];
		mp[a[i]] = i+1;
	}
	sort(a.begin(), a.end());
	cout << mp[a[N-2]]<< endl;
	return 0;
}
