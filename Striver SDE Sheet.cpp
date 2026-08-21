LeetCode 73 (Set Matrix Zeroes) — One-Liner Summary:Use two auxiliary arrays (or the matrix's 1st row & 1st column in $O(1)$ space with a col0 flag) to record which rows and columns contain zeros in Pass 1, then traverse again in Pass 2 to set any cell to 0 if its corresponding row or column is marked.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> row(r,0);
        vector<int> col(c,0);

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

Leetcode 118 Initialize each row $i$ with $i+1$ ones, then fill each inner cell $j$ from $1$ to $i-1$ using ans[i-1][j-1] + ans[i-1][j].
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans; //creating a 2d array to return the answer 
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1); //it created each row which will be added in the answer saari rows ek saath banadi starting me hi and sabme 1 daal diya .....
            for(int j=1;j<i;j++){
                row[j] = ans[i-1][j-1] + ans[i-1][j]; //This is just calculating the each row elements
            }
            ans.push_back(row);
        }
        return ans;
    }
};



Leetcode 31
