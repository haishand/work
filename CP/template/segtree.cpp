/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>

using namespace std;

#define MAX_VAL 0x3f3f3f3f

int A[100010];
int tree[400040]; // use it started by 1

void build(int pos, int low, int high) {
    if(low == high) {
        tree[pos] = A[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*pos, low, mid);
    build(2*pos+1, mid+1, high);
    tree[pos] = min(tree[2*pos], tree[2*pos+1]);
}

int query(int pos, int low, int high, int ql, int qh){
    if(ql<=low && qh>=high) {
        // overlap
        return tree[pos];
    }
    if(qh<low || ql>high) {
        return MAX_VAL;
    }
    int mid = (low+high)/2;
    return min(query(2*pos, low, mid, ql, qh), query(2*pos+1, mid+1, high, ql, qh));
}

void update(int pos, int low, int high, int idx, int val) {
    if(low == high) {
        A[idx] = val;
        tree[pos] = val;
        return;
    }
    int mid = (low+high)/2;
    if(low<=idx && idx<=mid) {
        update(2*pos, low, mid, idx, val);
    }else {
        update(2*pos+1, mid+1, high, idx, val);
    }
    tree[pos] = min(tree[2*pos] , tree[2*pos+1]);

}

int main() {
    int N, Q;
    scanf("%d%d", &N, &Q);
    for(int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
    }
    build(1, 1, N);
    
    char c;
    int a, b, r;
    for(int i=1;i<=Q;  i++) {
        cin>>c>>a>>b;
//        scanf("%c%d%d", &c, &a, &b);
//        printf("#%c %d %d\n", c, a, b);
        switch(c) {
            case 'q':
                r = query(1, 1, N, a, b);
                printf("%d\n", r);
                break;
            case 'u':
                update(1, 1, N, a, b);
                break;
        }
      
        
    }
    return 0;
}
