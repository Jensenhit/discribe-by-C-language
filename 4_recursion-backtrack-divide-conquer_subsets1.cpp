/*
recursion, backtracking, divide and conquer
subsets by backtracking and bits
plan 1:recursion
plan 2:bitwise operation
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution1{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> result;
        vector<int> item;
        result.push_back(item);
        generate(0, nums, item, result);
        return result;
    }
private:
    void generate(int i, vector<int>& nums, vector<int>& item, vector<vector<int>> &result){
        if (i >= nums.size()) return;
        item.push_back(nums[i]);
        result.push_back(item);
        generate(i+1, nums, item, result);
        item.pop_back();
        generate(i+1, nums, item, result);
    }
};

class Solution2{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> result;
        int all_set = 1<<nums.size();
        for (int i = 0; i < all_set; i++){
            vector<int> item;
            for (int j = 0; j < nums.size(); j++){
                if (i &(1<<j)){
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int>> result;
    Solution1 solve;
    result = solve.subsets(nums);
    for (int i = 0; i < result.size(); i++){
        if (result[i].size() == 0) cout<<"[]";
        for (int j = 0; j < result[i].size(); j++){
            cout<<"["<<result[i][j]<<"]";
        }
        cout<<endl;
    }
    return 0;
}
