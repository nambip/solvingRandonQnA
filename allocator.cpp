#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define ALLOC_SIZE 10000

static char alloc_buf[ALLOC_SIZE]; /* storage for alloc */
static char* allocp = alloc_buf;   /* next free pointer */

// 1. Stack oriented storage allocator
// returns pointer to n characters.
char* alloc(int n){

if((alloc_buf+ALLOC_SIZE - allocp)>=n){

    allocp = allocp + n;
    return (allocp - n);
}
else{
    return 0;
}
}

void afree(char* p){

    if(p>=alloc_buf && p < alloc_buf+ALLOC_SIZE)
    allocp = p;

}

// 2. 

int main(){

char* s = alloc(12);

for(int i=0; i<11; i++){
    *(s+i) = 'N';
}
*(s+11) = '\0';

while(*s!='\0'){
    printf("%c \n", *s++);
}


}