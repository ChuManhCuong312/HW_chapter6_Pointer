#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char namebook[100];
    char author[50];
    float price;
} Book;

void inputBookInfo(Book *book) {
    printf("Nhap thong tin cho sach:\n");
    printf("Ten sach: ");
    while (getchar() != '\n'); 
    fgets(book->namebook, sizeof(book->namebook), stdin);

    printf("Tac gia: ");
    fgets(book->author, sizeof(book->author), stdin);

    printf("Gia: ");
    scanf("%f", &book->price);
}

void displayBookInfo(Book *book) {
    printf("Ten sach: %s", book->namebook);
    printf("Tac gia: %s", book->author);
    printf("Gia: %.2f\n", book->price);
}

int main() {
    int numBooks;
    printf("Nhap so luong sach: ");
    scanf("%d", &numBooks);

    Book *bookArray = (Book *)malloc(numBooks * sizeof(Book));

    for (int i = 0; i < numBooks; ++i) {
        inputBookInfo(&bookArray[i]);
    }

    printf("\nThong tin sach da nhap:\n");
    for (int i = 0; i < numBooks; ++i) {
        printf("Sach %d:\n", i + 1);
        displayBookInfo(&bookArray[i]);
        printf("\n");
    }

    free(bookArray);

    return 0;
}

