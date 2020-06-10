#include <iostream>

using namespace std;

int fun(int n){
    if(n==0){
        return 1;
    }
    else if(n>0){
        return fun(n-1)*n;
    }else{
        cout<<"not possible";
        return 0;
    }
}

/*
int fun(int n){

    static int fact=1;
    if(n<0){
        cout<<"factorial not possible";
        return 0;
    }
    for(int i=n;i>=0;i--){
            if(i==0){
                return fact*1;
            }else{
            fact=fact*i;
            }

    }
    return fact;

}*/
int main()
{
   int c=fun(10);
   cout<<c;
}
