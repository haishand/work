// ONP - Transform the Expression
#include <iostream>
#include <stack>

#define MAXOP 8
using namespace std;
stack<string> vstack;
stack<char> opstack;
#define ADD 1
#define MINUS 2
#define MUL 3
#define DIV 4
#define POW 5

struct operand
{
    char ch;
    int pri;
};

operand ops[] = {
    {'$', 1},
    {'(', 25},
    {'+', 10},
    {'-', 10},
    {'*', 15},
    {'/', 15},
    {'^', 20},
    {')', 5}};

int ch2pri(char c)
{
    for (int i = 0; i < MAXOP; i++)
    {
        if (c == ops[i].ch)
            return ops[i].pri;
    }
    return 0;
}

void debug() {
    cout << "vstack:" << endl;
    for(stack<string> dump = vstack; !dump.empty(); dump.pop()) {
        cout << dump.top() << endl;
    }
    cout << "opstack:" << endl;
    for(stack<char> dump = opstack; !dump.empty(); dump.pop()) {
        cout << dump.top() << endl;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    string s, ans;
    while (t--)
    {
        cin >> s;

        // add $ the end of expr
        s.push_back('$');

        // init stacks
        opstack.push('$');

        int len = s.length();
        int i = 0;
        while(i<len)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                vstack.push(string(1, s[i]));
                cout <<"var: " << s[i] << endl;
            }
            else
            {
                cout << "op: " << s[i] << endl;
                int pri = ch2pri(s[i]);
                if (pri >= ch2pri(opstack.top()))
                {
                    opstack.push(s[i]);
                }
                else
                {
                    char c;
                    if (s[i] == ')')
                    {
                        do
                        {
                            c = opstack.top(); opstack.pop();
                            if (c == '(')
                                break;
                            if (c == '^')
                            {
                                string v = vstack.top(); vstack.pop();
                                vstack.push(v + c);
                            }
                            else
                            {
                                string v2 = vstack.top(); vstack.pop();
                                string v1 = vstack.top(); vstack.pop();
                                vstack.push(v1 + v2 + c);
                            }
                        } while (c != '(');
                    }else if(s[i] == '$') {
                       char c;
                       do {
                           c = opstack.top(); opstack.pop();
                           if(c=='$') break;
                           if(c=='^') {
                                string v = vstack.top(); vstack.pop();
                                ans.append(v + c);
                               
                           }else {
                                string v2 = vstack.top(); vstack.pop();
                                string v1 = vstack.top(); vstack.pop();
                                ans.append(v1 + v2 + c);
                               
                           }
                       }while(c!='$'); 
                           cout << ans << endl;
                    
                    } else {
                        if (c == '^')
                        {
                            string v = vstack.top(); vstack.pop();
                            vstack.push(v + c);
                        }
                        else
                        {
                            string v2 = vstack.top(); vstack.pop();
                            string v1 = vstack.top(); vstack.pop();
                            vstack.push(v1 + v2 + c);
                        }
                    }
                }
            }
            
            i++;
            debug();
        }
    }
    return 0;
}
