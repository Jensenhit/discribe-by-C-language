/*
dynamic programming
longest ascending subsequence
plan 1:dynamic
plan 2:stack
*/

#include <iostream>
#include <vector>
using namespace std;

//dynamic
class Solution1{
public:
    int maxSubsetsascend(vector<int>& nums){
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int LIS = 1;
        for (int i = 0; i < dp.size(); i++){
            dp[i] = 1;
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j] && dp[i] < dp[j] +1){
                    dp[i] = dp[j] + 1;
                }
            }
            if (LIS < dp[i]){
                LIS = dp[i];
            }
        }
        return LIS;
    }
};

//stack
class Solution2{
public:
    int maxSubsetsascend(vector<int>& nums){
        if (nums.size() == 0) return 0;
        vector<int> stack;
        stack.push_back(nums[0]);
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > stack.back()){
                stack.push_back(nums[i]);
            }
            else{
                for (int j = 0; j < stack.size(); j++){
                    if (stack[j] >= nums[i]){
                        stack[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return stack.size();
    }
};

int main(){
    int test[] = {1, 3, 2, 3, 1, 4};
    vector<int> nums;
    for (int i = 0; i < 6; i++){
        nums.push_back(test[i]);
    }
    Solution2 solve;
    cout<<solve.maxSubsetsascend(nums)<<endl;
    return 0;
}
