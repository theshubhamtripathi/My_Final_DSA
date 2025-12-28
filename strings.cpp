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
