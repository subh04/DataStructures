#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[]="decimal";
    char B[]="medicaka";
    int i,j;
    int H[26];
    int flag=0;
    for(i=0;i<26;i++){
        H[i]=0;
    }
    printf("hash initialised to zero\n");
    for(i=0;i<26;i++){
        printf("%d ",H[i]);
    }


    for(i=0,j=0;A[i]!='\0',B[i]!='\0';i++,j++){

    }
    //printf("%d %d",i,j);
    if(i==j){
        for(i=0;A[i]!='\0';i++){
            H[A[i]-97]++;
        }
    printf("\nhash re initialised\n");
    for(i=0;i<26;i++){
        printf("%d ",H[i]);
    }
    for(i=0;B[i]!='\0';i++){
        H[B[i]-97]--;
    }
    printf("\nhash re initialised\n");
    for(i=0;i<26;i++){
        printf("%d ",H[i]);
    }
    for(i=0;i<26;i++){
        if(H[i]==0){

            continue;
        }else{
            flag=1;
            break;
        }

    }
    if(flag==0){
        printf("\nits anagram");
    }else if(flag==1){
        printf("\nnot anagram");
    }
    }else{
        printf("not anagram\n");
    }

    return 0;
}
