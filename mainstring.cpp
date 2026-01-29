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

//isomorphic string 
//in this question we just created 2 maps and comapred the each char maps if mapping is found but the mapping is wrong or it is mapped to a different char return false else store the map ad retrun true 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        int n = s.size();
        for(int i=0;i<n;i++){
            char s1 = s[i];
            char t1 = t[i];

            if(mp1.find(s1) != mp1.end() && mp1[s1] != t1 ||
            mp2.find(t1) != mp2.end() && mp2[t1] != s1){
                return false;
            }
            mp1[s1] = t1;
            mp2[t1] = s1;
        }
        return true;
    }
};

//array ke left rotate me ek temp array banake temp[(i+k)%n] = nums[i]
//right rotate me ek temp array banake temp[(i-k+n)%n] = nums[i] karna hota hai
class Solution {
public:
    bool rotateString(string s, string goal) {
        // int n = s.size();
        // if(s.size() != goal.size()) return false;

        // for(int k=0;k<n;k++){
        //     string temp(n,' ');
        //     for(int i=0;i<n;i++){
        //         temp[(i+k)%n] = s[i];
        //     }
        //     if(goal == temp) return true;
        // }
        // return false;

        //using stl rotate we use it like this rotate(s.begin()(straying position),s.begin()+k(which position will tell the starting position of the string),s.end()(ending position))
        // int n = s.size();
        // for(int i=0;i<n;i++){
        //     rotate(s.begin(),s.begin()+1,s.end());
        //     if(s==goal){
        //         return true;
        //     }
        // }
        // return false;

        //approach 3 we will use one property of strings that if we add 2 same strings together then we will get all the rotations as a substrings in it
        //string::npos is a special value that tells us a substring does NOT exist in a string.
        int n = s.size();
        int m = goal.size();

        if(n != m) return false;

        if((s+s).find(goal) != string::npos){
            return true;
        }
        return false;
    }
};
    //ch - 'a' converts a lowercase character into a 0-based index so we can store and access data easily.
    //approach 4
    vector<int> count(26,0);
        for(auto it:s){
            count[it-'a']++;
        }
        for(auto it:t){
            count[it-'a']--;
        }
        for(int i=0;i<count.size();i++){
            if(count[i] != 0){
                return false;
            }
        }
        return true;
//very fast lookup better than map[ but if unicode one comes thes use map more easy 


//leetcode 451 sort charracter by freq
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto it : s){
            mp[it]++;
        }
        vector<pair<char,int>> a;
        for(auto it:mp){
            a.push_back({it.first,it.second});
        }
        auto lambda = [](pair<char,int>& p1, pair<char,int>& p2){
            return p1.second>p2.second;
        };
        sort(a.begin(),a.end(),lambda);
        
        string ans = "";
        for(int i=0;i<a.size();i++){
            while(a[i].second--){
                ans += a[i].first;
            }
        }
        return ans;

        //main concept here is vector of pair 

    }
};

//same question by using heaps 

//leetcode 1614
class Solution {
public:
    int maxDepth(string s) {
        int maxnested = 0;
        int count = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                count++;
            }
            else if(s[i] == ')'){
                count--;
            }
            maxnested = max(count,maxnested);  //compare the number of count and maxnested and return what is max also as above it increases adter every opening bracket and decrrwasing after evevry closing bracket
        }
        return maxnested;
    }
};

//leetcode 12 
class Solution {
public:
    vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> sym = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) {
        string r = "";
        for(int i=0;i<13;i++){
            if(num == 0) break;
            int times = num/val[i];
            while(times--){
                r += sym[i];
            }
            num %= val[i];
        }
        return r;
    }
};

//leetcode 13
class Solution {
public:
    int romanToInt(string s) {
        // int n = s.size();
        // int count = 0;

        // for(int i=0;i<n;i++){

        //     if(s[i] == 'I'){
        //         if(i+1 < n && (s[i+1] == 'V' || s[i+1] == 'X')){
        //             count -= 1;   // subtraction case
        //         }
        //         else{
        //             count += 1;
        //         }
        //     }

        //     else if(s[i] == 'V'){
        //         count += 5;
        //     }

        //     else if(s[i] == 'X'){
        //         if(i+1 < n && (s[i+1] == 'L' || s[i+1] == 'C')){
        //             count -= 10;
        //         }
        //         else{
        //             count += 10;
        //         }
        //     }

        //     else if(s[i] == 'L'){
        //         count += 50;
        //     }

        //     else if(s[i] == 'C'){
        //         if(i+1 < n && (s[i+1] == 'D' || s[i+1] == 'M')){
        //             count -= 100;
        //         }
        //         else{
        //             count += 100;
        //         }
        //     }

        //     else if(s[i] == 'D'){
        //         count += 500;
        //     }

        //     else if(s[i] == 'M'){
        //         count += 1000;
        //     }
        // }

        // return count;{

        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;

        int count = 0;

        for(int i=0;i<s.size();i++){

            if(i+1 < s.size() && mp[s[i]] < mp[s[i+1]]){
                count -= mp[s[i]];
            }
            else{
                count += mp[s[i]];
            }
        }

        return count;
    }
};


//atoi function 
//ASCII to Integer : It converts a string number into an integer.
//now we use stoi to convert a string to integer 

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int l = s.size();
        //leading whitespace
        while(i<l && isspace(s[i])){
            i++;
        }
        //nothing more present in between
        if(i==l){
            return 0;
        }
        //check for sign
        bool neg = false;
        if(s[i] == '-'){
            neg = true;
            //move to next
            i++;
        }
        else if(s[i] == '+'){
            //move to next
            i++;
        }
        else if(!isdigit(s[i])){
            return 0;
        }
        if(i==l){
            return 0;
        }
        //extract num and return int value 
        int value = 0;
        int max = INT_MAX/10;
        int min = INT_MIN/10;
        while(i<l && isdigit(s[i])){
            int digit = s[i] - '0'; //if we minus be the any string by ascii of 0 it return the value of that number
            if(value>max){
                return INT_MAX;
            }
            else if(value == max && digit>7){
                return INT_MAX;
            }
            if(value<min){
                return INT_MIN;
            }
            else if(value == min && digit>8){
                return INT_MIN;
            }
            //if this is the negative number
            if(neg){
                value = value*10 + (-digit);
            }
            //if this is the positive number
            else{
                value = value*10 + digit;
            }
            i++;
        }
        return value;
    }
};
