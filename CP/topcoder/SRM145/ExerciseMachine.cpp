#include<bits/stdc++.h>
using namespace std;
class ExerciseMachine {
public:
    int value(string s) {
        if(s.length()>1) {
            return (s[0]-'0')*10 + s[1]-'0';
        }
        return s[0]-'0';
    }
    int getPercentages(string time) {
        string hs, ms, ss;
        int ans;

        hs = time.substr(0, time.find(":"));
        time = time.substr(time.find(":")+1);
        ms = time.substr(0, time.find(":"));
        time = time.substr(time.find(":")+1);
        ss = time.substr(0, time.find(":"));
        
        int h = value(hs);
        int m = value(ms);
        int s = value(ss);
        int seconds = h*60*60 + m*60 +s;
 //       cout << "$ " << seconds << endl;
        int t;
        for(int i=1; i<=100; i++) {
           if(seconds*i % 100 == 0) {
               t = seconds * i / 100;
//               cout << "percent: " << t << endl;
               ans = seconds/t -1;
               break;
           } 
        }
//        cout << ans<< endl;
        return ans;
    }
    
};

int main() {
    ExerciseMachine em;
    em.getPercentages("00:30:00");
    em.getPercentages("00:28:00");
    em.getPercentages("23:59:59");
    em.getPercentages("00:14:10");
    em.getPercentages("00:19:16");
    em.getPercentages("00:00:01");

    return 0;
}