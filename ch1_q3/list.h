#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct Node {
    char *value;
    struct Node *prev;
    struct Node *next;
} Node;

void insert(Node **head, Node *after, const char *value);

Node *find(Node *head, const char *value);

void delete(Node **head, Node *node);

void dump(Node *head);

#endif