#include<iostream>
#include<vector>
using namespace std;
// int all_ways(int start_row,int start_column,int end_row,int end_column,vector<vector<int>> arr){
    
    
//         if(start_row==end_row&&start_column==end_column)
//         return 1;
//         if(start_row>end_row||start_column>end_column)
//         return 0;
    
//     int x=all_ways( start_row+1,start_column,end_row,end_column,arr);
//     int y=all_ways(start_row,start_column+1,end_row,end_column,arr);
//     return x+y;
// }
int all_ways(int end_row,int end_column,vector<vector<int>> arr){
    if(end_column==0&&end_row==0)return 1;
    if(end_column<0||end_row<0) return 0;
    int right=all_ways(end_row,end_column-1,arr);
    int down=all_ways(end_row-1,end_column,arr);
    return right+down;
}
int main(){
    int n,m;
    cout<<"enter the number of rows : ";
    cin>>n;
    cout<<"enter the number of columns : ";
    cin>>m;
    vector<vector<int>> arr(n);
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            arr[i].push_back(x);
        }
    }
    // cout<<all_ways(0,0,n-1,m-1,arr);
    cout<<all_ways(n-1,m-1,arr);
    
}
