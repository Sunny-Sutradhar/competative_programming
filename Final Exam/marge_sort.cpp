#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void marge(int a[],int l,int m,int h){
     int leftArraySize;
     int rightArraySize;
     leftArraySize = m-l+1;
     rightArraySize = h-m;
     int L[leftArraySize];
     int R[rightArraySize];

     for(int i=0;i<leftArraySize;i++){
        L[i] = a[l+i];
     }

     for(int i=0;i<rightArraySize;i++){
        R[i] = a[m+1+i];
     }
     int i=0,j=0,k=l;
     while(i<leftArraySize && j<rightArraySize){
        if(L[i]<=R[j]){
           a[k++] = L[i++];
           
        }else{
            a[k++] = R[j++];
        }
     }

     while(i<leftArraySize){
        a[k++] = L[i++];
     }
     while(j<rightArraySize){
        a[k++] = R[j++];
     }
}


void marzeSort(int a[],int l,int h){
     if(l<h){
         int mid = l + (h-l)/2;
         marzeSort(a,l,mid);
         marzeSort(a,mid+1,h);
         marge(a,l,mid,h);
     }
}



int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    marzeSort(a,0,n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
}