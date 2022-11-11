//ACMAKER - ACM (ACronymMaker)
#include<iostream>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<vector>
#include<set>

using namespace std;
#define MAXN    101
#define MAXM    160

string ignore[MAXN];
int n;
//dp[i][j]: 前i个单词中包含前j个缩写的个数
int dp[MAXM][MAXM];

//dp2[i][j]: 
int dp2[MAXM][MAXM];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) break;
        string s;
        set<string> igs;
        for(int i=0; i<n; i++) {
            cin >> s;
            igs.insert(s);
        }

        // ignore '\n'
        cin.ignore();

        for(;;) {
            string line;
            getline(cin, line);
            if(line=="LAST CASE") break;
            string abbr = line.substr(0, line.find(' '));
            string t = line.substr(line.find(' ')+1);
            vector<string> word;
            istringstream ss(t);
            do {
               string w;
               ss>>w;
               if(w=="") break;
               if(igs.find(w) == igs.end()) {
                   word.push_back(w);
               }

            }while(ss);
            int n1 = word.size();
            int n2 = abbr.length();

            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            for(int i=0; i<n1; i++) {
                for(int j=0; j<n2; j++) {
                    // 求第i个单词中含j..n2缩写的个数
                    memset(dp2, 0, sizeof(dp2));
                    int mx = min(n2-j, static_cast<int>(word[i].length()));
                    for(int p=0; p<=word[i].length(); p++) {
                        dp2[p][0] = 1;
                    }
                    for(int p=0; p<word[i].length(); p++) {
                        for(int q=0; q<mx; q++) {
                            dp2[p+1][q+1] = dp2[p][q+1];
                            if(tolower(word[i][p]) == tolower(abbr[j+q])) {
                                dp2[p+1][q+1] += dp2[p][q];
                            }
                        }
                    }
                    for(int k=1; k<=mx; k++){
                        dp[i+1][j+k] += dp[i][j]*dp2[word[i].length()][k];
                    }
                }
            }
            /*
            for(int i=0; i<=n1; i++) {
                for(int j=0; j<=n2; j++) {
                    printf("(%d, %d) = %d\n", i, j, dp[i][j]);
                }
            }
            */
            int ans = dp[n1][n2];
            if(ans) {
                cout << abbr << " can be formed in " << ans << " ways" << endl;
            }else {
                cout << abbr <<" is not a valid abbreviation" << endl;
            }
        }
    }
    return 0;
}
