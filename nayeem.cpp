#include <bits/stdc++.h>

using namespace std;
const double PI = 3.14;

class Cylinder
{
public:
    double r,h;
    Cylinder();
    void volume();
    void surface();    
};
Cylinder::Cylinder(){
    cout<<"Please enter the redius: ";
    cin>>r;
    cout<<"Please enter the height: ";
    cin>>h;
}
void Cylinder::volume(){
    double ans =  PI*pow(r,2)*h;
    cout<<"Volume  : "<<ans<<endl;
}
void Cylinder::surface(){
    double ans = (2*PI*r*h)+(2*PI*pow(r,2));
    cout<<"Surface : "<<ans<<endl;
}
int main(){
    double r,h;
    
    Cylinder obj;
    obj.volume();
    obj.surface();

    
    
}