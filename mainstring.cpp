// s.length() == s.size()   // always true both length and size same 

// char ch = 'a';
// Holds ONLY ONE character
// Uses single quotes ' '

// string s = "abc";
// Holds multiple characters
// Uses double quotes " "

// string sub = s.substr(start, length);
// string s = "abcdef";
// string sub = s.substr(2, 3);  // "cde"

//leetcode 961 2n array max element 
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        // int n = nums.size();
        // int chahiye = n/2;
        // unordered_map<int,int> mp;
        // for(auto it:nums){
        //     mp[it]++;
        // }
        // for(auto it:mp){
        //     int element = it.first;
        //     int freq = it.second;
        //     if(freq == chahiye){
        //         return element;
        //     }
        // }
        // return -1;

        // nums.back() It returns the value of the last element.
        // nums.end() Returns: iterator , Points to: after last element
        // nums.end() - 1 Returns: iterator to last element
        // *(nums.end() - 1) returns Value

        int n = nums.size();
        for(int i=2;i<n;i++){
            if(nums[i] == nums[i-1] || nums[i] == nums[i-2]){
                return nums[i];
            }
        }
        return nums.back();
    }
};

//remove outermost parentheses we created one coubter we keep on increasing it alsready said it is availd parenthesis now uderstand yourself 
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == ')'){
                count--;
            }
            if(count != 0){
                ans.push_back(s[i]);
            }
            if(s[i] == '('){
                count++;
            }
        }
        return ans;
    }
};


//four divisors 
class Solution {
public:
    int findsumdivisor(int num){
        int c = 0; //divisor count how many no. of divisior
        int sum = 0; //sum of divisors 

        for(int i=1;i*i<=num;i++){ //we didnt use sqrt beacuse it is expensive
        if(num%i == 0){
            int d1 = i;
            int d2 = num/i;
            if(d2 == d1){
                c += 1;
                sum += d1;
            }
            else{
                c += 2;
                sum += (d1 + d2);
            }
        }
        if(c>4){
            return 0;
        }
    }
    return (c==4) ? sum:0;
}
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int &num:nums){
            result += findsumdivisor(num);
        }
        return result;
    }
};


//reverse word in a string 
// stringstream is used to treat a string like an input/output stream, just like cin and cout.
// stringstream ss(string_name); and then ss >> variable;
//stringstream is used to parse a string just like input stream, useful for splitting strings and converting data types.



