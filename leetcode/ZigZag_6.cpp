#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)  return s;
        int len=s.size();
        vector<string> results(numRows);
        numRows=2*numRows-2;
        for(int i=0,y=0;i<len;++i){
            y=i%numRows;
            y=min(y,numRows-y);
            results[y].push_back(s[i]);
        }
        return accumulate(results.begin(),results.end(),string(""));
    }
};



int main()
{
    auto s=Solution();
    auto a=s.convert("ABCDE",4);
    cout << a<< endl;
    return 0;
}




