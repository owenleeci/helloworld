/*
    LinkedList
        Node* first: 指向串列開頭
        Node* last:  指向串列結尾
        Node append(LinkedList* this, void* data): 加入新節點(並返回節點位置)

    Node
        void* data:  節點內容(泛型指標)
        Node* next:  指向下一個結點

    __LinkedList__() 創建新的鍵結串列
*/

typedef struct node {
    void* data;
    struct node* next;
}Node;

typedef struct ll {
    Node* first;
    Node* last;
    Node* (*append)(struct ll*, void*);
}LinkedList;

Node* linkedlistAppend(LinkedList *this1, void *data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    if (!this1->first) {
        this1->first = n;
        this1->last = n;
        return n;
    }
    this1->last->next = n;
    this1->last = this1->last->next;
    return n;
}

LinkedList* __LinkedList__() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->first = NULL;
    list->last = NULL;
    list->append = linkedlistAppend;
    return list;
}

void printList(LinkedList* l) {
    Node* current;
    for (current = l->first; current; current = current->next) {
        printf("%s -> ", (char*)(current->data));
    }
    printf("NULL\n");
}

