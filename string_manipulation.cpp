#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

// print string

void print(const char* s){

    for(; *s!= '\0'; s++){
        printf("%c", *s);
    }

    printf("\n");
}

// concatenate two strings

void string_cat(char* s ,char* t){

for(; *s!='\0'; s++){

}
// *s = ' ';

for(; *t!='\0'; t++){
    *s = *t;
    s++;
}
*s = '\0';

}

// squeeze s by removing character c

void squeeze(char* s, int c){

int i,j;
    for(i=0,j=0; s[i]!='\0'; i++){
        if(s[i] != c){
          s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

// squeeze s1 by removing characters in s2
void squeeze_main(char* s1, char*s2){

    for(; *s2!='\0'; s2++){
      squeeze(s1, *s2);  
    }
}

// return the first index in s1 that matches with the chara in s2
int string_brk(char* s1, char* s2){
    
    int j;
    for(int i=0; *(s1+i) != '\0'; i++){
     
     j=0;
     while(*(s2+j) != '\0'){
       if(*(s1+i) == *(s2+j))return i;
       j++;
     }

    }
    return -1;
}

// reverse a string

void reverse(char* s){
    
    int i=0, j=strlen(s)-1;
    // printf("sizeof s %d \n", sizeof(s));
    // int k = strlen(s);
    // printf("strln s %d \n", k);
    char temp;
    while(i<j){
     temp = s[i];
     s[i] = s[j];
     s[j] = temp;
     i++;
     j--;
    }
}

// rotate k to the right

void rotate(char* s, int k){
    int i,j;
    char temp;

    //reverse whole string
    i=0; j=strlen(s)-1;
    while(i<j){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    // reverse first k elements
    i=0;
    j=k-1;
     while(i<j){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    // reverse next n-k elements
    i=k;
    j=strlen(s)-1;
     while(i<j){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }


}

int main(){

    
    char s[] = "So I have started to learn";
    char t[] = "C programming";
  
    print(s);
    print(t);
    
    string_cat(s,t);

    print(s);

    squeeze(t, 'g');
    print(t);

    char s1[] = "Hellone!";
    char s2[] = "Namita";
    
    char s3[] = "ne!";

    squeeze_main(s1,s3);
    print(s1);

    char s4[] = "Hellone!";
    print(s3);
    int index = string_brk(s4,s3);

    printf("index %d \n", index);

    reverse(s4);
    print(s4);
    reverse(s4);

    rotate(s4, 3);
    print(s4);


    return 0;
}