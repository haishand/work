#include<bits/stdc++.h>

using namespace std;
#define LL  long long

const LL mx = 1e9;

void test() {
    for(int i=1; i<1000; i++) {
        if((LL)(pow(i, 5) - pow(i-1, 5))>=mx) {
            cout << i << endl;
            return;
        }
    }
}
int main() {
    int X;
    cin >> X;
    test();
    for(int i=-120; i<=120; i++) {
        for(int j=-120; j<=120; j++) {
            if(i*i*i*i*i - j*j*j*j*j==X) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    return 0;
}
