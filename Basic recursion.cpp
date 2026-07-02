
Leetcode 8
class Solution {
public:
const int INT_MIN_VAL = -2147483648;
const int INT_MAX_VAL = 2147483647;

    // Recursive helper
int helper(const string &s, int i, long long num, int sign) {
    // If we are out of bounds means at last position or at a non-digit, return
    if (i >= s.size() || !isdigit(s[i]))
        return (int)(sign * num);

    // Update num with current digit
    num = num * 10 + (s[i] - '0');  //s[i] - '0' it gives the exact converted string to int using ascii value

    // Clamp if overflow
    if (sign * num <= INT_MIN_VAL) return INT_MIN_VAL;
    if (sign * num >= INT_MAX_VAL) return INT_MAX_VAL;

    // Recurse for next character
    return helper(s, i + 1, num, sign);
}

int myAtoi(string s, int i = 0) {
    // Skip leading whitespaces
    while (i < s.size() && s[i] == ' ') i++;

    // Handle sign
    int sign = 1;
    if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Call recursive helper
    return helper(s, i, 0, sign);
}
};

Leetcode 50
class Solution {
public:

    double solve(double x,long n){
        if(n == 0) return 1;
        if(n < 0) return solve(1/x,-n); //mandatoryly we have to use long here else out off bound issue is there 
        if(n%2 == 0) return solve(x*x,n/2);
        else return x*solve(x*x,(n-1)/2);
    }
    double myPow(double x, int n) {
        return solve(x,(long)n);
    }
};

to find total number of even indices in a array of n size it is (n+1)/2 while the odd one is just n/2
leetcode 1922
class Solution {
public:
    // Define the modulo constant as required by the problem statement (10^9 + 7)
    const int M = 1e9 + 7;

    // Recursive helper function for Binary Exponentiation O(log exp)
    long long power(long long base, long long exp){
        // Base Case: Any number raised to the power of 0 is 1
        if(exp == 0) return 1;
        
        // If the exponent is even: Transform base to (base^2) and cut exponent in half
        if(exp % 2 == 0) {
            return power((base * base) % M, exp / 2);
        }
        // If the exponent is odd: Pull one base out, and reduce the remaining exponent by 1/2
        else {
            return (base * power((base * base) % M, (exp - 1) / 2)) % M;
        }
    }

    int countGoodNumbers(long long n) {
        // Use long long to prevent integer overflow since n can be up to 10^15
        // Calculate total slots at even positions (0, 2, 4...) using ceiling division formula
        long long even = (n + 1) / 2;
        
        // Calculate total slots at odd positions (1, 3, 5...) using floor division formula
        long long odd = n / 2;

        // Calculate total combinations for even positions (5 choices: 0, 2, 4, 6, 8)
        long long ev = power(5, even);
        
        // Calculate total combinations for odd positions (4 choices: 2, 3, 5, 7)
        long long ov = power(4, odd);

        // Combine both choices using the slot multiplication rule and apply final modulo
        return (ev * ov) % M;
    }
};    
    
