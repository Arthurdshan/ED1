typedef enum boolean{false, true} Boolean;

typedef struct node{
	int data;
	struct node *prox;
}Node;

typedef struct {
	Node *start;
	Node *end;
	int size;
}Queue;

Queue *create_queue();
void destroy_queue(Queue *q);
Boolean insert_element(Queue *q, int data);
Boolean remove_element(Queue *q, int *mem_adress);
Boolean first_element(Queue *q, int *mem_adress); 
int get_size(Queue *q);
void print(Queue *q);
void revert_queue(Queue *q);
Boolean insert_all_elements(Queue *q, int *vetor, int length);
Boolean is_empty(Queue *q);

