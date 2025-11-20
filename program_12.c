// Name - Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} *Node;
Node createNode(int value) 
{
    Node newNode = (Node)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Node insertEnd(Node head, int value) 
{
    Node newNode = createNode(value);
    if (head == NULL)
        return newNode;
    Node temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}
Node insertBeg(Node head, int value) {
    Node newNode = createNode(value);
    newNode->next = head;
    return newNode;
}
Node deleteNode(Node head, int value) {
    if (head == NULL)
        return NULL;
    if (head->data == value) 
    {
        Node temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node temp = head;
    while (temp->next!=NULL && temp->next->data!=value)
        temp = temp->next;
    if (temp->next != NULL) 
    {
        Node del = temp->next;
        temp->next = del->next;
        free(del);
    }
    return head;
}
Node reverse(Node head) 
{
    Node prev = NULL;
    Node curr = head;
    while (curr != NULL) {
        Node nextNode = curr->next;
        curr->next = prev;   
        prev = curr; 
        curr = nextNode;  
    }
    return prev;
}
Node findMiddle(Node head) 
{
    if (head == NULL)
        return NULL;
    int count = 0;
    Node temp = head;
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
Node sortList(Node head) 
{
    if (head == NULL)
        return NULL;
    Node i = head;
    while (i != NULL) 
    {
        Node j = i->next;
        while (j != NULL) 
        {
            if (i->data > j->data) 
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    return head;
}
int sumList(Node head) 
{
    int sum = 0;
    while (head != NULL) 
    {
        sum += head->data;
        head = head->next;
    }
    return sum;
}
void printOddEven(Node head) 
{
    Node temp = head;
    printf("Odd values: ");
    while (temp != NULL) 
    {
        if (temp->data % 2 != 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    temp = head;
    printf("\nEven values: ");
    while (temp != NULL) 
    {
        if (temp->data % 2 == 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void printList(Node head) 
{
    Node temp = head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
Node merge(Node a, Node b) 
{
    Node result = NULL;
    if (a == NULL) 
        return b;
    if (b == NULL) 
        return a;
    if (a->data <= b->data) 
    {
        result = a;
        result->next = merge(a->next, b);
    } else 
    {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}
int main() 
{
    Node head = NULL;
    Node head2 = NULL;
    int choice, value;
    do {
        printf("\n----- LINKED LIST MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Reverse List\n");
        printf("5. Find Middle\n");
        printf("6. Sort List\n");
        printf("7. Sum of List\n");
        printf("8. Print Odd & Even Values\n");
        printf("9. Merge Another List\n");
        printf("10. Print List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
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
        case 5: {
            Node mid = findMiddle(head);
            if (mid != NULL)
                printf("Middle element = %d\n", mid->data);
            else
                printf("List is empty.\n");
            break;
        }
        case 6:
            head = sortList(head);
            printf("List sorted.\n");
            break;
        case 7:
            printf("Sum of list = %d\n", sumList(head));
            break;
        case 8:
            printOddEven(head);
            break;
        case 9:
            printf("Enter values for second list (-1 to stop):\n");
            head2 = NULL;
            while (1) {
                scanf("%d", &value);
                if (value == -1) break;
                head2 = insertEnd(head2, value);
            }
            head = merge(head, head2);
            printf("Lists merged.\n");
            break;
        case 10:
            printList(head);
            break;
        case 11:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 11);
    return 0;
}
