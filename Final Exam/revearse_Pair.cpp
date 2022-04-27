#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
typedef struct LinkedList node;


//complexity O(NlongN)

void marge(int a[],int l,int mid,int h){
   int temp[h-l+1];
   int i = l;
   int j = mid+1;
   int index=0;

   while(i<=mid && j<=h){
      if(a[i]<a[j]){
         temp[index++] = a[i++];
      }
      else {
          temp[index++] = a[j++];
      }

   }

   while(i<=mid)
        temp[index++] = a[i++];
   while(j<=h)
         temp[index++]=a[j++];

   index = 0;
   for(int i=l;i<=h;i++){
      a[i] = temp[index++];
   }
  // cout<<endl;

}



void divideAndConqure(int a[],int l,int h,int ans[]){
    if(l<h){
        int mid = (l+h)/2;
        divideAndConqure(a,l,mid,ans);
        divideAndConqure(a,mid+1,h,ans);
        int i=l;
        int j=mid+1;
        int counter = 0;

        while(i<=mid){
            if(j<=h && (a[i]>2*a[j])){
                counter++;
                j++;
            }else{
                ans[0] += counter;
               // cout<<ans[0]<<endl;
                //counter = 0;
                i++;

            }
        }
        marge(a,l,mid,h);

    }

}



int reversePairs(int a[],int n){
   int ans[1]={0};
   divideAndConqure(a,0,n-1,ans);
   return ans[0];
}

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cout<<reversePairs(a,n)<<endl;

}





//Reverse Pair Problem Complexity O(N^2)
 
// int count = 0;
//    for(int i=n-1;i>0;i--){
//        for(int j=i-1;j>=0;j--){
//           if(a[i]*2<a[j]){
//              count++;
//           }
//        }
//    }
//    cout<<count<<endl;