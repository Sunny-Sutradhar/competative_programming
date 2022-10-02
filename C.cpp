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

//C

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
    
    for(char i='a';i<='z';i++){
        ch.insert({i,index});
        index++;
    }
    while(t--){
        int n,m;
        cin>>n>>m;
        string a[n],s1,s2;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int sum =0,min=1000000;
        for(int i=0;i<n-1;i++){
            s1 = a[i];
            for(int j = i+1;j<n;j++){
                s2 = a[j];
                //cout<<s1<<" "<<s2<<endl;
                sum = 0;
                for(int k=0;k<m;k++){
                  sum += abs(ch[s1[k]] ,ch[s2[k]]);
                  
                }
                if(sum<min)
                    min = sum;
                 //cout<<sum<<endl;

            }

        }
        cout<<min<<endl;
        

    }
}