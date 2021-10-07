#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct group{
    int n;
    double m; 
    char text;
};

unsigned int convert_to_big_endian(unsigned int num){

    unsigned int res;
    unsigned b0 = num & (0x000000ff);
    unsigned b1 = num & (0x0000ff00);
    unsigned b2 = num & (0x00ff0000);
    unsigned b3 = num & (0xff000000);

    res = b0 << 24 | b1 << 8 | b2 >> 8 | b3 >> 24;

    return res;
}


int main(){

    struct group g1;

    //1. size of the struct is 24 --> this is due to structure padding for byte alignment (4 + 4padding) + (8) + (1 + 7padding) --> members are 8 each after padding
    // padding is added when structre member is followed by larger size or added at end of struct for data alignment ??
    int s = sizeof(g1);
    printf("%d \n", s);
    s = sizeof(int);
    printf("%d \n", s);
    s = sizeof(double);
    printf("%d \n", s);
    s = sizeof(double);
    
    s = sizeof(g1.text);
    printf("%d \n", s);

    //2. Size of int without sizeof
    int size;
    int* p = &size;
    int l = (char*)(&size+1) - (char*)&size;
    printf("%d \n", l);
    l = (char*)(p+1) - (char*)p;
    printf("%d \n", l);
    
    //3. Size of struct without sizeof
    struct group* ptr = &g1;
    l = (char*)(ptr+1) - (char*)ptr;
    printf("%d \n", l);

    //4. Convert little endian to big endian
    unsigned int n = 0x01234567;

    unsigned int res = convert_to_big_endian(n);
    printf("%x \n", res);

    return 0;
}