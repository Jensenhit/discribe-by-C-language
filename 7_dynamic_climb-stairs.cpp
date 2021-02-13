/*
dynamic programming
climb stairs
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int climbStairs(int n){
        vector<int> dp(n+3, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main(){
    int m = 3;
    Solution solve;
    int res = solve.climbStairs(m);
    cout<<res<<endl;
    return 0;
}
