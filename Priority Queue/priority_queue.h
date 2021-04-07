typedef enum boolean { false, true } Boolean;

typedef struct {
	int* array;
	int length; 
	int size;
}priority_queue;

priority_queue *create_queue();
void destroy_queue(priority_queue *q);
Boolean insert_in_queue(priority_queue *q, int value);
Boolean remove_from_queue(priority_queue *q, int *mem_adress); 
Boolean is_empty(priority_queue *q);
int get_size(priority_queue *q);
void print(priority_queue *q);
priority_queue *clone_queue(priority_queue *q);
Boolean insert_all_elements(priority_queue *q, int *array, int size);
void promove_element(priority_queue *q, int leaf);
void down_element(priority_queue *q, int root);
void switch_elements(int *a, int *b);
int root(int j);
int right_leaf(int i);
int left_leaf(int i);
