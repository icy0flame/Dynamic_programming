//grid sum with dynamic programming 
#include<iostream>
#include<vector>
using namespace std;

int all_ways(int end_row,int end_column,vector<vector<int>> arr,vector<vector<int>> dp){
    if(end_column==0&&end_row==0)return 1;
    if(end_column<0||end_row<0) return 0;
    if(dp[end_row][end_column]!=-1)return dp[end_row][end_column];
    int right=all_ways(end_row,end_column-1,arr,dp);
    int down=all_ways(end_row-1,end_column,arr,dp);
    return dp[end_row][end_column]=right+down;
}
int main(){
    int n,m;
    cout<<"enter the number of rows : ";
    cin>>n;
    cout<<"enter the number of columns : ";
    cin>>m;
    vector<vector<int>> arr(n);
    vector<vector<int>> dp(n,vector<int> (m,-1));
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            arr[i].push_back(x);
        }
    }
    // cout<<all_ways(0,0,n-1,m-1,arr);
    cout<<all_ways(n-1,m-1,arr,dp);
    
}
