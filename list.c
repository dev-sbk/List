#include "list.h"
List new(void){
    return NULL;
}
Boolean isEmpty(List l){
    if(l==NULL) return true;
    return false;
}
int length(List l){
    int c=0;
    if(!isEmpty(l)){
        while(!isEmpty(l)){
            c++;
            l=l->next;
        }
    }
    return c;
}
List addToFirst(List l ,int x){
    ListElement *element;
    element=(ListElement *) malloc(sizeof(ListElement));
    if(element==NULL){
        printf("Allocation achouee \n");
        exit(EXIT_FAILURE);
    }
    element->value=x;
    element->next=l;
    return element;
}
List addToLast(List  l  ,int x){
    ListElement *element,*p;
    element=(ListElement *) malloc(sizeof(ListElement));
    if(element==NULL){
        printf("Allocation echouee \n");
        exit(EXIT_FAILURE);
    }
    element->value=x;
    element->next=NULL;
    if(isEmpty(l)) return element;
    p=l;
    while(!isEmpty(p->next)) p=p->next;
    p->next=element;
    return l;
}
List removeToFirst(List l){
    ListElement *tmp;
    if(!isEmpty(l)){
        if(l->next==NULL){
            free(l);
            return new();
        }
        tmp=l;
        l=tmp->next;
        free(tmp);
        return l;
    }
    return new();
}
List removeToLast(List l){
    ListElement *before,*p;
    if(!isEmpty(l)){
        if(l->next==NULL){
          return removeToFirst(l);
        }
        before=l;
        p=before->next;
        while(!isEmpty(p->next)){
           before=p;
           p=p->next;
        }
        before->next=NULL;
        free(p);
        return l;
    }
    return new();
}
List delete(List l, int x){
    ListElement *prev,*p;
    if(!isEmpty(l)){
        if(l->value==x){
            l=removeToFirst(l);
        }
        prev=l;
        p=prev->next;
        while(!isEmpty(p)){
            if(p->value==x){
                prev->next=p->next;
                free(p);
            }else prev=p;
            p=prev->next;

        }
        return l;
    }
    return new();
}
List deleteRec(List l, int x){
    ListElement *p,*prev;
    if(!isEmpty(l)){
       if(l->value==x) l=removeToFirst(l);
       prev=l;
       p=prev->next;
       if(p->value==x){
           prev->next=p->next;
           free(p); 
       }
       p=prev->next;
       deleteRec(p,x);
     }
     return l;
}
List setLitSym(List l){
    List s=new();
    ListElement *p;
    p=l;
    while(!isEmpty(p->next)){
        s=addToFirst(s,p->value);
        p=p->next;
    }
    s=addToFirst(s,p->value);
    p->next=s;
    return l;
}
void print(List l){
     if(isEmpty(l)){
       printf("<----------- LISTE EMPTY-------------->\n");
       exit(EXIT_FAILURE);
     }
    if(!isEmpty(l)){
        printf("<---");
        while(!isEmpty(l->next)){
            printf("[%d]---",l->value);
            l=l->next;
        }
        printf("[%d]---|\n",l->value);
    }
}