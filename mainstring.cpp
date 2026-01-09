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
    return (c==4) ? sum:0;      //condition ? value_if_true : value_if_false  If divisor == 4, return sum, otherwise return 0
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


class Solution {
public:
    string reverseWords(string s) {
        //2 approaches are herre to solve this problem one using string stream and one is using simple intution step 1 first normally reverse the string then reverse each specific word again to get the desired result also make sure to minimise the spaces and gaps involved 

    reverse(s.begin(),s.end());

    int i=0;
    int l=0;
    int r=0;

    int n = s.size();

    while(i<n){
        while(i<n && s[i] != ' '){
            s[r++] = s[i++];
            //s[r] = s[i];   can be written like this 
            //r++;
            //i++;
        }
        if(l<r){
            reverse(s.begin()+l,s.begin()+r);
            s[r] = ' ';
            r++;
            l = r;
        }
        i++;
    }  
    s = s.substr(0,r-1);
    return s;
    }
};

//using string stream we make tokens we split the string into different parts using the space in between them them add them in vertor then again add them in a strong adding spaces between them excepting the last element

    stringstream ss(s);
    vector<string> words;
    string word;

    while(ss>>word){
        words.push_back(word);   //dividing each word and adding them into the vector so we can easily do the reverse
    }

    reverse(words.begin(),words.end());

    string ans = "";
    for(int i=0;i<words.size();i++){
        ans += words[i];  //adding each word 
        if(i != words.size()-1){ //this is used for adding the space aftereach words 
            ans += " ";
        }
    }
    return ans;
    }
};


//1975 leetcode
//we just have to see the count of negative numbers if it is even then we are sure the sum will be the same cause they will cancel out the negatives else as we have to return the max value sum we will find the min value of element from absolute and finally we will return sum - 2*mine;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int mine = INT_MAX;
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mine = min(mine,abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0){
                    count++;
                }
            }
        }
        if(count%2 == 0){
            return sum;
        }
        return sum - 2*mine;  //decrementing 2 times as the sum is getting 0 then negative
    }
};

//largest odd number in a string
//whenever we have to find the find the value in integer of a character we just have to substarct it with '0'
//in short to convert char to int we have to subaratct that char with '0'
//Subtracting '0' from a digit character converts it into its integer value due to ASCII encoding.
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2 != 0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};


//longest common prefix 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //brute in this we have to check the longest common prefix possible we will iterate form the first letter then we go till the end if we find the prefix as same we will keep on pushing it to the temp array and return that string 
        //2nd and most optimal approcah will be by sorting int his we are sorting the whole string and then comapring the first and last letter cause they will be the most dofferent one as the sorting happens lexicographically
        string ans = "";
        if(strs.empty()) return "";
        sort(strs.begin(),strs.end()); //sort the string
        string first = strs[0]; //first word
        string last = strs.back(); //strs[strs.size()-1] last 
        int len = min(first.size(), last.size());  //Comparing two strings → loop till min(lengths)
        for(int i=0;i<len;i++){
            if(first[i] != last[i]){
                break;
            }
            else{
                ans += first[i];
            }
        }
        return ans;
    }
};
