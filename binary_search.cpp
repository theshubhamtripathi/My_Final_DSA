//linear search in this we traverse from first to last element step by step 
//Binary search is only applicable when the array is sorted 
//tc : O(log(n)

//leetcode 704
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int high = n-1;
        int low = 0;

        while(low<=high){
            int mid = (low+high)/2;
            if(target == nums[mid]) return mid;
            else if(target<nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;//if not exist
    }
};

// Using this formula prevents Integer Overflow
int mid = low + (high - low) / 2;


//leetcode 35
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int high = n-1;
        int low = 0;
        while(low<=high){
            int mid = (high+low)/2;
            if(target == nums[mid]) return mid;
            else if(target<nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};


//lower bound first smallest index such that arr[idx]>=x
//using c++ stl we can directly use lb = lower_bound(arr.begin(),arr.end(),x) - arr.begin() so we will get the index 
//upper bound smallest index such that arr[mid] > x;

//lower bound code 
int lowerbound(vector<int> arr,int target){
    int n = arr.size();
    int high = n-1;
    int low = 0;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

//upper boudn
int lowerbound(vector<int> arr,int target){
    int n = arr.size();
    int high = n-1;
    int low = 0;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

//using c++ stl we can directly use ub = upper_bound(arr.begin(),arr.end(),x) - arr.begin() so we will get the index 

//leetcode 35
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int high = n-1;
    //     int low = 0;
    //     while(low<=high){
    //         int mid = (high+low)/2;
    //         if(target == nums[mid]) return mid;
    //         else if(target<nums[mid]){
    //             high = mid-1;
    //         }
    //         else{
    //             low = mid+1;
    //         }
    //     }
    //     return low;
    // }

    int n = nums.size();
    int high = n-1;
    int low = 0;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = low+1;
        }
    }
    return ans;
    }
};

//search insert position is equal to lowebound


//floor = largest no in the array <=x
//ceil = smallest no in the array >=x
//just implement lower bound to find ceil and floor 


//When you use curly braces{}, you are telling the compiler to create a vector containing the specific values you've listed inside {} curly braaces.

//leetcode 34
class Solution {
public:
    int lowerbound(vector<int> &nums, int target){
        int n = nums.size();
        int l = 0, h = n - 1;
        int ansl = n;
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(nums[mid] >= target){
                ansl = mid;
                h = mid - 1;
            } else { // Must be in else
                l = mid + 1;
            }
        }
        return ansl;
    }

    int upperbound(vector<int> &nums, int target){
        int n = nums.size();
        int l = 0, h = n - 1;
        int ansu = n;
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(nums[mid] > target){
                ansu = mid;
                h = mid - 1;
            } else { // Must be in else
                l = mid + 1;
            }
        }
        return ansu;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerbound(nums, target);
        
        // Logical Check: If target is not found
        // lb == nums.size() means target is larger than all elements
        // nums[lb] != target means target is missing
        if (lb == nums.size() || nums[lb] != target) {
            return {-1, -1};
        }
        
        int ub = upperbound(nums, target);
        return {lb, ub - 1};
    }
};

//by pure binary search 
class Solution {
public:
    int first(vector<int>& nums, int target){
        int n = nums.size();
        int h = n-1;
        int l = 0;
        int ansf = -1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid] == target){
                ansf = mid;
                h = mid-1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return ansf;
    }
    int last(vector<int>& nums, int target){
        int n = nums.size();
        int h = n-1;
        int l = 0;
        int ansl = -1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid] == target){
                ansl = mid;
                l = mid+1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return ansl;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums,target);
        if(f == -1){
            return {-1,-1};
        }
        int l = last(nums,target);
        return {f,l};
    }
};


//search in a sorted array 1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // 1. Check if mid is the target immediately
            if (nums[mid] == target) {
                return mid;
            }

            // 2. Determine which half is uniformly sorted
            if (nums[low] <= nums[mid]) {
                // Left half is sorted
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1; // Target is in the left sorted portion
                } else {
                    low = mid + 1;  // Target is in the right portion
                }
            } else {
                // Right half is sorted
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;  // Target is in the right sorted portion
                } else {
                    high = mid - 1; // Target is in the left portion
                }
            }
        }
        return -1; // Target not found
    }
};

