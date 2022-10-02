/* DATE: 17-07-2022 */

#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define push_back pb;
#define insert in;

using namespace std;

int main(){
    double a,b,c;
    cin>>a>>b>>c;

    double r = hypot(a,b);
    //hypot means squr(a^2+b^2) or distance
    double theta = atan2(b,a);

    theta += c * acos(-1.0)/180.0;

    double x = cos(theta) * r;
    double y = sin(theta) * r;

    cout<<fixed<<setprecision(10)<<x<<" "<<y<<endl;
}