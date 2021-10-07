#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define SIZE 1000

static int stack[SIZE];
static int* sp = stack; // next free location

void push(int value){

if(stack + SIZE - sp){
    *sp++ = value;
}
else{
    printf("error: stack full\n");
}
}

int pop(){

int val;

if((sp>=stack) && (sp<(stack+SIZE))){
    val = *--sp;
    return val;
}
else{
    printf("error: stack empty \n");
    return 0;
}

}

int main(){

    for(int i=0; i<20; i++){
        push(i);
    }

    int n = pop();
    printf("%d \n", n);

    n = pop();
    printf("%d \n", n);

    return 0;
}