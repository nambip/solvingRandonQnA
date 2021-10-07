#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define POS(x) 1 << x
#define INT_BITS 32

unsigned set_bit(unsigned int n, int p){
    return (n | POS(p));
}

unsigned clear_bit(unsigned int n, int p){
    return (n & ~(POS(p)));
}

unsigned toggle_bit(unsigned int n, int p){
    return (n ^ (POS(p)));
}

//Get the bits of x from position p to m bits to the right. 
unsigned getbits(unsigned x, int p, int m){
    return ((x >> (p+1 - m)) & ~(~0 << m));

// x >> (p+1 - m) move desired area the right
// ~(~0 << m) is the mask to select rightmost m bits

}

// change bits of x from position p according to the rightmost n bits of y
unsigned change_bits(unsigned x, int p, int n, unsigned int y){

    return (((y & ~(~0 << n)) << (p+1 - n) ) | x & ((~0 << (p+1)) | ~(~0 << (p+1 - n))));

    // y & ~(~0 << n)  rightmost n bits of y
    //  x & (~0 << (p+1)) upperpart of x
    //  x & ~(~0 << (p+1 - n))  lowerpart of x
} 

// invert bits of x starting from position p to m bits to the right
unsigned invert(unsigned x, int p, int m){

    unsigned int mask = (~0 << (p+1 - m)) &  (~(~0 << (p+1)));

    return (x ^ mask);

    // unsigned int mask1 = (~0 << (p+1 - m));
    // unsigned int mask2 = ~(~0 << (p+1));
    // printf("mask 0x%x, mask1 0x%x, mask2 0x%x  \n", mask, mask1, mask2);

}

// rotate m bits to the right

unsigned rotate_right(unsigned int x, int m){

    return (((x & ~(~0 << m)) << (INT_BITS - m) ) | (x >> m) );

// ((x & ~(~0 << m)) << (INT_BITS - m) )  choose m bits at the right and shift them to the extreme left
// (x >> m) right shift other bits
}


unsigned int swap_nibble(unsigned int n){

    n = ((n & 0x0f) << 4) | ((n & 0xf0) >> 4);
    return n;
}



unsigned int swap_nibble_word(unsigned int n){

unsigned int byte0, byte1, byte2, byte3;

// byte0 = n & 0xff;
byte0 = ((n & 0x0f) << 4) |  ((n & 0xf0) >> 4);

// byte1 = n & 0xff00;
byte1 = ((n & 0x0f00) << 4) | ((n & 0xf000) >> 4);

// byte2 = n & 0xff0000;
byte2 = ((n & 0x0f0000) << 4) | ((n & 0xf00000) >> 4);

// byte3 = n & 0xff000000;
byte3 = ((n & 0x0f000000) << 4) | ((n & 0xf0000000) >> 4);

return (byte3|byte2|byte1|byte0);

}

// number of set bits
int bit_count(unsigned x){

    int count;
    for(count=0; x!=0; x>>=1){
        if(x & 1)
        count++;
    }
    return count;
}

int main(){

    unsigned int n = 0x1234abcd;
    unsigned int num = 0xab;

    unsigned int res = swap_nibble(num);
    unsigned int res2 = swap_nibble_word(n);
    printf("0x%x \n", res);
    printf("0x%x \n", res2);

    unsigned int res3 = getbits(res2,4,3);
    printf("0x%x \n", res3);

    unsigned int res4 = set_bit(0x0F, 4);
    printf("0x%x \n", res4);

    unsigned int res5 = clear_bit(0xFF, 4);
    printf("0x%x \n", res5);

    unsigned int res6 = change_bits(res2, 15, 8, 0xFF);
    printf("0x%x \n", res6);

    unsigned int res7 = invert(res6, 15, 8);
    printf("0x%x \n", res7);

    unsigned int res8 = rotate_right(res7, 8);
    printf("0x%x \n", res8);

    unsigned int res9 = bit_count(0xFFF1);
    printf("%d \n", res9);

    return 0;
}