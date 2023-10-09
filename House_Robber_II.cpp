#include <bits/stdc++.h>

 int max_robbery2(vector<int> arr,int n){
   
      int prev1=arr[0];
     int prev2=0;
    int  m2,m3,curr;
    for(int i=1;i<n;i++)
    {   if(i>1) m2=arr[i]+prev2;
        else m2=arr[i];
        m3=0+prev1;
         curr=max(m2,m3);
       prev2=prev1;
       prev1=curr;
    }
   return prev1;
    
} 
long long int houseRobber(vector<int>& valueInHouse)
{   int n=valueInHouse.size();
    if(n==1)return valueInHouse[0];
    vector<int> temp1;
    vector<int> temp2;
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        temp1.push_back(valueInHouse[i]);
        if(i!=n-1)
        temp2.push_back(valueInHouse[i]);

    }
    return max(max_robbery2(temp1,n-1),max_robbery2(temp2,n-1));
   
}
