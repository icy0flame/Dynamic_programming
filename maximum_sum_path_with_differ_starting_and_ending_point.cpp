#include <bits/stdc++.h> 
// int ways(int i,int j,int rows,int cols,vector<vector<int>> &vec,
// vector<vector<int>> &dp)
//     {
        
//         if(j<0||j>=cols)
//         return -1e8;
//         if(i==rows-1)return dp[i][j]=vec[rows-1][j];
//         if(dp[i][j]!=-1)return dp[i][j];
//         int r=vec[i][j]+ways(i+1,j,rows,cols,vec,dp);
//         int dg1=vec[i][j]+ways(i+1,j+1,rows,cols,vec,dp);
//         int dg2=vec[i][j]+ways(i+1,j-1,rows,cols,vec,dp);
       
//         return dp[i][j]=max(r,max(dg1,dg2));
//     }
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
      int n=matrix.size();
      int maxi=-1e8;
      int m=matrix[0].size();
       vector<vector<int>> dp(n,vector<int> (m,-1));
        
        // for(int i=0;i<m;i++)
        // {
           
        //     maxi=max(maxi,ways(0,i,n,m,matrix,dp));
            
        // }
        int r,dg1,dg2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0)dp[i][j]=matrix[i][j];
                else
                {  
                    
                    
                    r=matrix[i][j]+dp[i-1][j];
                   
                    if(j>0)
                    dg1=matrix[i][j]+dp[i-1][j-1];
                    else dg1=-1e8;
                    if(j<m-1)
                    dg2=matrix[i][j]+dp[i-1][j+1];
                    else dg2=-1e8;

                    dp[i][j]=max(r,max(dg1,dg2));
                }
            }
        }
       for(int j=0;j<m;j++)
       {
           maxi=max(maxi,dp[n-1][j]);
       }
    return maxi;
}
