#include <stdio.h>
#include <string.h>
struct library
{
    int accesion;
    char book[100], author[100];
    int price, flag;
};
int main()
{
    int size;
    char author_name[100];
    printf("Enter the number of book entries:\n");
    scanf("%d", &size);
    struct library A[size + 10];
    for (int i = 0; i < size; i++)
    {
        printf("Enter accesion number, the book's name, the author's name, the book's price and its availibility (1: Yes, 0: No) with spaces in between:\n");
        scanf("%d %s %s %d %d", &A[i].accesion, A[i].book, A[i].author, &A[i].price, &A[i].flag);
    }
    int op1;
    start:
    printf("Enter 1 to add a book, enter 2 to display all books, enter 3 for the total number of books, enter 4 to display all books by an author, and anything else to exit.\n");
    scanf("%d", &op1);
    switch (op1)
    {
    case 1:
        printf("Enter accesion number, the book's name, the author's name, the book's price and its availibility (1: Yes, 0: No):\n");
        scanf("%d %s %s %d %d", &A[size].accesion, A[size].book, A[size].author, &A[size].price, &A[size].flag);
        size++;
        break;
    case 2:
        printf("List of all books is:\n\n");
        for (int i = 0; i < size; i++)
        {
            char availibility[10];
            if (A[i].flag == 1)
            {
                strcpy(availibility, "Yes");
            }
            else
            {
                strcpy(availibility, "No");
            }
            printf("Accession number: %d\nBook Name: %s\nAuthor's Name: %s\n", A[i].accesion, A[i].book, A[i].author);
            printf("Price: %d Rs.\nAvailability: %s\n\n", A[i].price, availibility);
        }
        break;
    case 3:
        printf("Number of books are: %d\n", size);
        break;
    case 4:
        printf("Enter the name of the author:\n");
        scanf("%s", &author_name);
        printf("The books by %s are:\n", author_name);
        for (int i = 0; i < size; i++)
        {
            if (strcmp(author_name, A[i].author) == 0)
            {
                printf("%s\n", A[i].book);
            }
        }
        break;
    default:
        printf("Exit");
    }
    printf("Do you want to go back to the main menu? (Enter 1 for Yes and 0 for No.)\n");
    int ch;
    scanf("%d", &ch);
    goto start;
}
