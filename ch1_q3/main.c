#include <stdio.h>
#include "list.h"

int main(int argc, const char *argv[]) {
    printf("Ch1 Q3\n");

    Node *list = NULL;

    insert(&list, NULL, "four");
    insert(&list, NULL, "one");
    insert(&list, find(list, "one"), "two");
    insert(&list, find(list, "two"), "three");

    dump(list);

    printf("-- delete three --\n");
    delete(&list, find(list, "three"));
    dump(list);

    printf("-- delete one --\n");
    delete(&list, find(list, "one"));
    dump(list);

    while (list != NULL) {
        delete(&list, list);
    }

    return 0;

}