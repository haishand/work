#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

#define INF     0x3f3f3f3f
#define LL  long long
using namespace std;
int N;
string S;
LL ans = 0;

int main()
{
    
    scanf("%d", &N);
    cin>>S;

    LL c1, c2, c3;
    c1 = c2 = c3  = 0;
    LL rgb = 0;
    for(int i=0; i<N; i++) {
        if(S[i] == 'R') {
            ++c1;
        }
        if(S[i] == 'G') {
            ++c2;
        }
        if(S[i] == 'B') {
             ++c3;

        }
        /*
        if(i+2<N) {
            if(S[i] == S[i+1] && S[i+1] == S[i+2]) {
                ++rgb;
            }
        }
        */
    }

/*
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            int t = j-i;
            if(S[i]!=S[j] && S[j] != S[j+t]) {
                ++rgb ;
            } 
        }
    }
    */

    for(int i=0; i<N; i++) {
        for(int d=1; i+2*d<N; d++) {
            if(S[i] != S[i+d] && S[i+2*d] != S[i]&&S[i+d]!=S[i+2*d]) {
                ++rgb;
            }
         }
    }

//    printf("%d %d\n", c1*c2*c3, rgb);
    ans =c1*c2*c3 -rgb;

/*
    int cnt = 0;
    int t1, t2, t3;
    t1 = t2 = t3;
    ofstream out;
    out.open("1.txt", ios::trunc);
    for(int i=1; i<=N; i++) {
        for(int j=i+1; j<=N; j++) {
            for(int k=j+1; k<=N; k++) {
//                if(k+i==j+j) continue;
                if(k+i==j+j && S[i-1]!=S[j-1] && S[i-1]!=S[k-1] && S[j-1]!=S[k-1]) {
//                    out << i << ","  << j << "," <<k << ":";
//                    out <<S[i-1]<< S[j-1]<< S[k-1]<<endl;
                    ++cnt;
                    //printf("%d %d %d\n", i, j, k);                  
                }
            }
        }
    }
    */
    cout << ans <<endl;
    return 0;
}