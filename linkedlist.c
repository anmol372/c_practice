#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
}node;

typedef struct linked_list {
  struct node *head;
}linked_list;

//to make new node
node* new_node(int data) {
  node *z;
  z = malloc(sizeof(struct node));
  z->data = data;
  z->next = NULL;

  return z;
}

//to make a new linked list
linked_list* new_linked_list(int data) {
  node *a; //new node for head of linked list
  a = new_node(data);

  linked_list *l = malloc(sizeof(linked_list)); //linked list
  l->head = a;

  return l;
}

void traversal(linked_list *l) {
  node *temp = l->head; //temporary pointer to point to head

  while(temp != NULL) { //iterating over linked list
    printf("%d\t", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

//new node before head
void insert_at_beginning(linked_list *l, node *n) {
  n->next = l->head;
  l->head = n;
}

//insert new node at last
void insert_at_last(linked_list *l, node *n) {
  node *temp = l->head;

  while(temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = n;
}

//function to insert a node after a node
void insert_node_after(node *n, node *a) {
  n->next = a->next;
  a->next = n;
}

//function to delete
void del(linked_list *l, node *n) {
  node *temp = l->head;
  if(temp == n) { //node to be deleted is head
    l->head = n->next;
    free(n);
  }
  else { //node to be deleted is not head
    while(temp != NULL) {
      if(temp->next == n) { //node previous to node to be deleted
        temp->next = n->next;
        free(n);
        break; //breaking the loop after deleting the node
      }
      temp = temp->next;
    }
  }
}

int main() {
  linked_list *l = new_linked_list(10);

  node *a, *b, *c; //new nodes to insert in linekd list
  a = new_node(20);
  b = new_node(50);
  c = new_node(60);

  //connecting to linked list
  /*
     ----     ----     ----     ----
    |head|-->| a  |-->|  b |-->|  c |-->NULL
    |____|   |____|   |____|   |____|
  */
  l->head->next = a;
  a->next = b;
  b->next = c;

  traversal(l);

  node *z;

  z = new_node(0);
  insert_at_beginning(l, z);
  z = new_node(-10);
  insert_at_beginning(l, z);

  z = new_node(100);
  insert_at_last(l, z);

  z = new_node(30);
  insert_node_after(z, a);
  z = new_node(40);
  insert_node_after(z, a->next);
  z = new_node(500);
  insert_node_after(z, a->next->next);

  traversal(l);

  del(l, l->head);
  del(l, z);
  traversal(l);

  return 0;
}
