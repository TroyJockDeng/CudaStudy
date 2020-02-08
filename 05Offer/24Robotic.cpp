#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<bool>> been;

    int movingCount(int threshold, int rows, int cols)
    {
        been = vector<vector<bool>>(rows, vector<bool>(cols, false));
        if (rows <= 0 || cols <= 0)
            return 0;
        int nums = 0;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                nums += dfs(threshold, i, j, rows, cols);
            }
        }
        return nums;
    }
    
    int sum(int num){
        int s = 0;
        while (num){
            s += num % 10;
            num /= 10;
        }
        return s;
    }
    
    bool check(int k, int row, int col){
        return k >= sum(row) + sum(col);
    }
    
    int dfs(int threshold, int row, int col, int rows, int cols){
        int dRow[] = {-1, 1, 0, 0 };
        int dCol[] = {0, 0, -1, 1 };
        
        if ( row < 0 || row >= rows || col < 0 || col >= cols)
            return 0;
        if ( been[row][col] )
            return 0;
        if (!check(threshold, row, col)){
            been[row][col] = true;
            return 0;
        }
        
        int nums = 1;
        been[row][col] = true;
        for (int i = 0; i < 4; i++){
            nums += dfs(threshold, row+dRow[i], col+dCol[i], rows, cols);
        }
        return nums;
    }
};

int main(){
    Solution sol;
    cout << sol.sum(12);
    cout << -4 % 2;
    // cout << sol.movingCount(0, 5, 6) << endl;
}