#include<bits/stdc++.h>
using namespace std;

int totalSumOfArray(int a[],int l,int mid,int h){
	int leftSum = INT_MIN;
	int rightSum = INT_MIN;
    int sum=0;
	for(int i=l;i<=mid;i++){
		sum+=a[i];
		if(sum>leftSum)leftSum=sum;
	}
	sum = 0;
	for(int i=mid+1;i<=h;i++){
        sum += a[i];
        if(rightSum<sum)rightSum =a[i];
	}
	return leftSum+rightSum;
}

int maximum(int a, int b, int c)
{
  if (a>=b && a>=c)
    return a;
  else if (b>=a && b>=c)
    return b;
  return c;
}
int findMaxSum(int a[],int l,int h){
	if(l<h){
		int mid = (h+l)/2;
		
		int leftSubArray  = findMaxSum(a,l,mid);
		int rightSubArray = findMaxSum(a,mid+1,h);
		int totalSum = totalSumOfArray(a,l,mid,h);
		int ans =  maximum(leftSubArray,rightSubArray,totalSum);
		
		cout<<ans<< " h= "<<h<<" l="<<l<<endl;
		cout<<leftSubArray<<" "<<rightSubArray<<" "<<totalSum<<endl;
		return ans;
	}
	else{

		return a[h];
	}

}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	cout<<findMaxSum(a,0,n-1)<<endl;

}