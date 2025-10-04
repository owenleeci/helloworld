// 在 Linked list 中的其中一個 Node 後插入一個新的 Node
#include <stdio.h>
#include <stdlib.h>
#include "lib/linkedlist.h"

void insert(LinkedList* l, Node* insertAfterHere, char* insertThis) {
    // 檢查該佇列是否為空
    // 該佇列不為空
    if (l->first) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = (void*)insertThis;
        newNode->next = insertAfterHere->next;
        insertAfterHere->next = newNode;
    } else {
        // 為空的話直接用先前寫好 append 語法就好了
        // 課本上的實作也類似，課本是直接更改指向 first 的那個 Node
        l->append(l, (void*)insertThis);
    }
}



int main() {
    LinkedList* l = __LinkedList__();

    Node* BAT = l->append(l, (void*)"BAT1");
    Node* CAT = l->append(l, (void*)"CAT");
    Node* EAT = l->append(l, (void*)"EAT");
    Node* FAT = l->append(l, (void*)"FAT");
    Node* HAT = l->append(l, (void*)"HAT");

    // (1) 原先的串列
    printList(l);
    // OUTPUT: BAT -> CAT -> EAT -> FAT -> HAT -> NULL

    // (2) 在該串列的 CAT 與 EAT 中插入 DAT
    insert(l, CAT, "DAT1");
    printList(l);
    // OUTPUT: BAT -> CAT -> DAT -> EAT -> FAT -> HAT -> NULL

    // (3) 新建空串列，空串列使用 insert 的效果
    LinkedList* m = __LinkedList__();
    insert(m, NULL, "DAT2");
    printList(m);
    // OUTPUT: DAT -> NULL

    return 0;
}
