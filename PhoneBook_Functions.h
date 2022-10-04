#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char Name[30];
    char Address[100];
    long long int PhoneNumber;
    char Type_PhoneNumber[7];

    struct Node *Link;
};

void Print_All_Nodes(struct Node *Head)
{
    if (Head == NULL)
        printf("\nNo Contacts Are Available in the PhoneBook!\n");
    else
    {
        int Number = 1;

        struct Node *Traversing_Pointer = Head;

        while (Traversing_Pointer != NULL)
        {
            printf("\n%d.\nName: %s", Number, Traversing_Pointer->Name);
            printf("\nAddress: %s", Traversing_Pointer->Address);

            Traversing_Pointer->PhoneNumber == -1 ? printf("\nPhone Number: (Was Skipped).") : printf("\nPhone Number: %d%lld", 0, Traversing_Pointer->PhoneNumber);
            /*
            if (Traversing_Pointer->PhoneNumber == -1)
                printf("\nPhone Number: (Was Skipped).");
            else
                printf("\nPhone Number: %lld", Traversing_Pointer->PhoneNumber);
            */
            printf("\nType of Phone Number: %s", Traversing_Pointer->Type_PhoneNumber);
            printf("\n\n");

            Traversing_Pointer = Traversing_Pointer->Link;
            Number++;
        }
    }
}

void Insert_New_Node(struct Node **Head)
{
    struct Node *Traversing_Pointer = *Head;
    struct Node *Temp_Pointer = NULL;

    if (*Head == NULL) // Linked List is Empty.(No Nodes Were Created Yet)
    {
        *Head = (struct Node *)malloc(sizeof(struct Node));
        Temp_Pointer = *Head;
    }
    else
    {
        while (Traversing_Pointer->Link != NULL)
            Traversing_Pointer = Traversing_Pointer->Link;

        Temp_Pointer = (struct Node *)malloc(2 * sizeof(struct Node));

        Traversing_Pointer->Link = Temp_Pointer;
    }

    Temp_Pointer->Link = NULL;

    getchar(); // Ignore

    printf("\nPlease Enter The Name (for Skip Just Hit Enter): ");
    gets(Temp_Pointer->Name);

    printf("Please Enter The Address (for Skip Just Hit Enter): ");
    gets(Temp_Pointer->Address);

    printf("Please Enter The Phone Number (for Skip Enter Number -1): ");
    scanf("%lld", &(Temp_Pointer->PhoneNumber));

    getchar(); // Ignore

    printf("Please Enter The Type of the Entered Phone Number. It can be Mobile, Home, Work, Fax (for Skip Just Hit Enter): ");
    gets(Temp_Pointer->Type_PhoneNumber);

    printf("\nNew Contact Was Added to the PhoneBook Successfully.\n");
}

int Is_Inside(struct Node *Head, long long int Searching_Number)
{
    if (Head == NULL)
        return 0;
    else
    {
        struct Node *Traversing_Pointer = Head;
        int found = 0;

        while (Traversing_Pointer != NULL)
        {
            if (Traversing_Pointer->PhoneNumber == Searching_Number)
            {
                found = 1;
                break;
            }

            Traversing_Pointer = Traversing_Pointer->Link;
        }

        return found;
    }
}

