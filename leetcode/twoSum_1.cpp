#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int> &nums,int target){
    vector<int> solution;
    if(nums.size()>=2){
        unordered_map<int,int> num_map;
        int i,s;
        s=nums.size();

        for(i=0;i<s;i++)
            num_map[nums[i]ec]=i;

        int ret;

        unordered_map<int,int>::iterator iter;
        for(i=0;i<s;i++){
            ret=target-nums[i];
            iter=num_map.find(ret);
            if(iter!=num_map.end() && iter->second!=i){
                solution.push_back(i);
                solution.push_back(iter->second);
                return solution;
            }
        }
    }
    return solution;
}

int main()
{
    vector<int> nums;
    int num,target;

    cin>>target;
    while(cin>>num)
        nums.push_back(num);

    vector<vector<int>> s;
    s=fourSum(nums,target);
    if(s.size()>0){
        vector<vector<int>>::iterator iter;
        for(iter=s.begin();iter!=s.end();iter++){
            cout<<endl
                <<(*iter)[0]
                <<'\t'
                <<(*iter)[1]
                <<'\t'
                <<(*iter)[2]
                <<'\t'
                <<(*iter)[3];
        }
    }
    else
        cout<<"no solution";

//    vector<int> s;
//    s=twoSum(nums,target);
//    if(s.size()>0){
//        cout<<endl
//        <<s[0]
//        <<endl
//        <<s[1];
//    }
//    else
//        cout<<"no solution";




    return 0;
}










