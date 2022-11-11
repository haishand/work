// 1068. Sum
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	cin >> N;
    int step = 1;
    if(N<1) {
        step = -1;
    }
	int sum = 0;
    int x = 1;
    while(x != N+1) {
        sum += x;
        x += step;
    }
    cout << sum << end;
	
	return 0;
}
