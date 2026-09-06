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
//So basically what we did in this question was just first we created or wanted a breaking point after that if we founded a breaking point we just finded the number lesser than it strictly less then we just swap the 2 and then we did the reverse from i+1 and we are done.
void nextPermutation(vector<int>& nums) {

    int n = nums.size();

    // so from right we are checking whether we are getting any breaking point or not
    int i = n - 2;

    while(i >= 0 && nums[i] >= nums[i + 1]) /*we are finding the breakpoint*/ {
        i--;
    }

    if(i >= 0) {

        int j = n - 1;

        while(nums[j] <= nums[i]) {
            j--;
        }

        swap(nums[i], nums[j]);
    }

    reverse(nums.begin() + i + 1, nums.end());
}

Leetcode 53
//using n^2 kind of a sliding window 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = nums[0];
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                maxsum = max(maxsum,sum);
            }
        }
        return maxsum;
    }
};

//using Kdane optimal solution 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = nums[0];
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            maxsum = max(maxsum,sum);

            if(sum < 0){ //The specific purpose of if (sum < 0) { sum = 0; } is to discard a negative running sum so it does not reduce the sum of future subarrays.
                sum = 0;
            }
        }
        return maxsum;
    }
};

Leetcode 121
//Brute force calculating every type of pairs of profits using n^2 complexity
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxp = 0;
        for(int i=0;i<n;i++){
            for(int j =i+1;j<n;j++){
                int profit = prices[j]-prices[i];
                maxp = max(maxp,profit);
            }
        }
        return maxp;
    }
};

Leetcode 287
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //self tried approcah what we did we just used whta given in the question nothing much else 
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] == nums[j]){
                    return nums[j];
                    break;
                }
            }
        }
        return -1;
    }
};

//ye map se haieasy and fast 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it : mp){
            if(it.second > 1){
                return it.first;
            }
        }
        return -1;
    }
};


//we can do also by sorting as well 

//optimal by using slow and fast pointer quite tough baad me seekh lena 

Leetcode 88
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //my approach
        vector<int> ans;
        for(int i=0;i<m;i++){
            ans.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++){
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(),ans.end());
        nums1 = ans;
    }
};


Leetcode 56

//so in this question we did nothing very extreme just we first sorted the first array and then we we checked the first interval last element if it is less then the first one they will make a overlap
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        //till here we sorted the main array

        for(int i=0;i<n;i++){
            if(ans.empty() || intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};


Leetcode 229
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> a;
        unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it] ++;
        }
        for(auto it : mp){
            if(it.second > nums.size()/3){
                a.push_back(it.first);
            }
        }
        return a;
    }
};
