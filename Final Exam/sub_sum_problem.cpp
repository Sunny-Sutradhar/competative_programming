#include<bits/stdc++.h>
using namespace std;



int main(){
   int n;
   cin>>n;
   int a[n];

   for(int i=0;i<n;i++){
     cin>>a[i];
   }
   
   //this is in O(n) complexity
   int sum = a[0],maxSum = a[0],s=0,e=0;
   for(int i=1;i<n;i++){
        sum = max(sum+a[i],a[i]); 
        if(sum==a[i])s=i;  //using this we also find start index    
        if(maxSum<sum){
            e = i;
            maxSum = sum;
        }
   }
   cout<<maxSum<<endl;
   int tempSum = maxSum;

   //here i find the starting index;
   // for(s=e;;s--){
   //     tempSum-=a[s];
   //     if(tempSum==0)break;
   // }
   cout<<s<<" "<<e<<endl;

}

//Time Complexity O(n^2)

// int sum=a[0],maxSum=a[0],sIndex=0,eIndex=0;
//    for(int i=0;i<n;i++){
//        sum = 0;
//        for(int j=i;j<n;j++){
//           sum += a[j];
//           if(sum>=maxSum){
//                maxSum = sum;
//                sIndex = i;
//                eIndex = j;
//           }
//        }
//    }
//    cout<<maxSum<<" "<<sIndex<<" "<<eIndex<<endl;
