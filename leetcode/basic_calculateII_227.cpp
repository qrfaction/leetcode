#include <iostream>
#include <ctype.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int last_num=0;
        int result=0;
        char op='+';
        auto i=s.begin();
        while(i!=s.end()){
            while(isspace(*i)) i++;
            if(isdigit(*i))
                while(isdigit(*i)){
                    last_num=10*last_num+(*i-'0');
                    i++;
                }
            else if(*i == '+' || *i =='-'){
                result+=last_num*(op=='+' ? 1 : -1);
                last_num=0;
                op=*i;
                i++;
            }
            else if(i!=s.end()){
                char cur_op=*i;
                i++;
                while(isspace(*i)) i++;
                int cur_num=0;
                while(isdigit(*i)){
                    cur_num=10*cur_num+(*i-'0');
                    i++;
                }
                if(cur_op=='*') last_num*=cur_num;
                else          last_num/=cur_num;
            }
        }
        result+=last_num*(op=='+' ? 1 : -1);
        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

