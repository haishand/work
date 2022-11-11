#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	char s[210];
	scanf("%s", s);
	int n = strlen(s);
	for(int i=n-2; i>0; i-=2) {
		if(strncmp(s, s+i/2, i/2) == 0) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
