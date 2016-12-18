#include <stdio.h>
#include <stdlib.h>

struct s_listnode {
    int element;
    struct s_listnode * pnext;
};

struct Stack{
    struct s_listnode *stack_buffer;
};

struct Stack newStack(void){
    struct Stack tmp;
    tmp.stack_buffer = NULL; //start empty
    return tmp;
};

void push(int elem, struct Stack * stack) {
    struct s_listnode *new_node = (struct s_listnode *) malloc(sizeof(struct s_listnode));
    new_node->pnext = stack->stack_buffer;
    new_node->element = elem;
    stack->stack_buffer = new_node;
}

int pop(struct Stack * stack) {
    if (stack->stack_buffer) {
        struct s_listnode *pelem = stack->stack_buffer;
        int elem = stack->stack_buffer->element;
        stack->stack_buffer = pelem->pnext;
        free(pelem);
        return elem;
    } else {
        return 0;  
    }
}

int main(int argc, char *argv[]) {
    //printf("%d\n",&stack_buff);
    struct Stack k = newStack();
    push(9,&k);
    push(10,&k);
    push(7,&k);
    printf("%d\n",pop(&k));
    printf("%d\n",pop(&k));
    printf("%d\n",pop(&k));
    return 0;
}