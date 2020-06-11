#include <iostream>

using namespace std;

double e(int x,int n){
    static double p=1;
    static double f=1;
    double r;
    if(n==0){
        return 1;
    }else{
        r=e(x,n-1);
        p=p*x;
        f=f*n;
        r=r+p/f;
        return r;



    }
}

int main()
{
    float c=e(1,10);
    cout<<c;
    return 0;
}
