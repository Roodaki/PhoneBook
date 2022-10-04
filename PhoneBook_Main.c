//  Written & Developed by AmirHossein Roodaki

#include "PhoneBook_Functions.h"

int main()
{
    printf("\nWelcome to the PhoneBook.\n\n");

    struct Node *Head = NULL;

    int continue_condition = 1;

    while (continue_condition)
    {
        int task_number;
        printf("\nPlease Choose the Task You Want to Do with the PhoneBook:\n1. New Contact\n2. Delete Contact\n3. Edit Contact\n4. Search Contact\n5. Show All Contacts\n\nChoosen Task: ");
        scanf("%d", &task_number);

        switch (task_number)
        {
        case 1: // Create New Profile (Node) to PhoneBook (Linked List)
            Insert_New_Node(&Head);
            break;

        case 2: // Delete an Profile (Entire Node) from PhoneBook (Linked List)
            Delete_Entire_Node(&Head);
            break;

        case 3: // Edit (Add, Remove) Data from an Existing Profile (Node) of the PhoneBook (Linked List)
            Edit_Node(&Head);
            break;

        case 4: // Search Profile (Node) from the PhoneBook(Linked List) Using PhoneNumber
            Search_Node(Head);
            break;

        case 5: // Show All Profiles & Their Data (All Entered Data of All Created Nodes) of the PhoneBook (Linked List)
            Print_All_Nodes(Head);
            break;

        default:
            printf("\nInvalid Input for Task Number!\nEntered Number Must be Beetwen 1 to 5.\n");
            break;
        }

        printf("\nDo You Want to Continue Using the PhoneBook? (0 for NO, Any Other Number (Like 1) for YES)\nChoosen Number: ");
        scanf("%d", &continue_condition);
    }

    printf("\n\nThanks for Using the PhoneBook.\n\n");

    return 0;
}