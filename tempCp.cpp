/***
 * Author : Sunny Sutradhar
 * Date : 30/01/2022 
 ***/
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        cout<<(a[i-1]^a[i])<<" ";
    }
    return 0;
}