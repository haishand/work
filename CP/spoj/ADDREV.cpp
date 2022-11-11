// ADDREV - Adding Reversed Numbers
#include<iostream>
#include<string>

#define MAXN    10000
using namespace std;

void itora(int n, string &s) {
    s.clear();
    while(n) {
    	char c = n%10 + '0';
        s.push_back(c);
        n/=10;
    } 
}

int atoi(string s) {
	int n = 0;
	for(int i=0; i<s.length(); i++) {
		n = 10*n + s[i]-'0';
	}
	return n;
}

int N;
int main() {
    scanf("%d", &N);
    int a, b;
    char s1[MAXN], s2[MAXN];
    for(int i=0; i<N; i++) {
        scanf("%d%d", &a, &b);
        string t1, t2, t;
        itora(a, t1); itora(b, t2);
        itora(atoi(t1)+atoi(t2), t);

        cout << atoi(t) << endl;
    }
    return 0;
}