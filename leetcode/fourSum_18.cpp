#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums,int target){
    vector<vector<int>> solution;

    if(nums.size()<4)
        return solution;

    unordered_map<int,vector<pair<int,int>>> num_map;
    int n=nums.size();

    sort(nums.begin(),nums.end());

    for(int i=n-2;i>-1;i--){
        if(i<n-2 && nums[i]==nums[i+1]){
            if(i<=n-3 && nums[i]!=nums[i+2])
                num_map[nums[i]*2].push_back(make_pair(i,i+1));
            continue;
        }
        for(int j=n-1;j>i;j--){
            if(j<n-1 && nums[j]==nums[j+1])
                continue;
            num_map[nums[i]+nums[j]].push_back(make_pair(i,j)); //i<j
        }
    }
    vector<pair<int,int>> index;
    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i]==nums[i-1])
            continue;
        for(int j=i+1;j<n-2;j++){
            if(j>i+1 && nums[j]==nums[j-1])
                continue;
            if(num_map.find(target-nums[i]-nums[j])!=num_map.end()){
                index=num_map[target-nums[i]-nums[j]];
                for(auto iter=index.begin();iter!=index.end();iter++){
                    if(j>=iter->first)  // i<j<first<second
                        break;
                    vector<int> q{
                             nums[i],
                             nums[j],
                             nums[iter->first],
                             nums[iter->second]
                            };
                    solution.push_back(q);
                }
            }
        }
    }
    return solution;


}
