/***
 * Author : Sunny Sutradhar
 * Date : 10/01/2022 
 ***/


#include<bits/stdc++.h>
using namespace std;

void LCS(char *X, char *Y ){
    int m = strlen(X);
    int n = strlen(Y);
    int L[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                L[i][j] = 0;
            else if(X[i]==Y[j])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i][j-1],L[i-1][j]);
        }
    }
   // cout<<L[m][n]<<endl;
    char LCS[L[m][n]];
    LCS[L[m][n]] = '\0';
    int index = L[m][n]-1;
    int i=m,j=n;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
          LCS[index] = X[i-1];
          index--;
          i--;
          j--;
        }
        else if(L[i][j-1]<L[i-1][j])
            i--;
        else 
            j--;
    }
    cout<<LCS<<endl;


}


int main(){
    char X[]="ABCBDAB";
    char Y[]="BDCABA";

    LCS(X,Y);
}