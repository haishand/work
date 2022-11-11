#include<iostream>
#include<set>
#define LL long long
using namespace std;
int N;
LL K;
int A[200010];
int trace[200010];
int main() {
    cin >>N >> K;
    for(int i=1; i<=N; i++) {
        cin>>A[i];
    }

    set<int> s;

    // 找到环始点
    s.insert(1);
    int i=1;
    for(;;) {
       i = A[i];
       if(s.count(i)) break; 
       s.insert(i);
    }
//    cout <<"loop start:"<< i << endl;

    // 计算环长度
    LL len = 0; trace[0] = i;
    int j = i;
    for(;;) {
        j=A[j];
        trace[++len] = j;
        if(j==i) break;
    }
//    cout<<"loop size:" << len << endl;

    // 计算1到环始点的个数
    LL t = 0;
    if(i!=1) {
        j=1; t = 1;
        for(;;) {
            j=A[j];
            if(j==i) break;
            ++t;
        }
    }
 //   cout << "1-loop:" << t << endl;

    // 计算答案
    //注意考虑K<=t情况
    if(K<=t) {
        j=1;
        for(;;) {
            j=A[j];
            --K;
            if(K==0) {
                cout <<j<<endl;
                break;
            }
        }
    }else {
        cout << trace[(K-t)%len]<< endl;
    }
    return 0;
}