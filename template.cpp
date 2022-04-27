/***
 * Author : Sunny Sutradhar
 * Date : 10/04/2022 
 ***/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
  ///ALL about stl
/*
  vector:begin(),end(),rbegin(),rend(),size(),empty(),front(),at(g),push_back(),pop_back(),insert()erase(),clear()
  list:front(),back(),push_front(g),push_back(g),pop_front(),pop_back(),begin(),end(),empty(),insert(),erase(),remove(),reverse(),size(),sort()
  Stack:empty(),size(),top(),push(g),pop()
  Queue:empty(),size(),swap(),emplace(),front()[retunr 1st element],back()[retunr last element],push(g),pop() 
  priority_queue:empty(),size(),top(),push(g),pop()
  map:begin(),end(),size(),empty(),pair insert(keyvalue, mapvalue),erase(iterator position),erase(const g),insert(),count(),find()[retunr iterator],

*/
  //vector itaration
/*

*/
  //priority queue indexing
/*
*/
  //pair access2
/*
    cout<<"("<<vec[i].first<<","<<vec[i].second<<")"<<" ";
    
*/
typedef char node_type;
#define east 0
#define west 2
#define north 3
#define south 1

ll abs(int a,int b){
   if(a>b){
      return a-b;
   }
   return b-a;
}

int main(){

    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      ll a[n],b[n],newA[n],newB[n],sum=0;

      for(int i=0;i<n;i++){
         cin>>a[i];
      }
      for(int i=0;i<n;i++){
         cin>>b[i];
      }
     
      for(int i=0;i<n;i++){
           if(a[i]>b[i]){
              newA[i] = a[i];
              newB[i] = b[i];
           }else{
             newB[i] = a[i];
             newA[i] = b[i];
           }
      }
      for(int i=1;i<n;i++){
         sum+= abs(newA[i-1],newA[i]) + abs(newB[i-1],newB[i]);
      }
      cout<<sum<<endl;
    }
   
 }  