#include <iostream>

using namespace std;

/*int fun(int n){
    static int sum=0;

    if(n>0){
        sum=fun(n-1)+n;

    }
}*/
//take O(n+1) space

int fun(int n){
    static int sum=0;
    while(n>0){
        sum=sum+n;
        n--;
    }
}

//takes O(n) time and O(1) space

int main()
{
    int c=fun(5);
    cout<<c;

}
