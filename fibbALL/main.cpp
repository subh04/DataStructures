#include <iostream>

using namespace std;


int fib(int n){
    static int t0=0,t1=1,sum=0;
    if(n<=1){
        return n;
    }else{
        sum=t0+t1;
        t0=t1;
        t1=sum;
        fib(n-1);

    }
    return sum;

}
int fibLoop(int n){
    static int t0=0,t1=1,sum=0;

    if(n<=1){
        return n;
    }
    for(int i=2;i<=n;i++){

        sum=t0+t1;
        t0=t1;
        t1=sum;

    }
    return sum;


}
int f[10];
int fibMemoization(int n){


    if(n<=1){
        f[n]=n;
        return n;
    }else{
        if(f[n-2]==-1)
            f[n-2]=fibMemoization(n-2);
        if(f[n-1]==-1)
            f[n-1]=fibMemoization(n-1);

        return f[n-2]+f[n-1];


    }


}

int main()
{
    for(int i=0;i<10;i++){
        f[i]=-1;
    }
    int c=fib(10);
    int d=fibLoop(10);
    cout<<c<<"\n";
    cout<<d<<"\n";
    int e=fibMemoization(6);
    cout<<e<<"\n";

        for(int i=0;i<10;i++){
        cout<<f[i]<<" ";
    }

}
