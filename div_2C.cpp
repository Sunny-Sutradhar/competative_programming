#include<bits/stdc++.h>
using namespace std;
typedef long long ull;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,index=0;
        ull k,sum=0;
        cin>>n>>k;
        ull a[n],step=0,chaker=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        index = n-1;
        sort(a,a+n);
        //
        //cout<<"sum "<<sum<<endl;
        //ccc
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<" ";
        // }cout<<endl;

        if(sum<=k)cout<<0<<endl;
        else{
           for(int i=0;i<n-1;i++){
              if(a[i]<a[index]){
                if(sum-1 <= k){
                    step++;
                    chaker = 1;
                    break;
                }
                sum -= (a[index]-a[0]);
                //cout<<"sum "<<sum<<endl;
                a[index] = a[0];
                step++;
                index--;
               // cout<<"this is in if"<<endl;
                if(sum<=k){
                    chaker = 1;
                    break;
                }
              }
                
              else break;
           } 
        }
        if(chaker==1){
            cout<<step<<endl;
        }
        else{
            //cout<<sum<<endl;
            //cout<<k<<endl;
            step += (sum-k);
            cout<<"Hrer "<<step<<endl;
        }
        

    }
}