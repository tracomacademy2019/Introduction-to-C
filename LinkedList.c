/*
Defining a linked list node

  typedef struc6t node {
    int val;
    struct node * next;
}node_t;

node_t * head= NULL;
head = malloc(sizeof(node_t));
if(head == NULL){
  return 1;
}

head-> val =1;
head-> next = NULL;

To add a variable
node_t * head = NULL;
head = malloc(sizeof(node_t));
head->val =1;
head->next = malloc(sizeof(node_t));
head->next->val = 2;
head->next->next = NULL

Iterating a list
void print_lis(node_t * head){
  node_t * current = head;

  while(current != null){
    printf("%d\n", current ->val);
    cuurent = current->next;
  }
}

Adding an item to the end of the list
void push(node_t * head, int val){
  node_t * current = head;
  while(current->next != NULL){
    current = current -> next;
  }
  current->next = malloc(sizeof(node_t));
  current-next->val = val;
  current->next->next = NULL;
}

Adding an item to the beginning
void push(node_t ** head, int val){
  node_t * new_node;
  new_node = malloc(sizeof(node_t));

  new_node->val = val;
  new_node->next = *head;
  *head = new_node;
}

Removing the first item
int pop(node_t ** head){
  int retval = -1;
  node_t * next_node = NULL;
  if(*head == NULL){
    return-1;
  }

  next_node = (*head)->next;
  retval = (*head)->val;
  free(*head);
  *head = next_node;

  return retval;
}

Removing the last item
int remove_last(node_t * head){
  int retval = 0;

  if(head->next = NULL){
    retval = head->val;
    free(head);
    return retval;
}

node_t * current = head;
while(current->next->next != NULL){
    current = current->next;
}

retval = current->next->val;
free(current->next);
current->next = NULL;
return retval;
}
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_value(node_t ** head, int val) {
    /* TODO: fill in your code here */
    node_t *previous, *current;

    if(*head == NULL){
      return -1;
    }
    if((*head)->val == val){
      return pop(head);
    }

    previous = current = (*head)->next;
    while(current){
      if(current->val == val){
        previous->next = current->next;
        free(current);
        return val;
      }
      previous = current;
      current = current->next;
    }
    return -1;
}

int main() {

    node_t * test_list = malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);
}
