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

leetcode 88
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
