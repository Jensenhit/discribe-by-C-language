/*
dynamic programming
raid and plunder homes
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    int rob(vector<int>& nums){
        if (nums.size() == 0){
            return 0;
        }
        if (nums.size() == 1){
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};

int main(){
    Solution solve;
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(6);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(7);
    cout<<solve.rob(nums)<<endl;
    return 0;
}
