#include <stdio.h>
#include <stdlib.h>


void createLinkedList(int size) {
    struct Node {
        int data;
        struct Node* next;
    };
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* end = NULL;
    for(int i=0; i<size; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = i;
        temp->next = NULL;
        if(head == NULL) {
            head = temp;
            end = temp;
        } else {
            end->next = temp;
            end = temp;
        }
        printf("Nacisnij aby kontynuować\n");
        getchar();
    }
    free(temp);
}


void createArrayOfArrays(int size) {
    double** array = (double**)malloc(size * sizeof(double*));

    for(int i=0; i<size; i++) {
        array[i] = (double*)malloc(size * sizeof(double));

        printf("Nacisnij aby kontynuować\n");
        getchar();
    }

    for(int i=0; i<size; i++) {
        free(array[i]);
    }

    free(array);
}

int main() {
    int size = 1000;

    createLinkedList(size);

    createArrayOfArrays(size);

    return 0;
}
