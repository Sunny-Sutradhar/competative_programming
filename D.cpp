/*********************
 *   Sunny Sutradhar *
 *     10/05/2022    *
 *********************/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;

//D

int abs(int a,int b){
    if(a>b){
        return a-b;
    }
    return b-a;
}

int main(){
    int t;
    cin>>t;
    map<char, int> ch;
    int index = 1;
    
    
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }

        ll sum=0,max=0;
        int k,l;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum = a[i][j];
                k = i+1;l=j+1;
                while(k<n && l<m){
                    sum+=a[k][l];
                    k++;l++;
                }
                k = i-1;l=j-1;
                while(k>=0 && l>=0){
                    sum+=a[k][l];
                    k--;l--;
                }
                k = i-1;l=j+1;
                while(k>=0 && l<m){
                    sum+=a[k][l];
                    k--;l++;
                }
                k = i+1;l=j-1;
                while(k<n && l>=0){
                    sum+=a[k][l];
                    k++;l--;
                }
                //cout<<sum<<endl;
                if(sum>max)
                max = sum;
            }

        }
        cout<<max<<endl;
    }
}