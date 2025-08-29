// Sieve of erathonese : print prime numbers till n with a efficient time complexity of nloglog(n). spcae complexity of o(n)
// #include<iostream>
// #include<cmath>
// using namespace std;
// int Sieve(int n){
//     bool arr[n+1];
//     for(int i=0;i<=n;i++){
//         arr[i]=true;
//     }
//     for(int i=2;i<=sqrt(n);i++){
//         if(arr[i]==true)
//         for(int j=i*i;j<=n;j+=i){
//             arr[j]=false;
//         }
//     }
//     for(int i=2;i<=n;i++){
//         if(arr[i]==true){
//         cout<<i<<endl;
//         }
//     }
//     int count = 0;
//     cout<<"Total number of primes are : ";
//     for(int i=2;i<=n;i++){
//         if(arr[i]==true){
//             count ++;
//         }
//     }
//     cout<<count;
//     return 0;
// }
// int main(){
//     int n;
//     cin>>n;
//     Sieve(n);
//     return 0;
// }

//Now we will write the code for a ranged sieve or segmented sieve they find rpime number in a range 
// Eulers phi , case1:if output is prime then n-1 case 2:if composite n (n)=p*q op:p and q must be prime then it will be (p-1)*(q-1) case3:composite number factor also composite number their factor will be cube or square of the factor also depends on the number we are giving  
// #include<iostream>
// using namespace std;
// int gcd(int a,int b){
//     if(a==0){
//         return b;
//     }
//     return gcd(b%a,a);
// }
// int getCoprime(int n){
//     int count = 0;
//     for(int i=0;i<=n;i++){
//         if(gcd(i,n)==1){
//             count++;
//         }
//     }
//     return count;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<getCoprime(n);
//     return 0;
// }

//here i is for printing rows and j for coumn in general for patern prnting and also i nothing prints it just make the code move to next line 
// #include<iostream>
// using namespace std;
// void seeding(int n) {
// 	for(int i=0;i<=n;i++){
// 		for(int j=0;j<=i;j++){
// 			cout<<" ";
//         }
//         for(int k=1;k<=2*(n-i)+1;k++){
//                 cout<<"*";
//         }
//         for(int j=0;j<=i;j++){
// 			cout<<" ";
// 		}
// 		cout<<endl;
	
// }
// }
// int main(){
// 	int n;
// 	cin>>n;
// 	seeding(n);
// 	return 0;
// }

