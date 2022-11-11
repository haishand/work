#include<bits/stdc++.h>
using namespace std;

int dc(vector<int>& v, int left, int right) {
    if(left > right) {
        return 0;
    }
    if(left == right) {
       return v[left];
    }
    int sz = v.size();
    int pos = -1;
	int mi = 1e9;
    for(int i=left; i<=right; i++) {
        if(v[i] == 0) {
            pos = i;
            break;
        }
		mi = min(mi, v[i]);
    }
	if(pos == -1) {
		int t = 0;
		for(int i=left; i<=right; i++) {
			v[i] -= mi;
			if(v[i]==0) {
				t = i;
			}
		}
		return mi + dc(v, left, t-1) + dc(v, t+1, right);
	}else {
    	return dc(v, left, pos-1) + dc(v, pos+1, right);
	}
}

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for(int i=0; i<N; i++) {
        cin >> h[i];
	}

    int ans = dc(h, 0, N-1);
	cout << ans << endl;
    return 0;
}
