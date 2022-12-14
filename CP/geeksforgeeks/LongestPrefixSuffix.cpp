// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{
  public:	
	int lps(string s) {
	    // Your code goes here
		int n = s.size();
	    vector<int> nex(n); 
	    nex[0] = 0;
	    for(int i=1; i<s.size(); i++) {
	        int j = nex[i-1];
	        while(s[i] != s[j] && j>0) {
	            j = nex[j-1];
	        }
	        if(s[i] == s[j]) {
	            ++j;
	        }
	        nex[i] = j;
			printf("nex[%d]=%d\n", i, nex[i]);
	    }
	    return nex[n-1];
	    
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
