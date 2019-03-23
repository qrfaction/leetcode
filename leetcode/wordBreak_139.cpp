#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return false;
        int low,high;
        high=low=wordDict[0].length();
        unordered_map<string,bool> dict;
        int len;
        for(auto i=wordDict.begin();i!=wordDict.end();i++){
            dict[*i]=true;
            len=i->length();
            if(len>high)      high=len;
            else if(len<low)  low=len;
        }
        len=s.length();
        if(len<low) return false;

        bool result[len];
        string subs;

        for(int i=0;i<len;i++){
            result[i]=false;
            for(int j=i-low+1;j>=0 && j>i-high;j--){
                subs=s.substr(j,i-j+1);
                if(dict.find(subs)!=dict.end() && (j==0 || result[j-1]==true)){
                    result[i]=true;
                    break;
                }
            }
        }
        return result[len-1];
    }
};


int main()
{
}





