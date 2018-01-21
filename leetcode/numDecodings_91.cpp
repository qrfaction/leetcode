#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len=s.length();
        if(len==0 || s[0]=='0')return 0;
        int memory[len+1];
        memory[0]=memory[1]=1;
        for(int i=2;i<len+1;i++){
            //s[i-1]只能与s[i-2]组合
            if(s[i-1]=='0'){
                if(s[i-2]=='1' || s[i-2]=='2')
                    memory[i]=memory[i-2];
                else
                    return 0;
            }
            //s[i-1]不能与s[i-2]组合
            else if(s[i-2]!='1'&&(s[i-2]!='2' || s[i-1]>='7'))
                memory[i]=memory[i-1];
            else
                memory[i]=memory[i-1]+memory[i-2];
        }
        return memory[len];
    }
};


int main()
{
    Solution s=Solution();
    string input;
    cin>>input;
    cout <<s.numDecodings(input)<< endl;
    return 0;
}





