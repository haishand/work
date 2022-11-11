#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Time {
public:
	string whatTime(int seconds) {
        int h = seconds/3600;
        int m = (seconds%3600)/60;
        int s = ((seconds%3600)%60)%60;
        char buf[32];
        snprintf(buf, sizeof(buf), "%d:%d:%d", h, m, s);
        string str = buf;
        return str;
    }
};

int main(void) {
    Time t;
    t.whatTime(5436);
    return 0;
}