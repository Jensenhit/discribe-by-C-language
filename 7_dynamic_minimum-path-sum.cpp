/*
dynamic programming
minimum path sum
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int minPathSum(vector<vector<int>>& grid){
        if (grid.size() == 0) return 0;
        int row = grid.size();
        int column = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(column, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < column; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for (int i = 1; i < row; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
            for (int j = 1; j < column; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[row-1][column-1];
    }
};

int main(){
    int test[][3] = {{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>> grid;
    for (int i = 0; i < 3; i++){
        grid.push_back(vector<int>());
        for (int j = 0; j < 3; j++){
            grid[i].push_back(test[i][j]);
        }
    }
    Solution solve;
    cout<<solve.minPathSum(grid)<<endl;
    return 0;
}
