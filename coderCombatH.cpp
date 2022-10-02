#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;





int main() {
    //freopen("input.txt", "r", stdin);

    int t=10;
    cin>>t;
    while(t--){
       // break;
       string s;
       cin>>s;
       int n = s.size();
       // for(int i=0;i<n;i++){
          
       // }
       string a;
       a.push_back(s[0]);
       int index=1;
       int count = 1;
       int j=0;
       //cout<<s<<endl;
       //cout<<a<<endl;
       for(int i=1;i<n;i++){
        //  cout<<a<<" "<<j<<endl;
           if(j>=0 && a[j]==s[i]){
               if(j-1>=0 && a[j-1]==s[i]){
                  a.pop_back();
                  a.pop_back();
                  count = 1;
                  
                 // if(a[j]==a[j-1])count=2;
                  j = j-2;
                  
               }else{
                  //count++;
                  j++;
                  a.push_back(s[i]);
                  //index++;
                  
               }
           }else{
              // count = 1;
               j++;
               a.push_back(s[i]);
               //index++;
               //j++;
           }
       }
       //cout<<j<<endl;
    //   if(count==2){
    //      a.pop_back();
    //      a.pop_back();
    //   }
       //cout<<j<<endl;
       cout<<a<<endl;


    }

    //cout<<"Hello"<<t<<endl;
     


}


