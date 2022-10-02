#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

//You Don't Know Who
bool isPrime[1000000+1];
void seive(int n){
    memset(isPrime,true,sizeof(isPrime));
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i+i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            cout<<i<<" ";
        }
    }
}

ull binarySearch(ull l,ull r,ull n){
      ull ans=1e18 + 1;

     ull mid=1;
      while(l<=r){
          // break;
           mid = (l+r)/2;
           ull tempSum = (mid*(mid+1))/2;
           //cout<<n<<" "<<mid<<" "<<l<<" "<<r<<endl;
           if(tempSum==n)return mid;
           else if(tempSum<n){
               //if(l==mid)return mid;
               //ans = min(ans,mid);
               l = mid+1;
           }else{
              //if(r==mid)return mid;
              r = mid-1;
              ans = mid;
           }

      }
     // cout<<ans<<endl;
      //if(((mid*(mid+1))/2)<n)return ans+1;
      return ans;
}


int main() {
  //  freopen("input.txt", "r", stdin);

    int t=10;
    cin>>t;
    while(t--){
        //cout<<"Hello"<<t<<endl;
        ull n,d;
        cin>>n>>d;
        ull ans = binarySearch(1,100000000000,n);
        //cout<<" = "<<ans<<endl;
        cout<<ans*d<<endl;
    }

    
     


}


