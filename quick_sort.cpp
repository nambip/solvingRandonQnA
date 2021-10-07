#include <stdio.h>
#include <stdlib.h>
using namespace std;

void print(int v[], int size){

 for(int j=0; j<size; j++){
        printf("%d ", v[j]);
    }
    printf("\n");

}
void swap(int *p, int *q){

int temp = *p;
*p = *q;
*q = temp;

}

void bubble_sort(int* v, int size){

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(v[j]>v[j+1])
            swap(&v[j], &v[j+1]);
        }
    }
}

void quick_sort(int v[], int left, int right){

    int i; int last; int pivot;

   if(left>=right){
       return;
   }
    // swap pivot elemnt to the first elemnt. pivot = (left+right)/2
    pivot = (left+right)/2;
    // printf("arr[pivot] %d \n", v[pivot]);
    swap(&v[left], &v[pivot]);
    // printf("pivot to left: ");
    // print(v, 9);
    last = left;
    // printf("last %d \n", last);
    for(i=last+1; i<=right; i++){

        if(v[i]<v[left]){
        swap(&v[i], &v[++last]);
        // printf("inside if: ");
        // print(v, 9);
        }
    }
    swap(&v[left], &v[last]); // put pivot element to this last place
    // print(v, 9);
    // Now elements to the left of pivot is smaller than pivot, to the right has greater or equal to pivot
    // repeat to the left and right sub arrays
    
    quick_sort(v,left,last-1);
    quick_sort(v,last+1,right);
   

}

void insertion_sort(int* v, int size){

    int i,j,key;
    
    for(i=1; i<size; i++){
        key = v[i];
        j = i-1;
        
        while((v[j]>key) && (j>=0)){
            
                v[j+1] = v[j];
                j--;
        }
        v[j+1] = key;


    }

}

/* v[low,...,mid] and v[mid+1, ....high] are sorted
*/
void merge(int v[], int low, int mid, int high){

    int n1 = mid-low+1;
    int n2 = high-mid;
    int L[n1];
    int R[n2];
    int i,j,k;
    for(i=0; i<n1; i++)L[i]=v[low+i];
    for(i=0; i<n2; i++)R[i]=v[mid+1+i];

    i=0;
    j=0;
    k=low;
    while((i<n1) && (j<n2)){
        if(L[i]<R[j]){
            v[k] = L[i++];
        }
        else if(L[i]>=R[j]){
            v[k] = R[j++];
        }
        k++;
    }
    
    while(i<n1){
        v[k++] = L[i++];
    }

    while(j<n1){
        v[k++] = R[j++];
    }

}

void merge_sort(int v[], int low, int high){
    
    int mid;
    if(low<high){

        mid = (low+high)/2;

        merge_sort(v, low, mid);
        merge_sort(v, mid+1, high);
        merge(v, low, mid, high);

    }

}

int binary_search(int v[], int low, int high, int value){
    
    if(low<high){
    int mid = (low+high)/2;
    if(v[mid]>value){
        return binary_search(v, low, mid-1, value);
    }
    else if(v[mid]<value){
        return binary_search(v, mid+1, high, value);
    }
    else
    return mid;

    }
    
    return -1;

}

int main(){

    int v[] = {2, 1, 3, 4, 9, 0, -1, 6, 6};
    int size = sizeof(v)/sizeof(v[0]);
    int right = (sizeof(v)/sizeof(v[0])) - 1;
    printf("Original array: ");
    print(v, size);
    quick_sort(v, 0, right);
    printf("Quick sort array: ");
    print(v, size);

    int a[] = {2, 1, 3, 4, 9, 0, -1, 6, 6};
    bubble_sort(a, size);
    printf("Bubble sort array: ");
    print(a, size);

    int b[] = {2, 1, 3, 4, 9, 0, -1, 6, 6};
    insertion_sort(b, size);
    printf("Insertion sort array: ");
    print(b, size);
    
    int value = 22;
    int res = binary_search(b, 0, right, value);
    printf("Binary search: ");
    printf("Found value %d at %d \n", value, res);
    
    int c[] = {2, 1, 3, 4, 9, 0, -1, 6, 6};
    merge_sort(c,0,8);
    print(c, 9);

   return 0;
}