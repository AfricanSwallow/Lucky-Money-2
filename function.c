#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "function.h"
Node * ptr_Node[500001];

void BubbleSort(int n) {
    Node *temp;
    for(int i = n; i >= 2; i--) {
        for(int j = 1; j <= i-1; j++) {
            if(ptr_Node[j]->age > ptr_Node[j+1]->age) {
                temp = ptr_Node[j];
                ptr_Node[j] = ptr_Node[j+1];
                ptr_Node[j+1] = temp;
            }
        }
    }
}


Node* createList(int n) {
    head = NULL;
    Node *cur, *prev;
    for(int i = 1; i <= n; i++) {
        cur = (Node*) malloc(sizeof(Node));
        if(head == NULL) {
            head = cur;
        }else {
            prev->next = cur;
            cur->prev = prev;
        }

        if(i == n) {
            cur->next = head;
            head->prev = cur;
        }

        scanf("%d", &cur->age);
        cur->number = i;
        prev = cur;

        ptr_Node[i] = cur;
    }

    //Sort the pointer array
    BubbleSort(n);
    return head;
}

/******************************************************************/

Node* Travel(Node *cur, int k, bool to_the_right) {
    if(to_the_right) {
        while(k--)
            cur = cur->next;
    }else {
        while(k--)
            cur = cur->prev;
    }
    return cur;
}


Node* solve(int n, int m) {
    int a, k;
    char dir;
    Node *from, *to;
    while(m--) {
        scanf("%d %d %c", &a, &k, &dir);
        from = ptr_Node[a];

        from->prev->next = from->next;
        from->next->prev = from->prev;

        if(dir == 'R') {
            to = Travel(from, k, true);
            from->prev = to;
            from->next = to->next;
            to->next->prev = from;
            to->next = from;
        }else {
            to = Travel(from, k, false);
            from->next = to;
            from->prev = to->prev;
            to->prev->next = from;
            to->prev = from;
        }
    }

    return ptr_Node[1];
}