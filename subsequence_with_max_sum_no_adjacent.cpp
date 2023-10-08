// maximum subsequences problem with no adjacent elements 
#include <iostream>
#include<vector>
using namespace std;
int max_subsequence(vector<int> vec,int n){
    //maan lo index 0 hogyaa mtlb usne index 1 nhi liyaa so index 0 waala value return krr denge
    //n=size-1
    if(n==0)return vec[n];
    //yahaa n-2 krr rhee hai maan lo n 1 hua too f of minus 1 call ho jayegaa so ek orr condition lgegaa
    if(n<0)return 0;
    int pick=vec[n]+max_subsequence(vec,n-2);
    int not_pick=0+max_subsequence(vec,n-1);
    if(pick>not_pick)return pick;
    else return not_pick;
}
int main()
{
   int n;
   cout<<"enter the size of the array : ";
   cin>>n;
   vector<int> vec;
   int x;
   cout<<"enter the elements of the array : ";
   for(int i=0;i<n;i++){
       cin>>x;
       vec.push_back(x);
   }
   cout<<max_subsequence(vec,n-1);
    return 0;
}


