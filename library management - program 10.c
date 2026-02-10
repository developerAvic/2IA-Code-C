#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};
typedef struct list node;
node *head = NULL;


void book_insert() {
    node *ptr; // This will hold the memory address of the new book we are about to create.
    int item; // temporarily store the Book ID entered by the user.
    
    ptr = (node *)malloc(sizeof( node)); // block of memory large enough to hold one node

    printf("\nEnter book ID: ");
    scanf("%d", &item);
    
    ptr->data = item; // Takes the ID the user just typed (item) and stores it inside the data field of our new node.
    ptr->next = head->next;  // This sets the new node's "next" pointer to point to whatever the head was previously pointing to. This ensures the rest of the existing list isn't lost.
    head->next = ptr;  // This updates the head node to point to our new node. Effectively, this inserts the new book at the very beginning of the list (right after the header).
    head->data++; // to keep track of the total number of books
    
    printf("\nReturned Book ID Inserted to the list\n");
}

void book_delete() {
    node *temp;  // Creates a temporary pointer called temp. We need this to "hold onto" the node we are about to delete so we can properly free its memory later.
    
    if(head->next == NULL)
        printf("\nList is empty\n");
    else {
        temp = head->next; // Sets temp to point to the first actual book node in the list (the one immediately following the head).
        head->next = temp->next;  // It tells the head to skip over the first node and point directly to the second node in the list. Even though the node is still in memory, it is now "unlinked" from the list.
        free(temp);
        
        head->data--;
        
        printf("\nBook ID deleted from the beginning for shelving...\n");
    }
}

void search() {
    node *temp;
    int key, i = 1; // i is a counter initialized to 1 to track the "position" or "location" of the book in the list.
    
    if(head->next == NULL) { // if theres nothing after head, then its empty
        printf("\nEmpty List\n");
        return;
    }
    printf("\nEnter book ID which you want to search: ");
    scanf("%d", &key);
    
    temp = head->next; // Starts the search at the first actual data node (skipping the header node).
    
    while(temp != NULL) { // not end of list
        if(temp->data == key) {
            printf("Book ID found at location %d\n", i);
            return;
        }
        i++; // increment the counter
        temp = temp->next; // move the temp pointer to the next node in the sequence.
    }
    printf("Book ID not found\n");
}

void display() {
    node *temp;
    
    if(head->next == NULL) // if theres nothing after head, then its empty
        printf("Nothing to print\n");
    else {
        printf("\nPrinting IDs of books...\n");
        temp = head->next; // point to the first book after header node
        
        while(temp != NULL) {  // not end of list
            printf("%d\n", temp->data); // print book id of current node
            temp = temp->next; // point to next node
        }
    }
}

int main() {
    int choice;
    node *header = (node *)malloc(sizeof(node));
    header->data = 0;
    header->next = NULL;
    head = header;
    
    while(1) {
        printf("\n1. Insert book in beginning");
        printf("\n2. Delete book from Beginning");
        printf("\n3. Search for a book ID");
        printf("\n4. Show all returned book IDs");
        printf("\n5. Total returned books");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                book_insert(); break;
            case 2:
                book_delete(); break;
            case 3:
                search(); break;
            case 4:
                display(); break;
            case 5:
                printf("\nTotal number of nodes: %d\n", header->data);  break;
            case 6:
                free(head);  exit(0);
            default:
                printf("Please enter a valid choice..\n");
        }
    }
    return 0;
}
