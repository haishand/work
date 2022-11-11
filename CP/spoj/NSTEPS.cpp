//NSTEPS - Number Steps
#include <iostream>
#include<cmath>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int sum = x + y;
        if((x%2 == y%2) && (x-y)<=2 && (x-y)>=0) {
            if(x%2==1) {
                printf("%d\n", sum-1);
            }else  {
                printf("%d\n", sum);
            }

        }else {
            printf("No Number\n");
        }
    }
    return 0;
}