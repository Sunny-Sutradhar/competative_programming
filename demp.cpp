/***
 * Author : Sunny Sutradhar
 * Date : 10/04/2022 
 ***/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
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
      int index = n*4;
      bool cond = true;
      int a[index];
      for(int i=0;i<index;i++){
         cin>>a[i];
      }
      sort(a,a+index);
      for(int i=0;i<index-1;i+=2){
          if(a[i]!=a[i+1]){
             //cout<<a[i]<<" "<<a[i+1]<<endl;
             cond=false;
             break;
          }
      }
      if(cond){
        int j=index-2;
        for(int i=1;i<index/2;i++){
            if(a[0]*a[index-1] != a[i]*a[j]){
                cout<<"NO"<<endl;
                cond = false;
                break;
            }
            j--;
        }
        if(cond){
            cout<<"YES"<<endl;
        }
      }
      else{
        cout<<"NO"<<endl;
      }
   } 

      
   
 }  
