//FCTRL2 - Small factorials
#include<iostream>
using namespace std;
#define MAXN	1000
#define LL  long long

int n, t;

int main() {
    scanf("%d", &t);
    while(t--) {
       scanf("%d", &n);
       if(n==0) {
           cout << 1 << endl;
       }else {
            char num[MAXN];
            int len = 1;
            num[0] = '1'; num[len] = 0;
            for(int i=2; i<=n; i++) {
				int carry = 0;
				int j = 0;
				while(j<len) {
					int mul = (num[j]-'0')*i + carry;
					num[j] = mul%10 + '0';
					carry = mul/10;
					j++;
				}
//				printf("carry = %d\n", carry);
				while(carry){
					num[len++] = carry%10+'0';
					num[len] = 0;
					carry /=10;
				}
//				printf("i=%d, num=%s\n", i,num);
			}

            for(int i=len-1; i>=0; i--) {
            	putchar(num[i]);
            }
            putchar('\n');
       }
    }
    return 0;
}