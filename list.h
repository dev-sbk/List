#include<stdio.h>
#include<stdlib.h>
typedef enum Boolean{false,true}Boolean;
typedef struct ListElement{
    int value;
    struct ListElement *next;
}ListElement,*List;

List new(void);
Boolean isEmpty(List l);
int length(List l);
List addToFirst(List l ,int x);
List addToLast(List  l  ,int x);
List removeToFirst(List l);
List removeToLast(List l);
List delete(List l, int x);
List deleteRec(List l, int x);
List setLitSym(List l);
void print(List l);