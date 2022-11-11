//#include <bits/stdc++.h>
//using namespace std;
//
//
//const int MAXN = 1e6+10;
//const int INF = 0x7fffffff;
//
//vector<int> a(MAXN);
//vector<int> tree(2*MAXN, INF);
//
//int n, q;
//
//void update(int node, int start, int end, int idx, int val) {
//	if(start >= end) {
//		tree[node]+=val;
//		a[idx]+=val;
//	}else {
//		int mid = (start+end)/2;
//		if(start <=idx && idx <= mid) {
//			update(2*node+1, start, mid, idx, val);
//		}else {
//			update(2*node+2, mid+1, end, idx, val);
//		}
//		tree[node] = min(tree[2*node+1], tree[2*node+2]);
//	}
//}
//
//int query(int node, int start, int end, int left, int right) {
//	if(start>right || end < left) {
//		return INF;
//	}
//	if(start >= left &&  end <= right) {
//		return tree[node];
//	}
//	int mid = (start+end)/2;
//	int t1 = query(2*node+1, start, mid, left, right);
//	int t2 = query(2*node+2, mid+1, end, left, right);
//	return min(t1, t2);
//}
//
//void build(int node, int start, int end) {
//	if(start>=end) {
//		tree[node] = a[start];
//	}else {
//		int mid = (start + end)/2;
//		build(2*node+1, start, mid);
//		build(2*node+2, mid+1, end);
//		tree[node] = min(tree[2*node+1], tree[2*node+2]);
//	}
//}
//
//void build_nonrec() {
//}
//int main() {
//	cin >> n >> q;
//	for(int i=1; i<=n; i++) {
//		cin >> a[i];
//		/*
//		tree[n+i-1] = a[i];
//		int x = n+i-1;
//		while(x>0) {
//			if(x%2) {
//				tree[x/2] = min(tree[x], tree[x-1]);
//			}
//			x/=2;
//		}
//		*/
//	}
//	build(0, 1, n);
//
//	for(int i=0; i<q; i++) {
//		char op;
//		int x, y;
//		cin >> op >> x >> y;
//		switch(op) {
//			case 'u':
//				update(0, 1, n, x, y);
//				break;
//			case 'q':
//				int res = query(0, 1, n, x, y);
//				cout << res << endl;
//				break;
//		}
//
//	}
//	return 0;
//}
//
