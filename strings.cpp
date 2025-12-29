//next permutation 
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
    


