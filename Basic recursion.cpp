What is recursion ? When a fuction calls itself until a specified condition is met(base condition).
First the main function gets called.
 #include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void print() {
    if (cnt == 3) return; //base condition
    
    cout << cnt << endl;
    cnt++;
    print();
}

int main() {
    print();
    return 0;
}
    //if we dont give a base condiition then it will go for infinite loop resulting in stack overflow and fillfulment of stack memory.
Printing name till n times
#include <bits/stdc++.h>
using namespace std;

void print(int i,int n) {
    if (i>n) return; //base condition
    cout <<"st"<< endl;
    print(i+1,n);
}

int main() {
    int n;
    cin>>n;
    print(1,n);
    return 0;
}

Print linearly from 1 to n
#include <bits/stdc++.h>
using namespace std;

void print(int i,int n) {
    if (i>n) return; //base condition
    cout <<i<< endl;
    print(i+1,n);
}

int main() {
    int n;
    cin>>n;
    print(1,n);
    return 0;
}

Print linearly from n to 1
#include <bits/stdc++.h>
using namespace std;

void print(int n) {
    if (n==0) return; //base condition
    cout<<n<<endl;
    print(n-1);
}

int main() {
    int n;
    cin>>n;
    print(n);
    return 0;
}
//by back tracking
#include <bits/stdc++.h>
using namespace std;

void print(int i, int n) {
    if (i > n) return;
    
    print(i + 1, n);
    cout << i << endl;
}

int main() {
    int n;
    cin >> n;
    print(1, n);
    return 0;
}
//Right now, your code prints n before it calls the next function (Forward Tracking).
What if an interviewer challenges you to print from 1 to n, but gives you a strict rule: You are NOT allowed to use i+1 or addition anywhere in the function parameters?
You solve that by printing after the recursive call. Here is how that look-behind execution works:
#include <bits/stdc++.h>
using namespace std;

void print(int n) {
    if (n == 0) return;
    
    print(n - 1);
    cout << n << endl;
}

int main() {
    int n;
    cin >> n;
    print(n);
    return 0;
}
Notice how this prints 1 to n even though we are subtracting n - 1? This happens because the cout statement waits on the call stack until the recursion hits 0, and then prints as the stack unfolds backwards.

 //parameterised recursion sum of n numbers from 1
#include <bits/stdc++.h>
using namespace std;

void func(int i, int sum) {
    if (i < 1) {
        cout << sum << endl;
        return;
    }
    func(i - 1, sum + i);
}

int main() {
    func(3, 0);
    return 0;
}
//in functional recursion you want the function you give you something and that is use in dp
//Same question using functional recursion
//In parametericed the parametres are passed and in functional direct n that is we use the function only 
#include <bits/stdc++.h>
using namespace std;

int func(int n) {
    if (n == 0) return 0;
    return n + func(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << func(n) << endl;
    return 0;
}

// Factorial of a number n
#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
    // Base case: 0! is 1, and 1! is 1
    if (n <= 1) {
        return 1;
    }
    // Recursive case
    return n * fact(n - 1);
}

int main() {
    int n;
    cin >> n;
    
    // Fixed: Added cout to actually display the result
    cout << fact(n) << endl; 
    
    return 0;
}

// Functional recursion example 
// Reverse an array using recursion (2 pointers)
#include <bits/stdc++.h>
using namespace std;

// Fixed: Passed the vector by reference (&a) so the function can modify it
void func(int l, int r, vector<int> &a) {
    if (l >= r) {
        return;
    }
    swap(a[l], a[r]);
    
    // Fixed: Changed 'i' to 'l' and fixed the semicolon to a comma
    func(l + 1, r - 1, a); 
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int l = 0;
    int r = n - 1;
    
    // Fixed: Passed 'a' into the function
    func(l, r, a);
    
    // Added: Print the reversed array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

// Reversing an array using functional recursion (Single Pointer)
#include <bits/stdc++.h>
using namespace std;

void func(int i, vector<int> &a) {
    int n = a.size();
    
    // Base case: Stop when we reach or cross the middle of the array
    if (i >= n / 2) {
        return;
    }
    
    // Swap the current element with its mirror element on the right side
    swap(a[i], a[n - i - 1]);
    
    // Recursive call: Move to the next index
    func(i + 1, a); 
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Start recursion from index 0
    func(0, a);
    
    // Print the reversed array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

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
    
