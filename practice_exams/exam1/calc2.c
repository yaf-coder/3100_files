#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedlist.h"

node* addition(node* num1, node* num2) {
    node* result = new_node(0);
    node* current = result;
    int carry = 0;
    //TODO: Write code to add two numbers represented by num1 and num2
    while (num1 != NULL || num2 != NULL || carry){
        int temp = carry;
        if (num1!=NULL) temp += num1->v;
        if (num2!=NULL) temp += num2->v;

        carry = temp/10;
        current->v = temp%10;
        
        if (num1->next != NULL || num2->next != NULL || carry) {
            current->next = new_node(0);
            current = current->next;
        }
        
        if (num1!=NULL) num1 = num1->next;
        if (num2!=NULL) num2 = num2->next;
    }

    return result;
}

node* subtraction(node *num1,node *num2){
    node *result = new_node(0);
    node* current = result;
    int borrow = 0;
    //TODO: Write code to subtract num2 from num1
    while (num1 != NULL || num2 != NULL || borrow){
        int temp = num1->v - borrow;
        if (num2 != NULL) {
            temp -= num2->v;
        }

        if (temp < 0){
            temp += 10;
            borrow = 1;
        }
        else borrow = 0;
        current->v = temp%10;
        current->next = new_node(0);
        current = current->next;
        
        if (num1 != NULL) num1 = num1->next;
        if (num2 != NULL) num2 = num2->next;
    }
    
    return result;
}


node *remove_leading_zeros(node *num){
    node *temp = num;
    while(temp!=NULL && temp->v == 0){
        node *temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
    return temp;
}

int main(int argc,char *argv[]){
    if(argc < 3){
        printf("Usage: ./calculator number1 number2\n");
        exit(0);
    }
    node *num1=NULL,*num2 = NULL;
    node *sum = NULL;
    node *difference = NULL;

    for(int i=0;i<strlen(argv[1]);i++){
        if(!isdigit(argv[1][i])){
            printf("Invalid inputin number1\n");
            exit(0);
        }
        num1 = prepend(num1,new_node(argv[1][i]-'0'));
    }
    for(int i=0;i<strlen(argv[2]);i++){
        if(!isdigit(argv[2][i])){
            printf("Invalid input in number2\n");
            exit(0);
        }
        num2 = prepend(num2,new_node(argv[2][i]-'0'));
    }
    sum = addition(num1,num2);
    difference = subtraction(num1,num2);

    sum = remove_leading_zeros(sum);
    difference = remove_leading_zeros(difference);
    
    print_list(sum);
    print_list(difference);

    delete_list(num1);
    delete_list(num2);
    delete_list(sum);
    delete_list(difference);
    return 0;
}
