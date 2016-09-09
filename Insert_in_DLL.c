#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Node Node;
struct Node
{
     int data;
     Node *next;
     Node *prev;
};
Node* createNode(int data)
{
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    return n;
}
Node* SortedInsert(Node *head,int data)
{
    Node* temp = createNode(data);
    Node* tempadd = head;
    if(head == NULL)
        head = temp;
    else
    {
        if((temp->data) > (tempadd->data))
        {
            while(tempadd->next != NULL)
            {
                tempadd = tempadd->next;
                if(temp->data < tempadd->data)
                {
                    tempadd = tempadd->prev;
                    break;
                }

            }
                temp->next = tempadd->next;
                tempadd->next = temp;
                temp->prev=tempadd;
        }
        else
        {
            head->prev = temp;
            temp->next=head;
            head = temp;
        }

    }
     return head;
}

int main()
{
    int n,i,n1,j,data;
    scanf("%d",&n);
    for(i = 0; i < n ;i ++)
    {
        Node* head = NULL;
        scanf("%d",&n1);
        for(j = 0; j < n1; j++)
        {
            scanf("%d",&data);
            head = SortedInsert(head,data);
        }
        while(head != NULL)
        {
            printf("%d ",head->data);
            head=head->next;
        }
    }
    return 0;
}
