// 在 Linked list 中刪除其中一個節點
#include <stdio.h>
#include <stdlib.h>
#include "lib/linkedlist.h"

void deleteNode (LinkedList* l, Node* nodeBeforeTarget) {
    // nodeBeforeTarget 為 NULL 代表刪除第一個節點
    // nodeBeforeTarget 有值代表刪除的不是第一個節點
    if (nodeBeforeTarget) {
        Node* target = nodeBeforeTarget->next;
        Node* nodeAfterTarget = target->next;
        free(target);
        nodeBeforeTarget->next = nodeAfterTarget;
    } else {
        Node* target = l->first;
        Node* nodeAfterTarget = target->next;
        free(target);
        l->first = nodeAfterTarget;
    }
}


int main() {
    LinkedList* l = __LinkedList__();

    Node* BAT = l->append(l, (void*)"BAT");
    Node* CAT = l->append(l, (void*)"CAT");
    Node* EAT = l->append(l, (void*)"EAT");
    Node* FAT = l->append(l, (void*)"FAT");
    Node* HAT = l->append(l, (void*)"HAT");

    // (1) 原先的串列
    printList(l);
    // OUTPUT: BAT -> CAT -> EAT -> FAT -> HAT -> NULL

    // (2) 試刪除 CAT 後的 EAT
    deleteNode(l, CAT);
    printList(l);
    // OUTPUT: BAT -> CAT -> FAT -> HAT -> NULL

    // (3) 試刪除頭結點 BAT
    // 因為 BAT 前沒有節點所以我們用 NULL 來代替 nodeBeforeTarget
    deleteNode(l, NULL);
    printList(l);
    // OUTPUT: CAT -> FAT -> HAT -> NULL

    return 0;
}
