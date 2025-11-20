//Name - Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#include <stdlib.h>
typedef struct DNode 
{
    int data;
    struct DNode *prev;
    struct DNode *next;
} *DNode;
DNode createNode(int value) {
    DNode newNode = (DNode)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
DNode insertBeg(DNode head, int value) 
{
    DNode newNode = createNode(value);
    if(head == NULL)
        return newNode;
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}
DNode insertEnd(DNode head, int value) 
{
    DNode newNode = createNode(value);
    if(head == NULL)
        return newNode;
    DNode temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
DNode deleteNode(DNode head, int value) 
{
    if(head == NULL)
        return NULL;
    DNode temp = head;
    while(temp != NULL && temp->data != value)
        temp = temp->next;
    if(temp == NULL) 
        return head;
    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    return head;
}
DNode reverse(DNode head) 
{
    DNode curr = head, prevNode = NULL;
    while (curr != NULL) 
    {
        prevNode = curr->prev;
        curr->prev = curr->next;
        curr->next = prevNode;
        curr = curr->prev;
    }
    if (prevNode != NULL)
        head = prevNode->prev;
    return head;
}
DNode findMiddle(DNode head)
{
    
    if (head == NULL)
        return NULL;
    int count = 0;
    DNode temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    int mid = count / 2;
    temp = head;
    for (int i = 0; i < mid; i++)
        temp = temp->next;
    return temp;
}
DNode sortList(DNode head)
{
    if (head == NULL)
        return NULL;
    DNode i, j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}
int detectLoop(DNode head) 
{
    DNode i = head;
    while (i != NULL) 
    {
        DNode j = head;
        while (j != i) 
        {
            if (j == i->next)
                return 1;
            j = j->next;
        }
        i = i->next;
    }
    return 0;
}
int sumList(DNode head) 
{
    int sum = 0;
    while (head != NULL) 
    {
        sum += head->data;
        head = head->next;
    }
    return sum;
}
void printOddEven(DNode head) 
{
    printf("Odd values: ");
    DNode temp = head;
    while (temp != NULL) {
        if (temp->data % 2 != 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nEven values: ");
    temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
DNode merge(DNode a, DNode b) 
{
    if (a == NULL) 
        return b;
    if (b == NULL) 
        return a;
    if (a->data <= b->data) 
    {
        a->next = merge(a->next, b);
        if (a->next) a->next->prev = a;
        return a;
    } else 
    {
        b->next = merge(a, b->next);
        if (b->next) b->next->prev = b;
        return b;
    }
}
void printList(DNode head) 
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {
    DNode head = NULL;
    DNode head2 = NULL;
    int choice, value;
    do {
        printf("\n---- DOUBLY LINKED LIST MENU ----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node\n");
        printf("4. Reverse List\n");
        printf("5. Find Middle\n");
        printf("6. Sort List\n");
        printf("7. Detect Loop\n");
        printf("8. Sum of Data\n");
        printf("9. Print Odd & Even Values\n");
        printf("10. Merge Another DLL\n");
        printf("11. Print List\n");
        printf("12. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            head = insertBeg(head, value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            head = insertEnd(head, value);
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            head = deleteNode(head, value);
            break;
        case 4:
            head = reverse(head);
            printf("List reversed.\n");
            break;
        case 5: 
            DNode mid = findMiddle(head);
            if (mid) printf("Middle = %d\n", mid->data);
            else printf("List is empty.\n");
            break;
        case 6:
            head = sortList(head);
            printf("List sorted.\n");
            break;
        case 7:
            printf(detectLoop(head) ? "Loop detected!\n" : "No loop.\n");
            break;
        case 8:
            printf("Sum = %d\n", sumList(head));
            break;
        case 9:
            printOddEven(head);
            break;
        case 10:
            printf("Enter values for 2nd list (-1 to stop):\n");
            head2 = NULL;
            while (1) 
            {
                scanf("%d", &value);
                if (value == -1) break;
                head2 = insertEnd(head2, value);
            }
            head = merge(head, head2);
            printf("Lists merged.\n");
            break;
        case 11:
            printList(head);
            break;
        case 12:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 12);
    return 0;
}
