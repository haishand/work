// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <assert.h>
#include <fstream>
#include <cstdlib>
#include <random>
#include <iomanip>
#include <queue>
#include <bitset>

using namespace std;

#define sqr(a) ((a)*(a))
#define all(a) (a).begin(), (a).end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'

const int MOD = int(1e9) + 7;
const int MAXN = 1123456;

bool used[MAXN], prime[MAXN];

long long mainSolve(int n, int k, const vector<int>& isOne, const vector<int>& isPrime) {
    vector <int> ones;
    vector <bool> chained(n + 1, false);

    long long res = 0;
    for (int i = 1; i <= n; ++i) if (!chained[i]){
        ones.clear();
        int currentOnes = 0;
        for (int j = i; j <= n; j += k){
            if ((!isOne[j] && !isPrime[j]) || chained[j]) {
                break;
            }
            chained[j] = true;
            if (isOne[j]) {
                currentOnes++;
            } else {
                ones.push_back(currentOnes);
                currentOnes = 0;
            }
        }

        if (ones.size() == 0) continue;
        ones.push_back(currentOnes);
        for (int j = 0; j < ones.size(); ++j) {
            res += ones[j];
            if (j > 0 && j < ones.size() - 1) {
                res += ones[j];
            }

            if (j < ones.size() - 1) {
                res += (long long)(ones[j]) * (long long)(ones[j + 1]);
            }
        }
    }

    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> isOne(n + 1, 0), isPrime(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            isOne[i] = 1;
        } else if (prime[a]) {
            isPrime[i] = 1;
        }
    }

    cout << mainSolve(n, k, isOne, isPrime) << endl;

}


void precalc() {
    for (int i = 2; i < MAXN; ++i) if (!used[i]){
        prime[i] = true;
        for (int j = i; j < MAXN; j += i) {
            used[j] = true;
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    srand(time(0));
    fast_io;
    precalc();

    int tests = 1;
    cin >> tests;
    while (tests--) {
        solve();
    }
}
