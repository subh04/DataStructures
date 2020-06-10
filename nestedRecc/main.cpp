#include <iostream>

using namespace std;

int fun(int n){
    if(n>100){
        return n-10;
    }else{
        return fun(fun(n+11));
    }
}

int main()
{
    int c=fun(95);
    cout<<c;
}
