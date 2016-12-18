/*
 *  Name:           
 *  Author:         Michel Cantacuzene
 *  Version:        0.1
 *  Description:    Assignment 3 program. Turns Infix notation into a Postfix (reverse polish) notation.
 *  Specifications: this program can only parse integers, and specific operators. Do not use paretheses or unary operators.
 */

#include <stdio.h>
#include <stdlib.h>

struct s_listnode { //standard struct used for both Stack and Queue
    char element;
    struct s_listnode * pnext;
};

struct Queue { //Queue structure to facilitate reading and modulability
    struct s_listnode *queue_buffer;
    struct s_listnode *prear;
};

struct Stack{ //Stack structure to facilitate reading and modulability
    struct s_listnode *stack_buffer;
};

//functions for the queue
struct Queue newQueue(void); //function to create a new Queue
void enqueue(char elem, struct Queue * data); //function to append to the Queue
char dequeue(struct Queue * data); //function to remove an element from the Queue

// functions for the stack
struct Stack newStack(void); //function to create a new Stack
void push(char elem, struct Stack * stack); //function to pus an element to the stack
char pop(struct Stack * stack); //function to pop an element from the stack

// sunting yard algorithm and it's dependencies
void shuntingYard(int argc,char *argv[]); //full shunting yard algorithm implementation
void operatorHandle(char element, struct Stack * stack, struct Queue * queue); //function to handle operator comparison and adding them to the stack
int precedence(char element); //function to associate the correct precedence to the operator

int main(int argc, char *argv[]){ //main function that is executed
    if(argc == 1){printf("Error. Empty input.\nUsage: ./executable <operation>\nUse only integers and the folowing operators\n\t+ for addition\n\t- for substraction\n\tx for product \n\t/ for division\n\t^ for power\nDo not use any unary operators or parentheses\n");exit(1);}
    shuntingYard(argc,argv);
    return 0; //returning 0 since EXIT_SUCCESS doesn't compile with (my version of) gcc
}

void shuntingYard(int argc, char *argv[]){ //full shuniting yard algorithm implementation
    struct Queue outputQueue = newQueue(); //create the output queue
    struct Stack operatorStack = newStack(); //create the operator stack
    int i,j;
    char tmp,counter=1;
    for (i=1; i<argc; i++){
        j=0;
        while (argv[i][j] != '\0'){
            if(argv[i][j]<=57 && argv[i][j]>=48){ //using ascii codes to determine whether is is an operator or a operand
                enqueue(argv[i][j],&outputQueue); //case that it is an operand
                counter=0;
            }else {
                if(counter==1){
                    printf("Error. Unary operator detected.\nUsage: ./executable <operation>\nUse only integers and the folowing operators\n\t+ for addition\n\t- for substraction\n\tx for product \n\t/ for division\n\t^ for power\nDo not use any unary operators or parentheses\n");
                    break;
                } else {
                    enqueue(32,&outputQueue); // case that it is an operator
                    operatorHandle(argv[i][j],&operatorStack,&outputQueue);
                    counter=1;
                }
            }
            j++;
        }
    }
    
    //displaying the result
    printf("postfix: ");
    tmp = pop(&operatorStack);
    while(tmp != 0){ //adding the remaining operators to the output Queue
        enqueue(32,&outputQueue);
        enqueue(tmp,&outputQueue);
        tmp = pop(&operatorStack);
    }
    tmp = dequeue(&outputQueue);
    while(tmp != 12){ //12 was chosen arbitrarily ...
        printf("%c",tmp); //print the result on the console
        tmp = dequeue(&outputQueue);
    }
    printf("\n"); //print a new line to make thing beutiful
}

void operatorHandle(char element, struct Stack * stack, struct Queue * queue){ //function to handle the operators and the operator stack
    char tmp = pop( stack);
    if(tmp == 0 || precedence(element) > precedence(tmp) || precedence(element)==3){ //check precedence and list posibilities
        push(tmp,stack);
        push(element,stack);
    } else if(precedence(element)<=precedence(tmp)){
        enqueue(tmp,queue);
        enqueue(32,queue);
        operatorHandle(element,stack,queue); //recursively check through all of the elements in the stack
    }
}

int precedence(char element) { //function to get the precedence of an operator or return an error
    switch (element){
        case 120 :
            return 2;
        case 43 :
            return 1;
        case 45 :
            return 1;
        case 47 :
            return 2;
        case 94 :
            return 3;
        default:
            printf("Error. Incorrect input.\nUse only integers and the folowing operators\n\t+ for addition\n\t- for substraction\n\tx for product \n\t/ for division\n\t^ for power\nDo not use any unary operators\n"); //return an error since what was inputed is not a correct operator
            exit(1); //exit with an error.
    }
    
}

struct Queue newQueue(void){ //function to create a new Queue
    struct Queue data;
    data.queue_buffer = NULL;
    data.prear = NULL;
    return data;
}

void enqueue(char elem,struct Queue * data) { //function to aff a value to a specific Queue
    struct s_listnode *new_node = (struct s_listnode *) malloc(sizeof(struct s_listnode));
    new_node->element = elem;
    new_node->pnext = NULL; // at rear
    if (data->prear){
        data->prear->pnext = new_node;
    } else {
        data->queue_buffer = new_node;
    }
    data->prear = new_node;
}

char dequeue(struct Queue * data) { //function to remove the top element from a specific Queue
    if (data->queue_buffer) {
        struct s_listnode *pelem = (data->queue_buffer);
        char elem = data->queue_buffer->element;
        data->queue_buffer = pelem->pnext;
        if (pelem == (data->prear)){
            data->prear = NULL;
        }
        free(pelem);
        return elem;
    } else {
        return 12; //return 12 if no value
    }
}

struct Stack newStack(void){ //function to create a new stack
    struct Stack tmp;
    tmp.stack_buffer = NULL; //start empty
    return tmp;
}

void push(char elem, struct Stack * stack) { //function to append a element ot the top of a specific Stack
    struct s_listnode *new_node = (struct s_listnode *) malloc(sizeof(struct s_listnode));
    new_node->pnext = stack->stack_buffer;
    new_node->element = elem;
    stack->stack_buffer = new_node;
}

char pop(struct Stack * stack) { //function to pop the top element from a specific stack
    if (stack->stack_buffer) {
        struct s_listnode *pelem = stack->stack_buffer;
        char elem = stack->stack_buffer->element;
        stack->stack_buffer = pelem->pnext;
        free(pelem);
        return elem;
    } else {
        return 0;  
    }
}
