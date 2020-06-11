#include <iostream>

using namespace std;

double e(int x,int n){
    static double sum=1;
    for(;n>0;n--){
        sum=1+x*sum/n;
    }
    return sum;
}

int main()
{
    float c=e(1,10);
    cout<<c;
}
