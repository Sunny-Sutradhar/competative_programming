#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        long long int a[n],sum=0,avg,count;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        avg = sum/n;
        count = avg*n;
        count  = sum -(count);
        if(count==0)cout<<0<<endl;
        else{
            for(int i=0;i<n;i++){
                if(a[i]==avg)count--;
            }
            if(count>=0)cout<<count<<endl;
            else cout<<1<<endl;
        }



    }
}