#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;
int min_loss(vector<int> energy,int fs,vector<int> dp,int k){
    dp[0]=0;
    int t,min=INT_MAX;
    vector<int> temp(k,INT_MAX);
 //   if(dp[fs]!=-1)return dp[fs];
   // else{
        for(int i=1;i<=fs;i++){
            temp[0]=dp[i-1]+abs(energy[i-1]-energy[i]);
            if(i>1){
                if(i>k)t=k;
                else t=i;
                for(int j=2;j<=t;j++)
                temp[j-1]=dp[i-j]+abs(energy[i]-energy[i-j]);
            }
          
            for(int h=0;h<temp.size();h++){
                if(temp[h]<min){
                    min=temp[h];
                }
            }
            dp[i]=min;
           
            min=INT_MAX;
        }
        return dp[fs];
    
}
int main()
{
    int n,k,x,p;
    cout<<"enter the final stair number : ";
    cin>>k;
    cout<<"enter the number of elements of the energy array : ";
    cin>>n;
    vector<int> energy;
    cout<<"enter the upto how many stairs a frog can jump : ";
    cin>>p;
    cout<<"enter the elements of energy array : ";
    for(int i=0;i<n;i++)
    {cin>>x;energy.push_back(x);}
    vector<int> dp(n+1,-1);
    cout<<min_loss(energy,k-1,dp,p);

    
}
