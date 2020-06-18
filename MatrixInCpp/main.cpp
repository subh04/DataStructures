#include <iostream>

using namespace std;
class DiagonalMatrix{
private:
    int n;
    int *A;
public:
    DiagonalMatrix(int n){
        this->n=n;
        A=new int[n];
    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~DiagonalMatrix(){
        delete[] A;
    }
};
void DiagonalMatrix::Set(int i,int j,int x){
    if(i==j){
        A[i-1]=x;
    }
}
int DiagonalMatrix::Get(int i,int j){
    if(i==j){
        return A[i=1];
    }else{
        return 0;
    }
}
void DiagonalMatrix::Display(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
                printf("%d ",A[i-1]);
            }else{
                printf("%d ",0);
            }
        }
        printf("\n");
    }
}
int main()
{
    DiagonalMatrix m(4);
    m.Set(1,1,1);
    m.Set(2,2,2);
    m.Set(3,3,3);
    m.Set(4,4,4);
    m.Display();
    printf("\n%d",m.Get(2,3));
    return 0;
}
