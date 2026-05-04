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
