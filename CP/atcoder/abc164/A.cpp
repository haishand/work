#include<iostream>

using namespace std;
int S, W;

int main()
{
    cin >> S >> W;
    if(W>=S) {
        cout << "unsafe" << endl;
    }else {
        cout << "safe" <<endl;

    }


    return 0;

}