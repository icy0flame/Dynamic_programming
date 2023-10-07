#include <iostream>
#include<vector>
//for keyword absolute value
#include <cmath>
//For Keyword INT_MAX
#include <limits.h>
using namespace std;
int min_loss(vector<int> energy,int idx,vector<int> dp){
    
   if(idx==0)return 0;
  //if the value of that recursion call is already present then no need to call recursion further
    if(dp[idx]!=-1){
        return dp[idx];
    }else{
    int left=min_loss(energy,idx-1,dp)+abs(energy[idx]-energy[idx-1]);
    int right=INT_MAX;
    if(idx>1)
    right=min_loss(energy,idx-2,dp)+abs(energy[idx]-energy[idx-2]);
      // minimum of the left and right call
    if(left>right)
    return dp[idx]=right;
    else return dp[idx]=left;
}}
int main()
{   vector<int> energy;

    int n,x;
    cout<<"enter the number of elements : ";
    cin>>n;
    cout<<"enter the elements of the energy array : ";
    for(int i=0;i<n;i++)
    {cin>>x;energy.push_back(x);}
    vector<int> dp(n+1,-1);
    cout<<min_loss(energy,n-1,dp);
  
}
