#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Findint Length of the string
    char S[]="MALOM";
    int i;
    //Findint Length of the string
    /*

    for(i=0;S[i]!='\0';i++){

    }
    printf("size of the string is %d",i);
    */
    //changing the cases of the string
    /*
    for(i=0;S[i]!='\0';i++){
        if(S[i]>=65&&S[i]<=90){
            S[i]=S[i]+32;
        }
        else if(S[i]>=97&&S[i]<=122){
            S[i]=S[i]-32;
        }
    }
    printf("%s",S);
    */

    //Finding Number of words in the sentence with any number of space
    /*
    int word=0;
    for(i=0;S[i]!='\0';i++){
        if(S[i]==32 &&S[i-1]!=32){
            word++;
        }
    }
    printf("number of words are %d",word+1);
    */
    //calculating the number of vowels
    /*
    int vcount=0;
    for(i=0;S[i]!='\0';i++){
        if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u'||
           S[i]=='A'||S[i]=='E'||S[i]=='I'||S[i]=='O'||S[i]=='U'){
                vcount++;
           }

    }
    printf("total number of vowels are %d",vcount);
    */
    //reversing a string using single array
    /*
    int j;
    char temp;
    for(j=0;S[j]!='\0';j++){

    }
    printf("length of the string is %d\n",j-1);
    j=j-1;
    for(i=0;i<j;i++,j--){
        temp=S[i];
        S[i]=S[j];
        S[j]=temp;
    }
    printf("reversed string is %s",S);
    */
    //reverse string using two arrays
    /*
    int j;
    for(j=0;S[j]!='\0';j++){

    }
    char B[j];
    for(i=j-1,j=0;i>=0;i--,j++){
        B[j]=S[i];
    }
    B[j]='\0';
    printf("string is %s\nreversed string is %s",S,B);
    */
    //comparing two strings
    /*
    int j;
    char A[]="welcome shubhamish";
    for(i=0,j=0;S[i]!='\0';i++,j++){
        if(S[i]!=A[j]){
            printf("strings are not equal");
            break;
        }
    }
    if(S[i]==A[j]){
        printf("the strings %s and %s are equal",S,A);
    }
    else if(S[i]<A[j]){
        printf("\n%s COMES FIRST in dictionary than %s",S,A);
    }else
        printf("\n%s COMES FIRST in dictionary than %s",A,S);
    */

    //checking if the strings are palindrome or not in a single array
    /*
    int j;
    for(j=0;S[j]!='\0';j++){

    }
    //char B[j];
    j=j-1;
    for(i=0;i<=j;i++,j--){
        if(S[i]!=S[j]){
            printf("not a palindrome\n");
            break;
        }
    }
    if(S[i]==S[j]){
        printf("Palindrome");
    }
    */
    //CHECKING IF PALINDROME OR NOT USING TWO ARRAYS
    //WRONG OUTPUT
    int j;
    for(j=0;S[j]!='\0';j++){

    }
    printf("%d\n",j);

    char B[j];
    for(i=j-1,j=0;i>=0;i--,j++){
        B[j]=S[i];
    }
    B[j]='\0';

    printf("REVERSED STRING IS %s\n",B);

    for(i=0,j=0;S[i]!='\0',B[j]!='\0';i++,j++){
        if(S[i]!=B[j]){
            printf("not palindrome\n");
            break;
        }
    }
    if(S[i]==B[j]){
        printf("palindrome\n");
    }


    return 0;

}
