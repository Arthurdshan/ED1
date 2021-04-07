typedef enum boolean{false, true} Boolean;

typedef struct node{
	int data;
	struct node *next;
}Node;

typedef struct {
	Node *top;
	int size;
}Stack;

Stack* create_stack();
void destroy_stack(Stack *s);
Boolean push_element(Stack *s, int data);
Boolean pop_element(Stack *s, int *mem_adress);
Boolean top_element(Stack *s, int *mem_adress);
void print(Stack *s);
int get_size(Stack *s);
Stack *clone_stack(Stack *s);
void revert_stack(Stack *s);
Boolean push_all_elements(Stack *s, int *vector, int size);
