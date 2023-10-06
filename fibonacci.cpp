#include <iostream>
#include<vector>
using namespace std;
int fibo(int n,vector<int> dp){
    if(n<=1) return n;
  // if dp at node n stores value means we have already calculate that part of tree no need to calculate 
    if(dp[n]!=-1)return dp[n];
  //storing in dp array
    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
}
int main()
{
    int n;
    cout<<"Enter the number you want to find the fibonacci : ";
    cin>>n;
  //declaring the dp array with -1 means there is no value storing
    vector<int> dp(n+1,-1);
    
    cout<<fibo(n,dp);

    
}
