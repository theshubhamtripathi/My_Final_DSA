//cp31 900 problem 3
//This solution wants answer in logn or 1 not even n so from this we can get the idea we have to use some mathmatical formula 
//just we have to implement one maths formula that is sum till n numbers that is n*(n-1)/2
//<bits/stdc++.h> this is used to import all libraraies at once 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        long long n,k,x;
        cin>>n>>k>>x;
        long long minsum = k*(k+1)/2;
        long long maxsum = n*(n+1)/2 - (n-k)*(n-k+1)/2;
        if(x>=minsum && x<=maxsum){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}


