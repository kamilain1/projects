#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void create_list(struct node *head, int value) {
    head->next = NULL;
    head->data = value;
}


void insert_node(struct node *new, struct node *prev, int value) {
    if (prev->data == NULL) {
        printf("%s%d%s", "Node with value ", value, " cannot be inserted: previous node is not initialised ");
        exit(1);
    }
    new->data = value;
    new->next = prev->next;
    prev->next = new;
}

//node is deleted by value
void delete_node(struct node *head, int value) {
    struct node *temp;
    struct node *del;

    del = head;
    while (del->data != value) {
        if (del->next == NULL) {
            printf("Node cannot be deleted: node with this value was not found ");
            exit(1);
        }
        del = del->next;

    }
    temp = head;
    while (temp->next != del) temp = temp->next;
    temp->next = del->next;
    del = NULL;
}

void print_list(struct node *head) {
    struct node *temp;
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node node1, node2, node3, node4, node5, node6, node7;

    create_list(&node1, 10);

    //insert_node(&node2, &node4, 15);   //program will check if previous node is initialised and if not, will output an error
    insert_node(&node2, &node1, 42);
    insert_node(&node3, &node2, 28);
    insert_node(&node4, &node3, 200);
    insert_node(&node5, &node4, 11);
    insert_node(&node6, &node5, 100);
    insert_node(&node7, &node6, 2);

    // delete_node(&node1, 99);           //program will not find such node and output an error
    delete_node(&node1, 2);
    delete_node(&node1, 200);
    print_list(&node1);

    return 0;
}