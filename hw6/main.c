#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next_node;
}node_t;

node_t* allocate_node(int data) {
    node_t* p = (node_t*)calloc(1,sizeof(node_t));
    p->data = data;
    p->next_node = NULL;
    return p;
}

node_t* append_node(node_t* head,int new_data) {
    node_t* new_node = allocate_node(new_data);
    if(head) {
        node_t* p = head;
        while(p->next_node) {
            p = p->next_node;
        }
        p->next_node = new_node;
    } else {
        head = new_node;
    }
    return head;
}

void show_list(node_t* headlist) {
    while(headlist) {
        printf("[%d]->", headlist->data);
        headlist = headlist->next_node;
    }
    printf("null\n");
}

void free_all_node(node_t* head) {
    node_t* p = NULL;
    while(head) {
        p = head;
        head = head->next_node;
        printf("free[%d]->", p->data);
        free(p);
    }
    printf("null\n");
}

node_t* add_node(node_t* head, int new_data) {
	node_t* new_node = allocate_node(new_data);
	new_node->data = new_data;
	new_node->next_node = head;
	head = new_node;
	return head;
}

node_t* del_node(node_t* head, int n) {
	if(head == NULL) return head;
	node_t* del = head;
    if (n == 0){
        head = del->next_node;   
        free(del);               
        return del;
    }
    for (int i=0; del!=NULL && i<n-1; i++) del = del->next_node;
    if (del == NULL || del->next_node == NULL) return del;
    node_t *next = del->next_node->next_node;
    free(del->next_node);  
    del->next_node = next;
    
}



int main() {
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 1);
    show_list(head);
    head = add_node(head, -1);
    show_list(head);
    del_node(head, 1);
    show_list(head);
    free_all_node(head);

    return 0;
}
