#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL A, B, N, ans;

LL calc(LL A, LL B, LL x) {
    return floor(A*x/B) -A*floor(x/B);
}
int main() {
    cin >> A >> B >> N;
    cout<< calc(A, B, min(B-1, N)) << endl;
    return 0;
}