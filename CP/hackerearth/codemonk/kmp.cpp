#include<bits/stdc++.h>

/*
using namespace std;

const int MAXLEN = 1000;

string a, b;
int na, nb;

// "next" has been used by STL
int nex[MAXLEN]= {-1, 0, 0, 1, 2, 3, 4, 0};

int kmp(string& a, string& b) {
	int n = a.size();
	int m = b.size();
	int i=0, j = 0;
	int start = -1;

	while(i<n && start ==-1) {
		if(a[i] == b[j]) {
			++i, ++j;
		}else {
			j=nex[j]+1;
			++i;
		}
		if(j==m) {
			start = i-m;
		}
	}

	return start;
}

void getNext(string& b, int (&nex)[MAXLEN]) {
	nex[0] = -1;
	int nb = b.size();
	for(int i=1; i<nb; i++) {
		int j = nex[i-1] + 1;
		while (b[i] == b[j] && j >= 0) {
			j = nex[j] + 1;
		}
		nex[i] = j;
	}
}

int main() {
//	cin >> a >> b;

	// kmp
	string a = "ababababca";
	string b = "abababca";

	int tnex[MAXLEN];
	getNext(b, tnex);
	for(int i=0; i<b.size(); i++) {
		printf("nex[%d]=%d\n", i, nex[i]);
	}
	int res = kmp(a, b);
	cout << res << endl;

	return 0;
}
*/