#include<bits/stdc++.h>
using namespace std;
class BinaryCode {
public:
    string process(string message, int first) {
        int len = message.length();
        int P[60], Q[60];
        for(int i=0; i<len; i++) {
            Q[i] = message[i]-'0';
        }
        P[0] = first;
        if(len == 1 && P[0] != Q[0]) {
            return "NONE";
        }
        for(int i=1; i<len; i++) {
            if(i==1) P[i] = Q[i-1]-P[i-1];
            else P[i] = Q[i-1]-P[i-1]-P[i-2];
            //cout << "$ " << P[i] << endl;
            if(P[i]!=0 && P[i]!=1) {
                return "NONE";
            }
        }
        if(len>1 && Q[len-1]!=P[len-1]+P[len-2]) {
            return "NONE";
        }

        string s;
        for(int i=0; i<len; i++) {
            s.push_back(P[i]+'0');            
        }
        return s; 
    }
	vector<string> decode(string message) {
        vector<string> v;
        v.push_back(process(message, 0));
        v.push_back(process(message, 1));
        return v;
    }
};

int main() {
    BinaryCode bc;
    vector<string> v;
    while(1) {
        string s;
        cin >> s;
        if(s=="END") break;
        v = bc.decode(s);
        cout << s << ": " << v[0] <<  " " << v[1] << endl;
    }
    /*
   v = bc.decode("123210122");
   cout << v[0] << " " << v[1] << endl;
   */
    return 0;
}