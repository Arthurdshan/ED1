typedef enum boolean{false, true} Boolean;

typedef struct {
	int *vector;
	int length;
	int start;
	int end;
	int size;
}Queue;

Queue *create_queue();
void destroy_queue(Queue *q);
Boolean insert_element(Queue *q, int data);
Boolean remove_element(Queue *q, int* mem_adress); 
Boolean first_element(Queue *q, int* mem_adress); 
Boolean is_empty(Queue *q);
int get_size(Queue *q);
void print_queue(Queue *q);
Queue *clone_queue(Queue *q);
void revert_queue(Queue *q);
Boolean insert_all_elements(Queue *q, int *vector, int length);
