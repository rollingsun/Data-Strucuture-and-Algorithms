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

void n_leaves(node* root, int &cnt)
{
	if (root->left == NULL && root->right == NULL) {
		cnt++;
		return; 
	}
	
	if(root->left != NULL) {
		n_leaves(root->left, cnt);
	}
	
	if(root->right != NULL) {
		n_leaves(root->right, cnt);
	}
}

void depth(node* root, int cnt, int &ans)
{
	if (root->left == NULL && root->right == NULL) {
		if (cnt >= ans) {
			ans = cnt;
		}
		return; 
	}
	
	if(root->left != NULL) {
		depth(root->left, cnt+1, ans);
	}
	
	if(root->right != NULL) {
		depth(root->right, cnt+1, ans);
	}
}

node* search(node* root, int p)
{
	if(root->val == p) {
		return root;
	}
	
	node* nw1 = NULL;
	node* nw2 = NULL;
	
	if(root->left != NULL) nw1 = search(root->left, p);
	
	if(root->right != NULL) nw2 = search(root->right, p);
	
	if(nw1 != NULL) {
		return nw1;
	}
	else if(nw2 != NULL) {
		return nw2;
	} 
	else {
		return NULL;
	}
}

node* search2(node* root, int p)
{
	if(root->left != NULL && root->left->val == p) {
		return root;
	}
	if(root->right != NULL && root->right->val == p) {
		return root;
	}
	
	node* nw1 = NULL;
	node* nw2 = NULL;
	
	if(root->left != NULL) nw1 = search2(root->left, p);
	
	if(root->right != NULL) nw2 = search2(root->right, p);
	
	if(nw1 != NULL) {
		return nw1;
	}
	else if(nw2 != NULL) {
		return nw2;
	} 
	else {
		return NULL;
	}
}

bool isfather(node* root, int p, int q)
{
	node* nw = search(root, p);
	
	if(nw != NULL) {
		if(nw->left != NULL && nw->left->val == q) {
			return 1;
		}
		if(nw->right != NULL && nw->right->val == q) {
			return 1;
		}
		return 0;
	}
	else {
		return 0;
	}
}

bool isSiblings(node* root, int p, int q)
{
	node* nw = new node;
	if(root->val == p) {
		nw = root;
	}
	else {
		nw = search2(root, p);
	}
	
	if(nw->left != NULL && nw->left->val == q) {
		return 1;
	}
	else if(nw->right != NULL && nw->right->val == q) {
		return 1;
	}
	else {
		return 0;
	}
}
 
int main()
{
	printf("No. of elements: ");
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
    
    //print(root,n);
    
    int cnt = 0;
    if(root == NULL) {
    	printf("No. of leaves = 0 \n");
    }
    else {
    	n_leaves(root, cnt);
		printf("No. of leaves = %d \n", cnt);	
    }
    
    int ans = 0;
    cnt = 0;
    depth(root, cnt, ans);
    printf("Depth of tree = %d \n", ans);
    
    int p,qq;
    printf("To check if 'p' is father of 'q', enter p and q: ");
    scanf("%d %d", &p, &qq);
    if(isfather(root, p, qq)) {
    	printf("Yes \n");
    }
    else {
    	printf("No \n");
    }
    
    printf("To check if p and q are siblings, enter p and q: ");
    scanf("%d %d", &p, &qq);
    if(isSiblings(root, p, qq)) {
    	printf("Yes \n");
    }
    else {
    	printf("No \n");
    }
 
    return 0;
}
