class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto x=s.begin();
        for(int i=0;i<t.size();i++){
            if(t[i]==*x)
                x++;
            if(x==s.end())
                return true;
        }
        if(s.empty() && t.empty())
            return true;
        return false;
    }
};
