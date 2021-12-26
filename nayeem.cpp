#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(long long int arr[], long long int n,long long int num)
{
  
    int i;
    set<long long int> s;
  
    for (i = 0; i < n; i++) {
  
        // insert into set
        s.insert(arr[i]);
    }
  
   set<long long int>::iterator it;
  
    // Print the array with duplicates removed
   //cout << "\nAfter removing duplicates:\n";
    i=0;
    for (it = s.begin(); it != s.end(); ++it)
    {  
           // i++;
            if(*it<=num)i++;
            
    }
  
    return i;
}

 int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,q,s,x,i,temp;
        long long int a[100000],index=0;
        cin>>n;
        x = 0;
        i = 2;
        a[index++]=1;
        temp = 2;
        while(1){
            //if(a[index-1]>1000000000)break;
            if(pow(i,2) <=n ){
               a[index++] = pow(i,2);
            }
            else break;
            if(pow(i,3)<=n){
               a[index++] = pow(i,3);
                //x++;
             }   
            i ++;
            //i = temp;

        }
        sort(a,a+index);
        cout<<removeDuplicates(a,index,n)<<endl;

    }
}