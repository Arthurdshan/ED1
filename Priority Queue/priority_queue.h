typedef enum boolean { false, true } Boolean;

typedef int DataType;

typedef struct {
	DataType* array;
	int length; 
	int size;
}priority_queue;

priority_queue *create_queue();
void destroy_queue(priority_queue *q);
Boolean insert_in_queue(priority_queue *q, DataType value);
Boolean remove_from_queue(priority_queue *q, DataType *mem_adress); 
Boolean is_empty(priority_queue *q);
int get_size(priority_queue *q);
void print(priority_queue *q);
priority_queue *clone_queue(priority_queue *q);
Boolean insert_all_elements(priority_queue *q, DataType *array, int size);
void promove_element(priority_queue *q, int leaf);
void down_element(priority_queue *q, int root);
void switch_elements(DataType *a, DataType *b);
int root(int j);
int right_leaf(int i);
int left_leaf(int i);
