/*
recursion, backtracking, divide and conquer
subsets by backtracking
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;
        sort(nums.begin(), nums.end());
        result.push_back(item);
        generate(0, nums, result, item, res_set);
        return result;
    }
private:
    void generate(int i, vector<int>& nums, vector<vector<int>> &result, vector<int> &item, set<vector<int>> &res_set){
        if (i >= nums.size()){
            return;
        }
        item.push_back(nums[i]);
        if (res_set.find(item) == res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, nums, result, item, res_set);
        item.pop_back();
        generate(i+1, nums, result, item, res_set);
    }
};

int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    vector<vector<int>> result;
    Solution solve;
    result = solve.subsetsWithDup(nums);
    for (int i = 0; i < result.size(); i++){
        if (result[i].size() == 0) cout<<"[]";
        for (int j = 0; j < result[i].size(); j++){
            cout<<"["<<result[i][j]<<"]";
        }
        cout<<endl;
    }
    return 0;
}