void Delete_Entire_Node(struct Node **Head)
{
    if (*Head == NULL)
        printf("\nThe PhoneBook is Already Empty.\n");
    else
    {
        long long int Search_PhoneNumber;
        printf("\nPlease Entre The Phone Number Which You'd Like to Delete from the PhoneBook: ");
        scanf("%lld", &Search_PhoneNumber);

        if (Is_Inside(*Head, Search_PhoneNumber))
        {
            int sure_condition = 1;
            printf("\nAll of the Data of the Contact with PhoneNumber %d%lld Will be Completely Deleted from the PhoneBook.\nAre You Sure You Want to Continue (0 for NO, Any Other Number (Like 1) for YES)? ", 0, Search_PhoneNumber);
            scanf("%d", &sure_condition);

            if (sure_condition)
            {

                struct Node *Traversing_Pointer = *Head;
                int Index_Position = 0;

                while (Traversing_Pointer->PhoneNumber != Search_PhoneNumber)
                {
                    Index_Position++;
                    Traversing_Pointer = Traversing_Pointer->Link;
                }

                if (Index_Position == 0)
                {
                    struct Node *Current_Position_Pointer = *Head;

                    *Head = Current_Position_Pointer->Link;

                    free(Current_Position_Pointer);
                    Current_Position_Pointer = NULL;
                }
                else
                {
                    int Save_Index_Position = Index_Position;

                    struct Node *Current_Position_Pointer = *Head;
                    struct Node *Previous_Position_Pointer = *Head;

                    while (Index_Position != 1)
                    {
                        Index_Position--;
                        Previous_Position_Pointer = Previous_Position_Pointer->Link;
                    }

                    while (Save_Index_Position != 0)
                    {
                        Save_Index_Position--;
                        Current_Position_Pointer = Current_Position_Pointer->Link;
                    }

                    Previous_Position_Pointer->Link = Current_Position_Pointer->Link;

                    free(Current_Position_Pointer);
                    Current_Position_Pointer = NULL;
                }

                printf("\nContact with PhoneNumber %d%lld Was Deleted from the PhoneBook.\n", 0, Search_PhoneNumber);
            }
            else
                printf("\nDelete Operation Cancelled.\n");
        }
        else
            printf("\nContact with PhoneNumber %d%lld Was Never Submitted into the PhoneNumber.\n", 0, Search_PhoneNumber);
    }
}

void Edit_Node(struct Node **Head)
{
    if (*Head == NULL)
        printf("\nNo Contacts Are Available Yet.\n");
    else
    {
        int Index_Position;
        printf("\nPlease Enter the Number of Profile Which You'd Like to Edit from the PhoneBook:");
        Print_All_Nodes(*Head);
        printf("Choosen Number: ");
        scanf("%d", &Index_Position);
        Index_Position--;

        struct Node *Traversing_Pointer = *Head;

        while (Index_Position != 0)
        {
            Index_Position--;
            Traversing_Pointer = Traversing_Pointer->Link;
        }

        int type_data;
        printf("\nWhich One of the Data You'd Like to Edit or Remove for this Contact?\n1. Name\n2. Address\n3. Phone Number\n4. Type of Phone Number\nChoosen Number: ");
        scanf("%d", &type_data);

        getchar(); // Ignore

        switch (type_data)
        {
        case 1:
            printf("\nPlease Enter New Name (To Remove it Just Hit Entre): ");
            gets(Traversing_Pointer->Name);
            break;

        case 2:
            printf("\nPlease Enter New Address (To Remove it Just Hit Entre): ");
            gets(Traversing_Pointer->Address);
            break;

        case 3:
            printf("\nPlease Enter New Phone Number (To Remove it Entre -1): ");
            scanf("%lld", &(Traversing_Pointer->PhoneNumber));
            break;

        case 4:
            printf("\nPlease Enter New Type for the Phone Number. It can be Mobile, Home, Work, Fax (To Remove it Just Hit Entre): ");
            gets(Traversing_Pointer->Type_PhoneNumber);
            break;

        default:
            printf("\nInvalid Input for Type of Data! Entered Number Must Be Between 1 to 4.\n");
            break;
        }

        printf("\nEdit Operation Was Successfully Done!\n");
    }
}

void Search_Node(struct Node *Head)
{
    if (Head == NULL)
        printf("\nNo Contacts Are Available!\n");
    else
    {
        long long int Search_PhoneNumber;
        printf("\nPlease Entre The Phone Number Which You'd Like to Search for It's Data: ");
        scanf("%lld", &Search_PhoneNumber);

        struct Node *Traversing_Pointer = Head;
        int Is_Inside = 0;

        while (Traversing_Pointer != NULL)
        {
            if (Traversing_Pointer->PhoneNumber == Search_PhoneNumber)
            {
                Is_Inside = 1;
                break;
            }
            else
                Traversing_Pointer = Traversing_Pointer->Link;
        }

        if (Is_Inside == 1)
        {
            printf("\nName: %s", Traversing_Pointer->Name);
            printf("\nAddress: %s", Traversing_Pointer->Address);
            Traversing_Pointer->PhoneNumber == -1 ? printf("\nPhone Number: (Was Skipped).") : printf("\nPhone Number: %d%lld", 0, Traversing_Pointer->PhoneNumber);
            printf("\nType of Phone Number: %s", Traversing_Pointer->Type_PhoneNumber);
            printf("\n\n");
        }
        else
            printf("\nNo Contacts Were Found With the Entered PhoneNumber.\n");
    }
}