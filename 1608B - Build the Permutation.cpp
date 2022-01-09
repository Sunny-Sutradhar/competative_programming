#include<bits/stdc++.h>
using namespace std;


void print_array(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void initial_array(int a[],int n){
    for(int i=1;i<=n;i++){
        a[i-1] = i;
    }
    //cout<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
       int n,a,b,odd=1,even=2,total,per;
       cin>>n>>a>>b;
       int arr[n];
       total = n-2;
       per = total/2;
       if(total%2!=0)per++;
       if(a+b>total){
         cout<<-1<<endl;
       }
       else if(per<a || per<b){
         cout<<-1<<endl;
       }
       else if(a==0 && b==0){
           initial_array(arr,n);
           print_array(arr,n);

       }
       else if(abs(a-b)>1){
         cout<<-1<<endl;
       }
       else{
          initial_array(arr,n);
          if(a>b){
            for(int i=n-1;i>=0;i-=2){
                if(a==0)break;
                int temp = arr[i];
                    arr[i] = arr[i-1];
                    arr[i-1] = temp;
                    a--;
            }
          }
          else if(b>a){ 
            for(int i=0;i<n;i+=2){
                if(b==0)break;
                int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    b--;
            }
          }
          else{
              for(int i=0;i<n;i+=2){
                if(b==0)break;
                int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    b--;
            }
            int temp = arr[n-1];
                    arr[n-1] = arr[n-2];
                    arr[n-2] = temp;
                
          }

           print_array(arr,n);
        
       }

       
       

    }
}