#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution1 {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > totalset = {{}};
        
        sort(S.begin(),S.end());    //数据排序 
        
        for(int i=0; i<S.size();){
            int count = 0; 
            
            while(count + i<S.size() && S[count+i]==S[i])  count++; //计算该元素出现次数 
            
            int previousN = totalset.size();                //上一阶段的子集个数
             
            for(int k=0; k<previousN; k++){                 //两两组合 
                vector<int> instance = totalset[k];         // 
                for(int j=0; j<count; j++){                 // 
                    instance.push_back(S[i]);               // 
                    totalset.push_back(instance);           // 
                }
            }
            i += count;
        }
        return totalset;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int,int> dict;
        for(auto x:nums)
            if(dict.find(x)!=dict.end()) dict[x]++;
            else                         dict[x]=1;
        int stk[dict.size()];
        int top=-1;
        stk[++top]=0;
        vector<vector<int>> results;
        vector<int> subset;

        auto cur_node=dict.begin();
        while(top!=0 || stk[top]<=cur_node->second){
            if(top<dict.size() && stk[top]<=cur_node->second){
                
                for(int i=0;i<stk[top];i++)
                    subset.push_back(cur_node->first);  // 将该分支要求的元素个数压入子集 
                
                stk[++top]=0;                       //进入当前节点最左边的孩子 
                cur_node++;
            }
            else{
                if(top==dict.size())
                    results.push_back(subset);          // 遇到叶节点   保存子集 
                top--;          // 回溯 
                cur_node--;
                for(int i=0;i<stk[top];i++)         //由于要回溯 把不相干元素弹出 
                    subset.pop_back();
                stk[top]++;       //换分支 
            }

        }
        return results;
    }
};

int main()
{
    Solution s;
    vector<int> a={1,2,2};
    vector<vector<int>> r=s.subsetsWithDup(a);
    for(auto x:r){
        for(auto y:x)
            cout<<y<<',';
        cout<<endl;
    }
    cout<<r.size();
    return 0;
}
