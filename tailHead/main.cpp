#include <iostream>

using namespace std;

fun(int n){

    if(n>0){

    cout<<n;
    cout<<"\n";
    fun(n-1);
    }

}

int main()
{
    int x=3;
    fun(x);
}
