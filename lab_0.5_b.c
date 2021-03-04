#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    char symbol;
    struct Node *next;
} Node;


char pop(Node **head);
Node* getNth(Node* head, int n);
int push(Node **pptr);
void deleteList(Node **head);
void outputList(Node *list);
void delBlank(Node *list);
void reverseSymb(Node *list);
char deleteNth(Node **head, int n);
void insert(Node *head, unsigned n, char val);


int main()
{

    Node *head = NULL;
    while(printf("Enter string: "), push(&head))
    {
        outputList(head);
        delBlank(head);
        outputList(head);
        deleteList(&head);
    }
    return 0;
}

void deleteList(Node **head) {
    Node* prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}

int push(Node **pptr)
{
    char buf[81], *str;
    Node head = {'*', NULL };
    Node *last = &head;
    int n, rc = 1;
    do{
        n = scanf("%80[^\n]", buf);
        if(n < 0){
            deleteList(&head.next);
            head.next = NULL;
            rc = 0;
            continue;
        }
        if(n > 0){
            for(str = buf; *str != '\0'; ++str)
            {
                last->next = (Node *)malloc(sizeof(Node));
                last = last->next;
                last->symbol = *str;
            }
            last->next = NULL;
            }
        else
            scanf("%*c");
    }while(n > 0);
    *pptr = head.next;
    return rc;
}

void outputList(Node *list)
{
    while(list) {
        printf("%c", list->symbol);
        list = list->next;
    }
    printf("\n");
}


Node* getNth(Node* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}


char pop(Node **head) {
    Node* prev = NULL;
    char val;
    if (head == NULL) {
        return -1;
    }
    prev = (*head);
    val = prev->symbol;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

char deleteNth(Node **head, int n) {
    if (n == 0) {
        return pop(head);
    } else {
        Node *prev = getNth(*head, n-1);
        Node *elm  = prev->next;
        char val = elm->symbol;
        prev->next = elm->next;
        free(elm);
        return val;
    }
}


void insert(Node *head, unsigned n, char val) {
    unsigned i = 0;
    Node *tmp = NULL;
    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (Node*) malloc(sizeof(Node));
    tmp->symbol = val;
    if (head->next) {
        tmp->next = head->next;
    } else {
        tmp->next = NULL;
    }
    head->next = tmp;
}

void delBlank(Node *list)
{
    while(list)
    {
        if(list->symbol == ' ')
        {
            list = list->next;
            pop(&list);
        }
        else{list = list->next;}
    }
}
