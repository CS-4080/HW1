#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

static char *strdup_c(const char *s) {
    size_t len = strlen(s);

    char *copy = malloc(len + 1);

    if (!copy) {
        return NULL;
    }

    memcpy(copy, s, len + 1);
    return copy;
}

void insert(Node **head, Node *after, const char *value) {
    if (head == NULL) {
        return;
    }

    Node *node = malloc(sizeof(Node));

    if (!node) {
        fprintf(stderr, "malloc failed in insert\n");
        exit(1);
    }

    node->value = strdup_c(value);

    if (!node->value) {
        fprintf(stderr, "malloc failed for string in insert\n");
        free(node);
        exit(1);
    }

    node->prev = NULL;
    node->next = NULL;

    if (*head == NULL) {
        *head = node;
        return;
    }

    if (after == NULL) {
        node->next = *head;
        (*head)->prev = node;
        *head = node;
        return;
    }

    node->next = after->next;
    node->prev = after;

    if (after->next != NULL) {
        after->next->prev = node;
    }

    after->next = node;

}

Node *find(Node *head, const char *value) {
    for (Node *cur = head; cur != NULL; cur = cur->next) {
        if (strcmp(cur->value, value) == 0) {
            return cur;
        }
    }
    return NULL;
}

void delete(Node **head, Node *node) {
    if (head == NULL || *head == NULL || node == NULL) {
        return;
    }

    if (node == *head) {
        *head = node->next;
    }

    if (node->prev != NULL) {
        node->prev->next = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    free(node->value);
    free(node);
}

void dump(Node *head) {
    printf("List: ");

    for (Node *cur = head; cur != NULL; cur = cur->next) {
        printf("%s ", cur->value);
    }

    printf("\n");

}

