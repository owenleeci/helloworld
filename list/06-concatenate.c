// 串接兩個 Linked list
#include <stdio.h>
#include <stdlib.h>
#include "lib/linkedlist.h"

LinkedList* concatenate(LinkedList* dest, LinkedList* src) {
    // 當 dest 串列不為空時直接將來源其結尾 next 指向 src 串列的頭
    if (dest->first) {
        dest->last->next = src->first;
    } else {
        // 若 dest 為空則直接將 dest 的頭指向 src 的頭，dest的尾指向 src 的尾
        dest->first = src->first;
        dest->last = src->last;
    }
    return dest;
}


int main() {
    LinkedList* l = __LinkedList__();
    l->append(l, (void*)"BAT");
    l->append(l, (void*)"CAT");
    l->append(l, (void*)"EAT");
    l->append(l, (void*)"FAT");

    printf("l: \t");
    printList(l);
    // OUTPUT: BAT -> CAT -> EAT -> FAT -> NULL

    LinkedList* m = __LinkedList__();
    m->append(m, (void*)"HAT");
    m->append(m, (void*)"JAT");
    m->append(m, (void*)"LAT");
    m->append(m, (void*)"MAT");
    
    printf("m: \t");
    printList(m);
    // OUTPUT: HAT -> JAT -> LAT -> MAT -> NULL

    printf("l + m: \t");
    l = concatenate(l, m);
    printList(l);
    // OUTPUT: BAT -> CAT -> EAT -> FAT -> HAT -> JAT -> LAT -> MAT -> NULL

    LinkedList* s = __LinkedList__();
    printf("s: \t");
    printList(s);
    // OUTPUT: NULL

    printf("s + m: \t");
    s = concatenate(s, m);
    printList(s);
    // OUTPUT: HAT -> JAT -> LAT -> MAT -> NULL

    return 0;
}
