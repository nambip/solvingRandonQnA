#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

//implementation of sizeof 

struct my_struct {

char name[10];
int age;
float grade;

};

int main(){

    // 1. Find size of struct without using sizeof operator
    struct my_struct no1;
    printf("%lu \n", sizeof(no1)); // -->  2 padding bytes for name --> 12+4+4 = 20
    
   // Method 1: Using adress of type ie..sizeof(type) = (char*)(&type + 1) - (char*)&type
    int size = (char*)(&no1 + 1) - (char*)&no1;
    printf("%d \n", size);
    
   // Method 2: Using 2 struct pointers array
    struct my_struct nums[2];       // always assign two struct blocks
    struct my_struct* p[2];
    p[0] = &nums[0];
    p[1] = &nums[1];
    
    // Method 3: Using pointer to struct
    size = (char*)p[1] - (char*)p[0];
    printf("%d \n", size);

    struct my_struct* p1 = nums;
    size = (char*)(p1+1) - (char*)p1;
    printf("%d \n", size);

    // 2. Find size of an array
    // &arr1 points to the whole array, arr1 points to the first element in the array.
    int arr1[10];

    int l1 = (char*)(arr1+1) - (char*)arr1; 
    int l2 = (char*) (&arr1+1) - (char*)&arr1; // size of an array
    int l3 =  *(&arr1+1) - arr1; // no: of elements in an array, &arr1 --> ponts to array of 10 elements, *(&arr1+1) will turn it as (int*) 
    printf("%d \n", l1 );
    printf("%d \n", l2 );
    printf("%d \n", l3 );

    int arr2[2][10];
    
    l1 = *(&arr2+1) - arr2;
    printf("%d \n", l1 );
    l2 = (char*) (arr2+1) - (char*)arr2; 
    printf("%d \n", l2 );

}