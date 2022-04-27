#include<bits/stdc++.h>
using namespace std;

int position(int a[],int l,int h){
  int pivot = a[h]; // Let Considier last number as a pivot
    int i = l-1; 
    int j = h;
    while(i<j){  // Exchange the position
        do{
            i++;
        }while(a[i]>pivot);//Incriss I untill a[i]<=pivot
        do{
            j--;
        }while(a[j]<=pivot);//Dicriss J untill a[j]>pivot
        if(i<j){ //Exchange the elemnet in i nad j position
            int temp = a[i];
              a[i] = a[j];
              a[j] = temp;
        }
    }int temp = a[i];  //Exchange the element 
              a[i] = a[h];
              a[h] = temp;
    return i;

}


void quickSort(int a[],int l,int h){

    if(l<h){
        int pivot = position(a,l,h);
        quickSort(a,l,pivot-1);
        quickSort(a,pivot+1,h);
    }

}

int main(){
   int n;
   cin>>n;
   int a[n];

   for(int i=0;i<n;i++){
     cin>>a[i];
   }
   quickSort(a,0,n-1);
   for(int i=0;i<n;i++){
      cout<<a[i]<<" " ;
    }

}
