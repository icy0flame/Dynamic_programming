// TIME complexity of below both code is O(n)
//SPACE COMPLEXITY of below code is O(1)

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

// below code do it in space complexity O(1)

#include <iostream>
#include<vector>
#include <cmath>
#include <limits.h>
using namespace std;
int min_loss(vector<int> energy,int idx,vector<int> dp){
    dp[0]=0;
    for(int i=1;i<energy.size();i++){
        int left=dp[i-1]+abs(energy[i-1]-energy[i]);
        int right=INT_MAX;
        if(i>1)
         right=dp[i-2]+abs(energy[i-2]-energy[i]);
        if(left>right) dp[i]=right;
        else dp[i]=left;
    }
    return dp[idx];

}
int main()
{   vector<int> energy;

    int n,x,k;
    cout<<"enter the kth stair u want to reach ; ";
    cin>>k;
    cout<<"enter the number of elements : ";
    cin>>n;
    cout<<"enter the elements of the energy array : ";
    for(int i=0;i<n;i++)
    {cin>>x;energy.push_back(x);}
    vector<int> dp(n+1,-1);
    cout<<min_loss(energy,k-1,dp);
  
}
