#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
      int n,index=0;
      cin>>n;
      char a[n+1],temp[n+1],dhori,r[n+1],max;
      cin>>a;
      dhori = a[0];
      max = dhori;
      temp[index++] = a[0];
      for(int i=1;i<n;i++){
         if(a[i]>dhori)break;
         else if(max==a[i])break;
         else{
            temp[index++] = a[i];
            dhori =a[i];
            if(a[i-1]>a[i])max = a[i-1];
         }
      }
      temp[index]='\0';
      
  int i;
  for(i = 0; i < index; i++) {
    r[i] = temp[index- 1 - i];
  }r[index] = '\0';
      
      
      cout<<temp;
      
      cout<<r<<endl;
   }
}