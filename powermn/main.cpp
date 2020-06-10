#include <iostream>

using namespace std;
/*
fun(int m,int n){
        if(n==0){
            return 1;
        }else
            return fun(m,n-1)*m;
}*/

int fun(int m,int n){
    if(n==0){
        return 1;
    }
    static int res=1;
    for(int i=0;i<n;i++){
        res=res*m;
    }
    return res;
}

int main()
{
  int c=fun(2,9);
  cout<<c;
}
