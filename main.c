#include "list.c"
int main(void){
    List l=new();
    l=addToLast(l,5);
    l=addToLast(l,4);
    l=addToLast(l,3);
    l=addToLast(l,2);
    l=addToLast(l,1);
    l=setLitSym(l);
    print(l);
    return EXIT_SUCCESS;
}