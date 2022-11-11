#include <iostream>
using namespace std;
 
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    for (int i = 1; i <= B; ++i) {
        if (A*i%B == C) {
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    
    return 0;
}
