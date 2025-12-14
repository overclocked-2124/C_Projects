typedef struct node {
    int data;
    struct node *next;
} Node;

Node *top = NULL;   // empty stack

void push(int x) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (!temp) {
        printf("Stack Overflow (no memory)\n");
        return;
    }
    temp->data = x;
    temp->next = top;   // new node points to previous top
    top = temp;         // update top
}

int pop(void) {
    if (top == NULL) {
        printf("Stack Underflow (empty)\n");
        return -1;      // or some error code
    }

    Node *temp = top;
    int val = temp->data;

    top = top->next;    // move top down
    free(temp);         // free old top

    return val;
}

int peek(void) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int isEmpty(void) {
    return top == NULL;
}
