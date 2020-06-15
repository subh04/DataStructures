#include <iostream>

using namespace std;


class Array{
private:
    int *A;
    int length;
    int size;
public:
    Array(){
        size=10;
        length=0;
        A=new int[size];

    }
    Array(int sz){
        size=sz;
        length=0;
        A=new int[size];
    }
    ~Array(){
        delete []A;
    }
    void display();
    void insert(int index,int x);
    int del(int index);

};
void Array::insert(int index,int x){
    if(index>=0&&index<=length){
        for(int i=length-1;i>=index;i--){
            A[i+1]=A[i];
        }
        A[index]=x;
        length++;
    }
}
void Array::display(){
    for(int i=0;i<length;i++){
        cout<<A[i]<<"_";
    }
    cout<<endl;
}
int Array::del(int index){
    int x=0;
    if(index>=0&&index<=length){
        x=A[index];
        for(int i=index;i<length-1;i++){
            A[i]=A[i+1];
        }
        length--;
    }
    return x;
}
int main()
{
    Array arr(10);
    arr.insert(0,5);
    arr.insert(1,6);
    arr.insert(2,7);
    arr.display();
    return 0;
}
