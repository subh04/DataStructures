#include <iostream>

using namespace std;


double e(int x,int n){

    static double sum=1;

    if(n==0){
        return sum;
    }else{

        sum=1+x*sum/n;
        return e(x,n-1);

    }


}

int main()
{
    float c=e(1,10);
    cout<<c;
}
