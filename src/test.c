#include "push_swap.h"

void bubbleSort(stack *start) 
{ 
    int swapped; 
    stack *ptr1; 
    stack *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->value > ptr1->next->value) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  
/* function to swap value of two nodes a and b*/
void swap(stack *a, stack *b) 
{ 
    int temp = a->value; 
    a->value = b->value; 
    b->value = temp; 
} 