#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    int m[n][n]={0};
    int s[n][n]={0};
    int j,min,q;

    for(int d=2;d<n;d++){
        for(int i=1;i<n-d+1;i++){
            j = i+d-1;
            m[i][j] = INT_MAX;
            for(int k=i;k<=j-1;k++){
                q=m[i][k] + m[k+1][j]+(p[i-1]*p[k]*p[j]);
               if(q<m[i][j]){
                  m[i][j] =q;
                  s[i][j] = k;
               }
            }
            //m[i][j] = min;
        }

    }
    cout<<m[1][n-1];

    return 0;
}