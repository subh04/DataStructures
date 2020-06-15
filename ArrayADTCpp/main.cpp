#include <iostream>

using namespace std;

template<class T>

class Array{
private:
    T *A;
    int length;
    int size;
public:
    Array(){
        size=10;
        length=0;
        A=new T[size];

    }
    Array(int sz){
        size=sz;
        length=0;
        A=new T[size];
    }
    ~Array(){
        delete []A;
    }
    void display();
    void insert(int index,T x);
    T del(int index);

};
//EFFECT OF TEMPLATE FINISHED IN THE END OF THE CLASS
template<class T>
void Array<T>::insert(int index,T x){
    if(index>=0&&index<=length){
        for(int i=length-1;i>=index;i--){
            A[i+1]=A[i];
        }
        A[index]=x;
        length++;
    }
}
template<class T>
void Array<T>::display(){
    for(int i=0;i<length;i++){
        cout<<A[i]<<"_";
    }
    cout<<endl;
}
template<class T>
T Array<T>::del(int index){
    T x=0;
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
    Array<float> arr(10);
    arr.insert(0,5.2);
    arr.insert(1,6.8);
    arr.insert(2,7.3);
    arr.display();
    float c=arr.del(1);
    cout<<c<<" is deleted"<<endl;
    arr.display();
    return 0;
}
