/***
 * Author : Sunny Sutradhar
 * Date : 13/01/2022 
 ***/


#include<bits/stdc++.h>
using namespace std;
//Not completed
int makeInt(int cross,int add){
    return cross*10+add;
}
void solve(int a[],int lenA,int b[],int lenB){
     int i=0,j;
     int numA,numS;
     j= lenB-1;
     int ans[lenB],index=0;
     for(i=lenA-1;i>=0;i--){
        numA = a[i];
        numS = 0;
        while(j>=0){
            if(b[j]==0){
                int countZero = 1;
                while(1){
                   if(b[j]!=0)break;
                   countZero = makeInt(countZero,0);
                   j--;
                }
                numS = countZero+numS;
            }
            else
            {
                if(numS==0)numS = makeInt(numS,b[j]);
                else numS = makeInt(b[j],numS);
                j--;
            }
            if(numA<=numS){
                ans[index] = numS-numA;
                cout<<numS<<" - "<<numA<<endl;
                index++;
                break;
                
            }
        }
        //if(j<0 && i!=0)
       // //cout<<endl;

     }
     if(numA<=numS){
         index--;
         while(1){
            if(ans[index]!=0)break;
            index--;
         }
         for(int i=index;i>=0;i--){
            cout<<a[i];
         }cout<<index<<endl;
     }else{
        cout<<"-1"<<endl;
     }

}

void insertArr(int a[],int len,char *ch){
    for(int i=0;i<len;i++){
        a[i] = ch[i] - '0';
    }
}
void printArr(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        char a[100],s[100];
        int la=0,ls=0,arr[100],sum[100];
        cin>>a>>s;
        la = strlen(a);
        ls = strlen(s);
        insertArr(arr,la,a);
        //printArr(arr,la);
        insertArr(sum,ls,s);
        //printArr(sum,ls);
        solve(arr,la,sum,ls);
    }
}