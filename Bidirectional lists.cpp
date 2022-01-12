#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <io.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <locale.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>

struct listItem {
    int number;
    struct listItem* next;
    struct listItem* prev;
};

struct listItem* createList(int sizeList) {
    listItem* current = NULL;
    listItem* first = new listItem;
    first->next = NULL;
    first->prev = NULL;
    first->number = rand() % 100;
    for (int i = 0; i < sizeList; i++) {
        current = first;
        first = new listItem;
        current->next = first;
        first->next = NULL;
        first->prev = current;
        first->number = rand() % 100;
    }
    return first;
}
struct listItem* AddingAnItemToTheList(listItem* list, int* size) {
    printf("How mant elements to add ?\n");
    int element;
    scanf("%d", &element);
    listItem* current = NULL;
    listItem* first = new listItem;
    first->next = NULL;
    first->prev = list;
    list->next = first;
    first->number = rand() % 100;
    for (int i = 1; i < element; i++) {
        current = first;
        first = new listItem;
        current->next = first;
        first->next = NULL;
        first->prev = current;
        first->number = rand() % 100;
    }
    *size = element + (*size);
    return first;
}

void printList(listItem* list, int* size) {
    int i = 0;
    printf("Of all items in the list: %d\n", *size);
    while (list->prev != NULL) {
        printf("%d. %d\n", i, list->number);
        i++;
        list = list->prev;
    }
}

struct listItem* min_one(listItem* list, int* size) {
    listItem* tmp = list;
    listItem* min = list;
    listItem* root = list;
    int i = 0;
    while (tmp->prev != NULL) {
        if (min->number > tmp->number) {
            min = tmp;
        }
        root = min;
        tmp = tmp->prev;
        i++;
    }
    printf("Minimum value in the list: %d\n", min->number);

    tmp = list;
    while (tmp->prev != min) {
        tmp = tmp->prev;
    }
    tmp->prev = min->prev;

    tmp = list;
    while (tmp != min->prev) {
        tmp = tmp->prev;
    }
    tmp->next = min->next;
    listItem* first = list;
    first->next = min;
    min->prev = first;
    min->next = NULL;
    return min;
}

void delete_list(listItem* list) {
    listItem* tmp = list;
    while (list) {
        tmp = list;
        list = list->prev;
        delete tmp;
    }
}
void main() {
    setlocale(LC_ALL, "Russian");
    int sizeList;
    int* size = &sizeList;
    listItem* list = NULL;
    int menu = 0;

    while (true) {
        system("cls");
        puts("1 - Создать двунаправленный список");
        puts("2 - Добавление элемента в список");
        puts("3 - Просмотр списка");
        puts("4 - Решение поставленной задачи");
        puts("5 - Выход");
        fflush(stdin);
        scanf_s("%d", &menu);

        switch (menu) {
        case 1: {
            srand(time(NULL));
            puts("Enter the number of items in the two-forked list:");
            scanf("%d", &sizeList);
            list = createList(sizeList);
            printList(list, size);
            printf("\n");
            _getch();
            break;
        }
        case 2: {
            list = AddingAnItemToTheList(list, size);
            _getch();
            break;
        }
        case 3: {
            printList(list, size);
            _getch();
            break;
        }
        case 4: {
            printList(list, size);
            list = min_one(list, size);
            printList(list, size);
            _getch();
            break;
        }
        case 5: {
            puts("The work is done!");
            delete_list(list);
            puts("\nMemory freed!");
            _getch();
            exit(0);
        }
        default: {
            puts("Inappropriate character entered");
            _getch();
        }
        }
    }
}