//if the left part is not sorted then the right parted is sorted thats the property of rotataed sorted array
//leetcode 88
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};


//leetcode 153
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() -1;
        int ans = INT_MAX;

        while(low<=high){
            int mid = low +(high - low)/2;
            if(nums[low]<=nums[mid]){
                ans = min(ans,nums[low]);
                low = mid + 1;
            }
            else{
                high = mid - 1;
                ans = min(ans,nums[mid]);
            }
        }
        return ans;
    }
};

//leetcode 540
//Instead of memorizing code, remember the Bitwise XOR (^ 1) trick used above:Any even number XOR 1 increments it by 1 (e.g., $4 \oplus 1 = 5$).Any odd number XOR 1 decrements it by 1 (e.g., $5 \oplus 1 = 4$).
//if even odd is going on we are on the left side and the single element is on the right side
//if odd even is going on we are on the right side and the single element is on the left side

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it : mp){
            if(it.second == 1){
                ans = it.first;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // 1. Move this to the very top! If n is 1, nums[1] doesn't exist.
        if(n == 1) return nums[0]; 
        
        // Now these are safe to check
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1;
        int high = n-2;

        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            
            // 2. Added explicit parentheses for absolute logical clarity
            if ((mid % 2 == 1 && nums[mid] == nums[mid-1]) || (mid % 2 == 0 && nums[mid] == nums[mid+1])) {
                low = mid + 1; // We are on the left side, move right
            }
            else {
                high = mid - 1; // We are on the right side, move left
            }
        }
        return -1;
    }
};

//leetcode 162 peak elements
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        for(int i=0;i<n;i++){
            if((i==0 || nums[i-1] < nums[i] )&&( i==n-1 || nums[i]> nums[i+1])){
                return i;
            }
        }
        return -1;
    }
};

//for single peak
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // int n = nums.size();
        // if(n==1) return 0;
        // for(int i=0;i<n;i++){
        //     if((i==0 || nums[i-1] < nums[i] )&&( i==n-1 || nums[i]> nums[i+1])){
        //         return i;
        //     }
        // }
        // return -1;

        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 1;
        int high = n-2;

        while(low <= high){
            int mid = low + (high - low) / 2;
            
            // 1. Check if mid is the peak
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            // 2. If we are on a rising slope, peak is to the right
            else if(nums[mid] > nums[mid-1]){
                low = mid + 1;
            }
            // 3. If we are on a falling slope OR in a valley, go left
            else {
                high = mid - 1;
            }
        }
        return -1;

//for multipeak


//Binary search on answers 
//KOKO Eating bananas Leetcode 875
whenever we have a range(in sorted order) and there we know the whether the number should fall on the selected or non selected part we can use the binary search in answers 
whenver we have to find the min answer we have to apply binary search on answers for that we have to know a range and the answer always lies in beteen 

