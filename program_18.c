//Name - Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TrieNode 
{
    struct TrieNode *child[26];
    int isEnd;
};
struct TrieNode* createNode() 
{
    struct TrieNode *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEnd = 0;
    for(int i = 0; i < 26; i++)
        node->child[i] = NULL;
    return node;
}
void insert(struct TrieNode *root, char word[]) 
{
    struct TrieNode *temp = root;
    int i, index;
    for(i = 0; word[i] != '\0'; i++) 
    {
        index = word[i] - 'a';
        if(temp->child[index] == NULL)
            temp->child[index] = createNode();
        temp = temp->child[index];
    }
    temp->isEnd = 1;
}
int search(struct TrieNode *root, char word[]) 
{
    struct TrieNode *temp = root;
    int index, i;
    for(i = 0; word[i] != '\0'; i++) {
        index = word[i] - 'a';
        if(temp->child[index] == NULL)
            return 0;
        temp = temp->child[index];
    }
    return temp->isEnd;
}
int main() 
{
    struct TrieNode *root = createNode();
    int choice;
    char word[50];
    do {
        printf("\n1.Insert\n2.Search\n3.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
                printf("Enter word: ");
                scanf("%s", word);
                insert(root, word);
                break;
            case 2:
                printf("Enter word to search: ");
                scanf("%s", word);
                if(search(root, word))
                    printf("Word FOUND\n");
                else
                    printf("Word NOT FOUND\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
        }
    } while(choice != 3);
    return 0;
}
