#include <cstdio>
#include <cstdlib>

struct node {
    int val;
    node *right,*left;
};
 
struct Queue {
    int front, rear;
    int size;
    node* *array;
};
 
 
node* get_node(int val)
{
    node* nw = new node;
    nw->val = val;
    nw->left = NULL;
	nw->right = NULL;
    return nw;
}
 
Queue* create_Queue(int size)
{
    Queue* q = new Queue;
 
    q->front = -1;
	q->rear = -1;
    q->size = size;
 
    q->array = (node**) malloc(q->size * sizeof( node* ));

    for (int i = 0; i < size; ++i)
    {
    	 q->array[i] = NULL;
    }
    return q;
}
 
bool empty(Queue* q)
{
    return q->front == -1;
}
 
bool full(Queue* q)
{  
	return q->rear == q->size - 1; 
}
 
bool singleton(Queue* q)
{  
	return q->front == q->rear;  
}
 
void enqueue(node *root, Queue* q)
{
    if (full(q))
        return;
 
    q->array[++q->rear] = root;
 
    if (empty(q))
        ++q->front;
}
 
node* dequeue(Queue* q)
{
    if (empty(q))
        return NULL;
 
    node* nw = q->array[q->front];
 
    if (singleton(q))
        q->front = q->rear = -1;
    else
        ++q->front;
 
    return nw;
}
 
node* get_front(Queue* q)
{
   return q->array[q->front]; 
}

int two_child(node* nw)
{
    return (nw && nw->left && nw->right);
}
 
void insert(node **root, int val, Queue* q)
{
    node *nw = get_node(val);
 
    if (!(*root)) {
    	*root = nw;
    }
 
    else {
        node* front = get_front(q);
 
        if (!front->left) {
        	front->left = nw;
        }
        else if (!front->right) {
        	front->right = nw;
        }
    
        if (two_child(front)) {
        	dequeue(q);
        }
    }
 
    enqueue(nw, q);
}
 
void print(node* root, int size)
{
    Queue* q = create_Queue(size);
 
    enqueue(root, q);
 
    while (!empty(q))
    {
        node* nw = dequeue(q);
 
        printf("%d ", nw->val);
 
        if (nw->left) {
            enqueue(nw->left, q);
        }
        if (nw->right) {
            enqueue(nw->right, q);
        }
    }
}
 
int main()
{
	printf("Enter no. of elements: ");
	int n;
	scanf("%d",&n);
    node* root = NULL;
    Queue* q = create_Queue(n);
 
 	int x;
    for(int i = 0; i < n; ++i) 
    {
    	scanf("%d",&x);
    	insert(&root, x, q);
    }
    
    print(root,n);
 
    return 0;
}
