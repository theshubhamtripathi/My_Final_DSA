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


//When you use curly braces{}, you are telling the compiler to create a vector containing the specific values you've listed inside {} curly braaces .
