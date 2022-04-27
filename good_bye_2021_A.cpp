#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int>&a,const pair<int,int>&b){
   return a.second<b.second;
}

int main(){
   int t;
   cin>>t;

   while(t--){
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++){
         cin>>a[i];
      }
      sort(a,a+n);
      int counter=1,check=0;
      int s = -111;
      for(int i=0;i<n;i++){
           
          if(s ==a[i]){
              a[i] = (-1)*s;  
          }else {
             s = a[i];
          }
      }
      set<int>se;
      for(int i=0;i<n;i++){
         //cout<<a[i]<<" ";
         se.insert(a[i]);
      }//cout<<endl;
      cout<<se.size()<<endl;

   }
}