// #include<iostream>
// using namespace std;
// void pattern(int n){
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=n-i;j++){
//             cout<<" ";
//         }
//         for(int k=1;k<=2*i+1;k++){
//             cout<<"*";
//         }
//         for(int j=0;j<=n-i;j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<" ";
//         }
//         for(int j=1;j<=2*(n-i)+1;j++){
//             cout<<"*";
//         }
//         for(int j=0;j<=i;j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// }
// int main (){
//     int n;
//     cin>>n;
//     pattern(n);
//     return 0;
// }

//hour glass
// #include<iostream>
// #include<vector>
// using namespace std;
// int hourGlass(vector<vector<int>> arr,int row,int col){
//     int maxg = INT_MIN;
//     for(int i=0;i<=row-3;i++){
//         for(int j=0;j<=col-3;j++){
//             int sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
//             maxg = max(maxg,sum);
//         }
//     }
//     return maxg;
// }
// int main(){
//     int row,col;
//     cin>>row;
//     cin>>col;
//     if(row<3||col<3){
//         cout<<"Cant be accepted";
//         return 0;
//     }
//     vector<vector<int>> arr(row,vector<int>(col));
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             cin>>arr[i][j];
//         }
//     }
//     cout<<hourGlass(arr,row,col);
//     return 0;
// }

//whenever we get a array and some condititons are given so use longest subsequence using dynamic programming in that case
//strobogramatic number 


//maximum equilibrium sum
// #include<iostream>
// using namespace std;
// int Equilibrium_max_sum(int arr[],int n){
//     int total = 0;
//     int left = 0;
//     for(int i=0;i<=n;i++){
//         total = total + arr[i];
//     }
//     for(int i=0;i<=n;i++){
//         int right = total - left - arr[i];
//         left = left + arr[i];
//     }
//     return left;
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<=n;i++){
//         cin>>arr[i];
//     }
//     cout<<Equilibrium_max_sum(arr,n);
//     return 0;
// }

//monkey and door
// #include<iostream>
// using namespace std;
// void check(bool arr[],int n) {
//     for(int i=1;i<=n+1;i++){
//         arr[i]=false;
//     }
//     for(int i=1;i<=n+1;i++){
//         for(int j=i;j<=n;j+=i){
//             if(arr[j]==false){
//                 arr[j]=true;
//             }
//             else{
//                 arr[j]=false;
//             }
//         }
//     }
//     int count = 0;
//     for(int i=1;i<=n+1;i++){
//         if(arr[i]==true){
//             count++;
//         }
//     }
//     cout<<"Total number of open door : "<<count;
// }
// int main(){
//     bool arr[101];
//     int n;
//     cin>>n;
//     check(arr,n);
//     return 0;
// }

//Max product subarray
// #include<iostream>
// #include<vector>
// using namespace std;
// int max_product_subarray(vector<int> s){
//     int n = s.size();
//     int result = INT_MIN;
//     for(int i=0;i<n;i++){
//         int product = 1;
//         for(int j=i;j<n;j++){
//             product *= s[j]; 
//             result = max(product,result);
//         }
//     }
//     return result;
// }
// int main(){
//     vector<int> s ={0,0,0,0};
//     cout<<max_product_subarray(s);
//     return 0;
// }

//things from striver stl till now first s.end() it points to the elements just ater the last element s.back() points the last element and when we give range for example s.begin() to s.begin()+2 so the it will only point till s.begin+1 it will not point at the last index given.
//set for unique and ordered , unordered set for unique and unordered , vector like a dynamic array vairious functions uk it maintain a singly linked list, list maintains a doubly linked list very similar to vector more efficient front operation .
//deque also pretty same 
//stack lifo .push() to enter .top() .pop()removes the top element the top element .
//queue fifo .push() .front() the first element .back() the last element and at last here .pop()deltes the first element
//both stack and queie operation happens at tc pf O(1)
//priority queue the didgit or element with higherst value stay ta the top also known as max heap 
//.top() .pop() both reperesent the higherst value elements also inside it maintains a tree data sturcture 
//.insert() for inserting 
//to create a priority queue which stores the min value at the top give synatax something like that priority_queue<int, vector<int>, greater<int>> pq also known as min heap if we use .pop() or .top() it always return the min elememt in this case.
//set are sorted and unique also it maintains a tree also here is find is there where we can find if the element is present or not 
//multiset Allows multiple instances of the same element—duplicates are allowed and counted Keeps track of how many times each element appears (called the “multiplicity”).
//maps are more like dictionary in python they are lke in combinanation they have key and value pairs map<int ,int> m we can also write in this format map<pair<int,int>, int> m it is also stored in a sorted order of keys more like sets . multimap similar to multi set duplicated alowed
//unordered amps dont store in sorted order they are randomised but dont store duplicate elements .
// sort mainly sort the things in a respective order sort(v.begin(),v.end()) this will sort in acending order to sort in decdnding order use sort(a, a+n, greater<int>); here a is the start index a+n is the ending index and for any dcedneodng we must use greater
//max and min 

// majority elemenet in an array
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             int count = 0;
//             for(int j=0;j<n;j++){
//                 if(nums[i]==nums[j]){
//                     count ++;
//                 }
//             }
//             if(count > n/2){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };

//Binary palindrome

//Leaders in the array 

//Alice apple tree

//Swap the nibble in a byte

//karastuba

//longest sequence after flipping the bit 

//joesephus 

//The ceil() function returns the smallest integer value that is greater than or equal to the given floating-point number. ceil(4.3) returns 5.0, ceil(7.0) returns 7.0, and ceil(-2.7) returns -2.0.ceil iike chat so the higher value we will take 

//The floor() function returns the largest integer value that is less than or equal to the given floating-point number. floor(4.3) returns 4.0, floor(7.0) returns 7.0, and floor(-2.7) returns -3.0.floor like zameen so lower value 





 
