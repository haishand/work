#include <iostream>
#include<map>
#include<algorithm>

using namespace std;
const int MAXN = 2010;
const int MAXA = 1e9;

int A[MAXN];
map<int, int> am;
int N;

int main() {
	cin >> N;
	for(int i=1; i<=N; i++) {
		cin >> A[i];
		am[A[i]] = i;
	}
	sort(A+1, A+N+1, greater<int>());
	
	for(int i=1; i<=N; i++) {
		cout << A[i] << endl;
	}
	return 0;
}