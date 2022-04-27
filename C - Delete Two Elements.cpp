/***
 * Author : Sunny Sutradhar
 * Date : 09/01/2022 
 ***/


#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       long long int a[n],sum=0,find,counter;
       double avg;
       std::map<long long int, int> map;
       for(int i=0;i<n;i++){
          cin>>a[i];
          sum+=a[i];
          map.insert({a[i],0});
       }
       for(int i=0;i<n;i++){
         map[a[i]]++;
       }
      
       if((2*sum)%n!=0){
         cout<<"0"<<endl;
       }
       else{
         find = 2*sum/n ;
         counter = 0;
         for(int i=0;i<n;i++){
             auto it = map.find(find - a[i]);
             if(it != map.end()){
                counter += it->second; 
               if(find-a[i] == a[i])counter--;
             }
             map[a[i]] --;            
         }
         cout<<counter<<endl;
          
       }
 
 
 
    }
}