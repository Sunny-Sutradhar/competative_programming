#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
    int t;
    cin>>t;

    while(t--){
        int x,y,n,w,wight;
        double p1,p2,totalP,finalP=0; 
        cin>>x>>y>>n>>w;
        cin>>p1>>p2;
        int takeX,takeY;
        p1/=100.0;
        p2/=100.0;
        double a[n+1][w+1];
        for (int i=0;i<=n;i++) 
            a[i][0] = 1; 
        for (int i=1;i<=w;i++) 
            a[0][i] = 0; 
        for (int i=1;i<=n;i++){ 
            for (int j=1;j<=w;j++) { 
                a[i][j] = max(p1*a[i-1][max(j-x,0)] + (1-p1)*a[i-1][max(j,0)],
                              p2*a[i-1][max(j-y,0)] + (1-p2)*a[i-1][max(j,0)]); 
            } 
        }
        totalP = a[n][w]*100;
        printf("%.6f\n",totalP);
       
    }


    return 0;
}

 
 