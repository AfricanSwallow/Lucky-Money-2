#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "function.h"
Node * ptr_Node[500001];

int comp(const void * p1, const void * p2) {
    const Node ** a1 = (const Node **) p1;
    const Node ** a2 = (const Node **) p2;

    if((*a1)->age > (*a2)->age) {
        return 1;
    }else if ((*a1)->age < (*a2)->age) {
        return -1;
    }else {
        if((*a1)->number > (*a2)->number)
            return 1;
        else 
            return -1;
    }
}


Node* createList(int n) {
    head = NULL;
    Node *cur, *prev;
    for(int i = 0; i < n; i++) {
        cur = (Node*) malloc(sizeof(Node));
        if(head == NULL) {
            head = cur;
        }else {
            prev->next = cur;
            cur->prev = prev;
        }

        if(i == n-1) {
            cur->next = head;
            head->prev = cur;
        }

        scanf("%d", &cur->age);
        cur->number = i;
        prev = cur;

        ptr_Node[i] = cur;
    }

    //Sort the pointer array
    qsort(ptr_Node, n, sizeof(Node*), comp);
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
        from = ptr_Node[a-1];

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
    return ptr_Node[0];
}