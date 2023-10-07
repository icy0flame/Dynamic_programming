//Same as Fibonacci
#include <iostream>
#include<vector>
using namespace std;
int count_ways(int n,vector<int> dp){
    if(n<=2) return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
}
int main()
{
    int n;
    cout<<"Enter the number of steps : ";
    cin>>n;
    vector<int> dp(n+1,-1);
    
    cout<<count_ways(n,dp);

    
}
