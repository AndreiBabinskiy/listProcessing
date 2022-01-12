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

struct Stack {
    int value;
    Stack* next;
};

void CreateStack(Stack** TMP, Stack** First) {    
    if (*TMP != NULL) {
        puts("Stack created!");
        _getch();
    }
    puts("Put the number of items on the stack:");
    int count;
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        int ran = rand() % 100 - 50;
        printf("Item on the stack: %d\n", ran);
        int firstValue = ran;
        if (*TMP == NULL) {
            *TMP = new Stack;
            (*TMP)->value = firstValue;
            (*TMP)->next = *First;
            *First = *TMP;
        }
        else {
            *TMP = new Stack;
            (*TMP)->value = firstValue;
            (*TMP)->next = *First;
            *First = *TMP;
        }
    }
    _getch();
}

void AddInStack(Stack** TMP, Stack** First, int value) {
    printf("Adding an item: %d\n", value);

    if (*TMP == NULL) {
        *TMP = new Stack;
        (*TMP)->value = value;
        (*TMP)->next = *First;
        *First = *TMP;
    }
    else {
        *TMP = new Stack;
        (*TMP)->value = value;
        (*TMP)->next = *First;
        *First = *TMP;
    }
}

void ViewStack(Stack* First) {
    puts("View Stack:");

    Stack* TMP = First;
    if (First == NULL) {
        puts("Stack is empty!");
        _getch();
    }
    while (TMP != NULL) {
        printf("Element: %d\n", TMP->value);
        TMP = TMP->next;
    }

    _getch();
}

void SolutionOfTheTask(Stack** TMP) {
    if (*TMP == NULL) {
        puts("Stack is empty!");
        _getch();
       
    }
    Stack* current = *TMP;
   
    Stack* positive_start, * positive_tail;
    positive_start = NULL;
    positive_tail = NULL;
    
    Stack* negative_start, * negative_tail;
    negative_start = NULL;
    negative_tail = NULL;
    while (current != NULL) {
        int valueTwo = current->value;
        if (valueTwo > 0) {
           Stack* next_tail;
           next_tail = new Stack;
           next_tail->value = valueTwo;
           if (positive_start == NULL) {
               positive_start = next_tail;
               positive_tail = next_tail;
           }
           else {
               positive_tail->next = next_tail;
           }
           positive_tail = next_tail;
           positive_tail->next = NULL;
        }
     
        if (valueTwo < 0) {
            Stack* new_tail;
            new_tail = new Stack;
            new_tail->value = valueTwo;
            if (negative_start == NULL) {
                negative_start = new_tail;
                negative_tail = new_tail;
            }
            else {
                negative_tail->next = new_tail;
            }
            negative_tail = new_tail;
            negative_tail->next = NULL;
        }
        current = current->next;
    }
    puts("Stack with negative numbers:");
    ViewStack(negative_start);
    puts("Stack with positive numbers:");
    ViewStack(positive_start);
}

void delete_Stack(Stack* First) {
    Stack* tmp;
    while (First) {
        tmp = First;
        First = First->next;
        delete tmp;
    } 
}

void main() {
    setlocale(LC_ALL, "Russian");

    Stack* First, * TMP;

    First = NULL;
    TMP = NULL;

    int menu = 0;

    while (true) {
        system("cls"); 
        puts("1 - CREATE STACK");
        puts("2 - ADD ITEM TO STACK");
        puts("3 - VIEWING THE CONTENTS OF THE STACK");
        puts("4 - SOLUTION DELIVERED TASKS");
        puts("5 - Exit");
        fflush(stdin);
        scanf_s("%d", &menu);

        switch (menu) {
        case 1: {
            CreateStack(&TMP, &First);
            break;
        }
        case 2: {
            int value;
            puts("Enter element:");
            scanf("%d", &value);
            AddInStack(&TMP, &First, value);
            _getch();
            break;
        }
        case 3: {
            ViewStack(First);
            break;
        }
        case 4: {
            puts("Initial Stack:");
            ViewStack(First);
            SolutionOfTheTask(&TMP);
            break;
        }
        case 5: {
            puts("The work is done!");
            delete_Stack(First);
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