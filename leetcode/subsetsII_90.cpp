#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution1 {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > totalset = {{}};
        
        sort(S.begin(),S.end());    //�������� 
        
        for(int i=0; i<S.size();){
            int count = 0; 
            
            while(count + i<S.size() && S[count+i]==S[i])  count++; //�����Ԫ�س��ִ��� 
            
            int previousN = totalset.size();                //��һ�׶ε��Ӽ�����
             
            for(int k=0; k<previousN; k++){                 //������� 
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
                    subset.push_back(cur_node->first);  // ���÷�֧Ҫ���Ԫ�ظ���ѹ���Ӽ� 
                
                stk[++top]=0;                       //���뵱ǰ�ڵ�����ߵĺ��� 
                cur_node++;
            }
            else{
                if(top==dict.size())
                    results.push_back(subset);          // ����Ҷ�ڵ�   �����Ӽ� 
                top--;          // ���� 
                cur_node--;
                for(int i=0;i<stk[top];i++)         //����Ҫ���� �Ѳ����Ԫ�ص��� 
                    subset.pop_back();
                stk[top]++;       //����֧ 
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
