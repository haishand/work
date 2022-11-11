#include<bits/stdc++.h>
using namespace std;

class AlphabetOrderDiv1 {
  public:
	  int vis[26]; // 0: white, 1: gray, 2:black
	  int g[26][26];

  std::string isOrdered2(const std::vector<std::string> &words) {
    int g[26][26];
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        g[i][j] = i == j;
      }
    }
    for (const auto &s : words) {
      for (size_t j = 0; j + 1 < s.length(); ++j) {
        int x = s[j] - 'a';
        int y = s[j + 1] - 'a';
        g[x][y] = 1;
      }
    }
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        for (int k = 0; k < 26; ++k) {
          g[j][k] |= g[j][i] & g[i][k];
        }
      }
    }
 
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < i; ++j) {
        if (g[i][j] != 0 && g[j][i] != 0)
          return "Impossible";
      }
    }
    return "Possible";
  }

  bool dfs(int v) {
  	  vis[v] = 1;
	  for(int u=0; u<26; u++) {
		  if(v==u) continue;
		  if(g[v][u]) {
			  if(vis[u] == 0) {
			  	  dfs(u);
			  }else if(vis[u] == 1) {
				  return false;
			  }
		  }
	  }
	  vis[v] = 2;
	  return true;
  }

  bool has_loop() {
	for(int k=0; k<26; k++) {
		for(int i=0; i<26; i++) {
			for(int j=0; j<26; j++) {
				g[i][j] |= g[i][k] & g[k][j];
			}	
		}
	}
	for(int i=0; i<26; i++) {
		for(int j=0; j<i; j++) {
			if(g[i][j] && g[j][i]) {
				return true;
			}
		}
	}
	return false;
  }
  string isOrdered(vector <string> words) {
	  int g[26][26];
	  for(int i=0; i<26; i++) {
		  for(int j=0; j<26; j++) {
			  g[i][j] = (i==j);
		  }
	  }
	  //memset(g, 0, sizeof(g));
	  int n = words.size();
	  for(int i=0; i<n; i++) {
		  for(int j=1; j<words[i].length(); j++) {
			  g[words[i][j-1]-'a'][words[i][j]-'a'] = 1;
		  }
	  }

	  /*
      memset(vis, 0, sizeof(vis));
	  for(int i=0; i<26; i++) {
		  if(dfs(i) == false) {
			  return string("Impossible");
		  }
	  }
	  return string("Possible");
	  */

	for(int k=0; k<26; k++) {
		for(int i=0; i<26; i++) {
			for(int j=0; j<26; j++) {
				g[i][j] |= g[i][k] & g[k][j];
			}	
		}
	}
	for(int i=0; i<26; i++) {
		for(int j=0; j<i; j++) {
			if(g[i][j] && g[j][i]) {
		  		return string("Impossible");
			}
		}
	}
    return string("Possible");
  }
};
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string words[]            = {"single","round","match"};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string words[]            = {"topcoder","topcoder"};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string words[]            = {"algorithm", "contest"};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string words[]            = {"pink","floyd"};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string words[]            = {"gimnasia","y","esgrima","la","plata"};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string words[]            =  {"aaa", "bbbb", "c"};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			string words[]            = {"a", "b"};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 7: {
			string words[]            =  {"a", "ab", "b"};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		default:
			return -1;
		}
	}
}

string rand_str() {
	int len = rand()%101;
	string s;
	for(int i=0; i<len; i++) {
		s.push_back('a'+rand()%26);
	}
	return s;
}

void diff() {
	for(int i=0; i<50; i++) {
		vector<string> vs;
		for(int i=0; i<100; i++) {
			vs.push_back(rand_str());
		}
		AlphabetOrderDiv1 ao;
		if(ao.isOrdered(vs) != ao.isOrdered2(vs)) {
			cout << "diff found" << endl;
		}else {
			cout << i << " passed" << endl;
		}
	}
}
#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
//	diff();
}
// END CUT HERE
