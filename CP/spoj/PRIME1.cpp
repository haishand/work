// PRIME1 - Prime Generator

#include<iostream>

using namespace std;

int main() {
    int t, n, m;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        scanf("%d%d", &n, &m);
        for(int j=n; j<=m; j++) {
            bool isprime = true;
            for(int k=2; k*k<j; k++) {
                if(j%k == 0) {
                    isprime = false;
                    break;
                }
            }
            if(isprime) {
                printf("%d\n", j);
            }
        }
        printf("\n");
    }
    return 0;
}