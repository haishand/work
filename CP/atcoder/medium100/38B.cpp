#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	map<int, int> md;
	for(int i=0; i<N; i++) {
		int d;
		cin >> d;
		auto it = md.find(d);
		if(it!=md.end()) {
			++md[d];
		}else {
			md[d] = 1;
		}
	}
	int M;
	cin >> M;
	int flag = 1;
	for(int i=0; i<M; i++) {
		int t;
		cin >> t;
		auto it = md.find(t);
		if(it!=md.end()) {
			--md[t];
			if(md[t] < 0) {
				flag = 0;
				break;
			}
		}else {
			flag = 0;
		}
	}
	if(flag) {
		cout << "YES";
	}else {
		cout << "NO";
	}
    return 0;
}
