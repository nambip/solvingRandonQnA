#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Node definition
struct node{
    int data;
    struct node* next;
};

// create node
struct node* create_node(int value){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}

// print linkedlist
void print_list(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf(" %d - ", temp->data);
        temp = temp->next;
      
    }
    printf("\n");
}

// insert at head
void insert_at_head(struct node** head, struct node* new_node){

new_node->next = *head;
*head = new_node;

}

// find a node

bool find_value(struct node* head, int value){

struct node* temp = head;
while( temp!= NULL){

    if(temp->data == value){
      printf("Found value %d \n", value);
      return true;
    }
    temp = temp->next;

}
if(temp == NULL){
    printf("Not Found value %d \n", value);
    return false;
}
}

// delete node

void delete_node(struct node** head, int value){

    struct node* prev;
    struct node* temp = *head;

    if((temp != NULL) && (temp->data == value)){
     *head = temp->next;
     free(temp);
     return;
    }

    while((temp != NULL) && (temp->data != value)){
     prev = temp;
     temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void new_node_after(struct node* prev, int num){
    if(prev == NULL)
    return;

    struct node* new_node = create_node(num);
    new_node->next = prev->next;
    prev->next = new_node;
}

void remove_loop(struct node* loop_node, struct node* head){

// Count no: of loop_nodes - k (with two pointers: one stationary and other moving)
// With One pointer at head and another pointer at k nodes from head, start with equal pace, then they would meet at start of loop.
// Find end of loop from there.

struct node* ptr1 = loop_node;
struct node* ptr2 = loop_node;
ptr2 = ptr2->next;

int k = 1;

while(ptr2 != ptr1){
ptr2 = ptr2->next;
k++;
}
printf("no: of nodes = %d \n", k);


// To make ptr1 at head ptr2 at k distance from head
ptr1 = ptr2 = head;

for(int l=0; l<k; l++){

ptr2 = ptr2->next;

}

printf("ptr1 data = %d, ptr2 data = %d \n", ptr1->data, ptr2->data);

// move ptr1 and ptr2 at same pace

while(ptr1->next != ptr2->next){
    ptr1 = ptr1->next;
    ptr2 = ptr2->next; 
}

printf("Entered here \n");
ptr2->next = NULL;


 }

bool detect_and_remove_circular(struct node* head){

// Using Floyd's algorithm (fast and slow pointers)
// fast and slow pointers would meet at one of the loop nodes.

struct node* fp = head;
struct node* sp = head;

while(sp && fp && fp->next){
    sp = sp->next;
    fp = fp->next->next;

    if(sp == fp){
    remove_loop(fp, head);
    return true;
    }
}

return false;

}

int main(){

    struct node* head = NULL;
    
    head = create_node(14);
    head->next = create_node(15);
    head->next->next = create_node(16);
    head->next->next->next = create_node(17);

    printf("Enter linked list \n");

    print_list(head);

    struct node* new_node;
    for(int i=0; i<10; i++){
        
        new_node = create_node(i);
        insert_at_head(&head, new_node);
    }

    print_list(head);

    find_value(head, 0);
    find_value(head, 18);

    delete_node(&head, 0);
    
    print_list(head);

    delete_node(&head, 9);
    print_list(head);

    new_node_after(head->next->next, 22);
    print_list(head);

    printf("head->next->next->data %d \n", head->next->next->data);

    // creating circular loop
    struct node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head->next->next->next->next;

    detect_and_remove_circular(head);

    print_list(head);



    return 0;
}

