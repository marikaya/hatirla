#include <stdio.h>
#include <stdlib.h>


typedef struct data {
    int val;
    struct data *next;
} t_data;


t_data *root;


void printList() {
    t_data *current = root;
    printf("#LINKED LIST START\n");


    while (current != NULL) {
        printf("ELEMENT : %d\n", current->val);
        current = current->next;
    }
    printf("#LINKED LIST END\n");
}

t_data *findElement(int val) {
    t_data *current = root;
    while (current != NULL) {
        if (current->val == val) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void deleteElement(int data) {
    t_data *current = root;
    t_data *last = NULL;

    while (current != NULL) {
        if (current->val == data) {
            if (current->next != NULL) {
                if(last ==NULL){
                    //en basta imis
                    // en basta ise
                    root = current;
                }else{
                    if (current->next !=NULL){
                        last->next = current->next;
                    }else{
                        last->next = NULL;
                    }
                }

            }else{
                last->next = NULL;
            }
        } else {
            last = current;
        }

        current = current->next;
    }

}

int add_element(int val) {
    if (root == NULL) {
        root = (t_data *) malloc(sizeof(t_data));
        root->next = NULL;
        root->val = val;
    } else {
        t_data *current = root;
        while (current->next != NULL) {
            current = current->next;
        }

        t_data *newNode = (t_data *) malloc(sizeof(t_data));
        newNode->next = NULL;
        newNode->val = val;

        current->next = newNode;
    }

    return 0;

}

int main() {

    add_element(10);
    add_element(11);
    add_element(10);
    add_element(10);
    add_element(10);

    deleteElement(10);
    deleteElement(10);
    deleteElement(10);
    deleteElement(10);
    deleteElement(11);
    printList();


    t_data *foundElement = findElement(11);
    if (foundElement != NULL) {
        printf("Element is found %d\n", foundElement->val);
    } else {
        printf("No element is found\n");
    }


    foundElement = findElement(13);
    if (foundElement != NULL) {
        printf("Element is found %d\n", foundElement->val);
    } else {
        printf("No element is found\n");
    }

}