class Solution {
public:
    bool caneatall(vector<int> &piles, int mid, int h){
        // Bug Fix 3: Changed to long long to prevent integer overflow
        long long actualhours = 0; 
        
        for(int i = 0; i < piles.size(); i++){
            // Bug Fix 2: Used pure integer math formula for ceiling division
            actualhours += (piles[i] + mid - 1) / mid;
        }
        return (actualhours <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
       // Bug Fix 1: Changed starting speed 'l' from 0 to 1 to avoid division by zero
       int l = 1; 
       int r = *max_element(piles.begin(), piles.end());
       
       while(l < r){
            int mid = l + (r - l) / 2;
            if(caneatall(piles, mid, h)){
                r = mid; 
            }
            else{
                l = mid + 1;
            }
       }
       return l;
    }
};

//leetcode 1011
One thing we figured out the answer lies between the max weight and the summation of all the weights.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function: Checks if a given capacity 'mid' can ship everything within 'days'
    bool canShipWithCapacity(vector<int>& weights, int mid, int days) {
        int daysNeeded = 1; // Start on Day 1
        int currentLoad = 0;

        for (int i = 0; i < weights.size(); i++) {
            // If adding this package keeps us within capacity, load it up!
            if (currentLoad + weights[i] <= mid) {
                currentLoad += weights[i];
            } 
            // Otherwise, this ship is full for the day. Send it off!
            else {
                daysNeeded++;          // Move to the next day
                currentLoad = weights[i]; // Start the new day's load with this package
            }
        }

        // Return true if the total days taken is less than or equal to allowed days
        return (daysNeeded <= days);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0; // Will store the max element
        int r = 0; // Will store the total sum
        
        for (int i = 0; i < weights.size(); i++) {
            l = max(l, weights[i]); // Ship must hold at least the heaviest package
            r += weights[i];        // Max limit is putting everything on one ship
        }

        // Binary search on the answer range [l, r]
        while (l < r) {
            int mid = l + (r - l) / 2; // Trial capacity

            if (canShipWithCapacity(weights, mid, days)) {
                r = mid; // This capacity works, but let's see if we can go smaller
            } else {
                l = mid + 1; // Too small! We need a stronger ship
            }
        }

        return l; // 'l' will converge to the minimum optimal capacity
    }
};

Leetcode 74
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Brute force
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         if(matrix[i][j] == target){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // int n = matrix.size();  //for number of rows
        // int m = matrix[0].size();  //for number of cols

        // int i=0;
        // int j=m-1;

        // while(i<n && j>=0){
        //     if(matrix[i][j] == target){
        //         return true;
        //     }
        //     else if(matrix[i][j]>target){
        //         j--;
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // return false;

        // optimal as the 2d array is sorted we can impelment binary search
        // in this appraoch we %m and /m the index by the size of col onyl if square matix as n == m so we can use any this was the main approach
        class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;

        int n = matrix.size();    // Total Rows
        int m = matrix[0].size(); // Total Columns

        int l = 0;
        int h = (m * n) - 1; // Last index of flattened matrix

        // Fixed 4: Changed '<' to '<=' to check the single element case
        while(l <= h){
            // Fixed 1: Standard overflow-safe midpoint calculation
            int mid = l + (h - l) / 2; 
            
            // Fixed 2: Correctly converted 1D index back to 2D [row][col]
            int row = mid / m;
            int col = mid % m;
            int element = matrix[row][col]; 

            // Fixed 3: Compare target to the 'element', not the index 'mid'
            if(target == element){
                return true;
            }
            else if(target < element){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};


Leetcode 1901
// Function to find the index of the row 
      // with the maximum element in a given column
      int maxElement(vector<vector<int>>& arr, int col) {
          int n = arr.size();
          int max_val = INT_MIN;
          int index = -1;
  
          // Iterate through each row to find the maximum element 
          // in the particular column
          for (int i = 0; i < n; i++) {
              if (arr[i][col] > max_val) {
                  max_val = arr[i][col];
                  index = i;
              }
          }
          return index;
      }
  
      // Function to find a peak element in the 2D matrix 
      // using binary search
      vector<int> findPeakGrid(vector<vector<int>>& arr) {
          int n = arr.size();     
          int m = arr[0].size();  
  
          // Initialize the lower and upper bounds for binary search
          int low = 0;           
          int high = m - 1;      
  
          // Perform binary search on columns
          while (low <= high) {
              int mid = (low + high) / 2;
  
              // Find the index of the row with the maximum element 
              // in the middle column
              int row = maxElement(arr, mid);
  
              // Determine the elements to the left and right of 
              // the middle element in the found row
              int left = mid - 1 >= 0 ? arr[row][mid - 1] : INT_MIN;
              int right = mid + 1 < m ? arr[row][mid + 1] : INT_MIN;
  
              // Check if the middle element is greater than its neighbors
              if (arr[row][mid] > left && arr[row][mid] > right) {
                  return {row, mid};
              } 
              else if (left > arr[row][mid]) {
                  high = mid - 1;
              } 
              else {
                  low = mid + 1;
              }
          }
