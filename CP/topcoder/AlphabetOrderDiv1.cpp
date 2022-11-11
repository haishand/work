#include<bits/stdc++.h>
using namespace std;

class AlphabetOrderDiv1 {
  public:
  string isOrdered(vector <string> words) {
	  const int maxn = 110;
	  int n = words.size();

	  // one char echo more than 1 time in one word
	  for(int i=0; i<n; i++) {
	  	  vector<int> ca(26, 0);
		  for(int j=0; j<words[i].size(); j++) {
		  	  ++ca[words[i][j] - 'a'];
			  if(ca[words[i][j]-'a']>1) {
				  return string("Impossible");
			  }
		  }
	  }

	  // filter the char in different words 
	  vector<int> cb(26, 0);
	  for(int i=0; i<words.size(); i++) {
		  for(int j=0; j<words[i].size(); j++) {
		  	  ++cb[words[i][j] - 'a'];

		  }
	  }

	  pair<long long, long long> ds[maxn][26];
	  for(int i=0; i<26; i++) {
		  if(cb[i]>1) {
			  char ch = 'a' + i;
			  for(int j=0; j<n; j++) {
				  int found = words[j].find(ch);
				  if(found == string::npos) continue;
				  for(int k=0; k<found; k++) {
					  ds[j][i].first += 1<<(words[j][k]-'a');
				  }
				  for(int k=found; k<words[j].size(); k++) {
					  ds[j][i].second += 1<<(words[j][k]-'a');
				  }
			  }
		  }
	  }

	  for(int i=0; i<26; i++) {
		  if(cb[i]>1) {
			  for(int j=0; j<n; j++) {
			  	  for(int k=j+1; k<n; k++) {
					  long long f1 = ds[j][i].first & ds[k][i].second;
					  long long f2 = ds[j][i].second & ds[k][i].first;
					  if(f1>0 || f2>0) {
						  return string("Impossible");
					  }
				  }
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
			string words[]            = {"a", "b"};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string words[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string words[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
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
}
// END CUT HERE
