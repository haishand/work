#include<iostream>

using namespace std;
int A, B, C, D;

int main()
{
    cin >> A >> B >> C >> D;
    if(A==0) {
        cout << "No" << endl;
    }else if(C==0){
        cout << "Yes" << endl;
    }else {
        while(A&&C) {
            C -= B;
            if(C<=0) {
                cout << "Yes" << endl;
                break;
            }
            A -= D;
            if(A<=0) {
                cout << "No" << endl;
                break;
            }
        }
    }


    return 0;

}
