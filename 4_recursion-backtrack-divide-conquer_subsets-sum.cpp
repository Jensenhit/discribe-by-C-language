/*
recursion, backtracking, divide and conquer
subsets sum by backtracking and its cut leaf
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;
        sort(candidates.begin(), candidates.end());
        generate(0, candidates, result, item, res_set, 0, target);
        return result;
    }
private:
    void generate(int i, vector<int>& nums, vector<vector<int>> &result, vector<int> &item, set<vector<int>> &res_set, int sum, int target){
        if (i >= nums.size() || sum > target){
            return;
        }
        sum += nums[i];
        item.push_back(nums[i]);
        if (target == sum && res_set.find(item) == res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, nums, result, item, res_set, sum, target);
        sum -= nums[i];
        item.pop_back();
        generate(i+1, nums, result, item, res_set, sum, target);
    }
};

int main(){
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(5);
    vector<vector<int>> result;
    Solution solve;
    result = solve.combinationSum2(nums, 8);
    for (int i = 0; i < result.size(); i++){
        if (result[i].size() == 0) cout<<"[]";
        for (int j = 0; j < result[i].size(); j++){
            cout<<"["<<result[i][j]<<"]";
        }
        cout<<endl;
    }
    return 0;
}
