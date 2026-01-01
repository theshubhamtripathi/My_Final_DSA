///next permutation 
// begin() points to the first element
// end() points just AFTER the last element not the last element
// The expression *nums.begin() will print the value of the first element in the container named nums. 
//The expression *nums.end() would lead to undefined behavior or a runtime error in C++ because it attempts to dereference an invalid iterator. 
//*(nums.end() - 1): This is the correct way to access the last element in the vector. 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //1st approach using c++ stl just a inbuilt function 
        // next_permutation(nums.begin(),nums.end());

        //optimal approach
// 1. Find pivot (break point from right)
// 2. Find just larger element
// 3. Swap
// 4. Reverse the suffix

        int n = nums.size();
        int gola = -1; //find blue gola
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                gola = i-1;
                break;
            }
        }
        if(gola != -1){
        int swap1 = gola;
        for(int i=n-1;i>gola;i--){
            if(nums[i]>nums[gola]){
                swap1 =i;
                break;
            }
        }

        swap(nums[gola],nums[swap1]); //We reverse the subarray after the pivot to make the suffix smallest, ensuring the next lexicographical permutation.
    }
        reverse(nums.begin()+gola+1,nums.end());

    }
};


//left roatate array
reverse(nums.begin(), nums.begin() + k);
reverse(nums.begin() + k, nums.end());
reverse(nums.begin(), nums.end());


//right rotate array
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;   // handle k > n

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}


//longest consecutive seq
//appraoch one nlogn
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 1; //not by 0 by 1 start 
        int maxc = INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]-nums[i+1] == -1){
                count++;
            }
            else if(nums[i] == nums[i+1]){
                continue;
            }
            else{
                maxc = max(count,maxc);
                count = 1;
            }
        }
        maxc = max(count,maxc); //we are using this here suppose if the complete array is consecutive seq then we are not chnaging the value of max thats ehy
        return maxc;
    }
};

// Use set when:
// You only care whether something exists
// You need unique elements
// Example: longest consecutive sequence (hash set version)

// Use map when:
// You need to associate data
// Count frequency
// Store relationships
//approach 2 n
        int n = nums.size();
        int longest = 1;
        if(n==0) return 0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        for(auto it:st){
            if(st.find(it-1) == st.end()){//means smaller number than it is not 
                int x = it;
                int cnt = 1;
                while(st.find(x+1) != st.end()){//means consecutive num present
                    x = x+1;
                    cnt = cnt+1;
                    longest = max(longest,cnt);
                }
            }
        }
        return longest;


//count negative number in a sorted array
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        //1st approach n^2
        // int m = grid.size(); //used to know the length of rows
        // int n = grid[0].size(); //used to know the legth of voloumn
        // int count = 0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j] < 0){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        //2nd approach binary seach or upper bound upper_bound gives an iterator; subtracting begin() converts it to an index. upper_bound returns an iterator pointing to:the first element which should come AFTER the given value according to the sorting order.
        int m = grid.size();
        int n = grid[0].size();
// Yes ✅ — greater<int>() is used to sort in descending order.
        int count = 0;
        for(auto &row:grid){
            int idx = upper_bound(row.begin(),row.end(),0,greater<int>())/*this whole part will return a iterator we must sub to get the index*/-row.begin();
            count += n-idx;
        }
        return count;

        //3rd appproach most optimal m+n
        class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(); //size of row
        int n = grid[0].size(); //size of col

        int row = m-1;
        int col = 0;

        int r = 0;
        while(row>=0 && col<n){
            if(grid[row][col] >= 0){
                col++;
            }
            else{
                r += n-col; //decending order me soted ai bagar ek negative mil gaya toh uske baad sab negative honge
                row--;
            }
        }
        return r;
    }
};

//set matrix 0
// we just created a 2d temp matrix and there we did all the chnages required and then equate with original matrux 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // appraoch 1 tc (m*n + (m+n))
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> temp = matrix;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    for(int k=0;k<n;k++){
                        temp[i][k] = 0; //all row elements are 0 now
                    }
                    for(int k=0;k<m;k++){
                        temp[k][j] = 0; //all col elements are 0 now
                    }
                }
            }
        }

        matrix = temp;
    }
};
    
//better space complexity time same This code first records which rows and columns contain zeros, then in a second pass sets all cells in those rows or columns to zero.
        vector<bool> row(m,false);
        vector<bool> col(n,false);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i] == true || col[j] == true){
                    matrix[i][j] = 0;
                }
            }
        }


//most optimal
        int m = matrix.size(); // size of row
        int n = matrix[0].size(); // size of col

        bool first_r_impact = false;
        bool first_c_impact = false;

        //check first row impacted or not
        for(int i=0;i<n;i++){
            if(matrix[0][i] == 0){
                first_r_impact = true;
                break;
            }
        }

        //check first col impacted or not
        for(int i=0;i<m;i++){
            if(matrix[i][0] == 0){
                first_c_impact = true;
                break;
            }
        }

        //set markers in first row and col 
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(first_r_impact){
            for(int i=0;i<n;i++){
                matrix[0][i] = 0;
            }
        }

        if(first_c_impact){
            for(int i=0;i<m;i++){
                matrix[i][0] = 0;
            }
        }


//rotate matrix image by 90 degree 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //approach 1 
        vector<vector<int>> ans(n,vector<int>(n)); //This line creates a 2-D vector with n rows and n columns, initialized with zeros.
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][(n-1)-i] = matrix[i][j];
            }
        }
        matrix = ans;
    }
};

//aproach 2 we are following just 2 major steps in this thats is first transpose the matrix means chnaging the row with col and then swap the upper part of trangle with lower leaving the diagonal elements as they remain common 
        //Transpose = swap only upper triangle with lower triangle
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

//plus one 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i=n-1;i>=0;i--){  //just iterating from back and normal mathmatical addition 
            if(digits[i] != 9){ //if lastdigit is not equal to 9 then just add on and return
                digits[i] += 1;
                return digits;
            }
            else{
                digits[i] = 0;  //if it is 9 then make that index 0 and carry forward to next digit 
            }
        }
        digits.insert(digits.begin(),1); //if all the elments are 9 then all the digits are 0 and we have to add one 1 at the begenning and return thre naswer
        return digits;
    }
};


//rotate matrix in spriL ORDER 
//The 2 if conditions prevent duplicate traversal when the matrix reduces to a single row or column during spiral traversal.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while(top <= bottom && left <= right){

            // top row
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            // right column
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            // bottom row
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // left column
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};


//subarray sum equals to k 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //approach 1 tc n^2
        // int n = nums.size();
        // int count = 0;
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum += nums[j];
        //         if(sum == k){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int presum = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            presum += nums[i];
            int r = presum - k;
            cnt += mp[r];
            mp[presum] += 1;
        }
        return cnt;
    }
};


