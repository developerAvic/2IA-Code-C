
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void book_insert();
void book_delete();
void display();
void search();

int main()
{
    int choice;
    
    // Create a header node to keep track of count
    struct node *header = (struct node *)malloc(sizeof(struct node));
    header->data = 0;        // stores total number of books returned
    header->next = NULL;
    head = header;
    
    while(1)
    {
        printf("\n1. Insert book in beginning");
        printf("\n2. Delete book from Beginning");
        printf("\n3. Search for a book ID");
        printf("\n4. Show all returned book IDs");
        printf("\n5. Total returned books");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                book_insert();
                break;
                
            case 2:
                book_delete();
                break;
                
            case 3:
                search();
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                printf("\nTotal number of nodes: %d\n", header->data);
                break;
                
            case 6:
                // Free the entire list before exiting (optional improvement)
                while(head->next != NULL) {
                    book_delete();
                }
                free(head);
                exit(0);
                
            default:
                printf("Please enter a valid choice..\n");
        }
    }
    
    return 0;  // Never reaches here due to exit(0) in case 6
}

void book_insert()
{
    struct node *ptr;
    int item;
    
    ptr = (struct node *)malloc(sizeof(struct node));
    
    if(ptr == NULL)
    {
        printf("\nMemory overflow\n");
    }
    else
    {
        printf("\nEnter book ID: ");
        scanf("%d", &item);
        
        ptr->data = item;
        ptr->next = head->next;
        head->next = ptr;
        head->data++;  // increment count
        
        printf("\nReturned Book ID Inserted to the list\n");
    }
}

void book_delete()
{
    struct node *temp;
    
    if(head->next == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp = head->next;
        head->next = temp->next;
        free(temp);
        
        head->data--;  // decrement count
        
        printf("\nBook ID deleted from the beginning for shelving...\n");
    }
}

void search()
{
    struct node *temp;
    int key, i = 1;
    
    if(head->next == NULL)
    {
        printf("\nEmpty List\n");
        return;
    }
    
    printf("\nEnter book ID which you want to search: ");
    scanf("%d", &key);
    
    temp = head->next;
    
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("Book ID found at location %d\n", i);
            return;
        }
        i++;
        temp = temp->next;
    }
    
    printf("Book ID not found\n");
}

void display()
{
    struct node *temp;
    
    if(head->next == NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        printf("\nPrinting IDs of books...\n");
        temp = head->next;
        
        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
