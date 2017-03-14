#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stack>
  
struct node {
    int val;
    struct node *left, *right;
};
  
node* new_node(int data)
{
    node* nw =  new node;
    nw->val = data;
    nw->left = NULL;
	nw->right = NULL;
    return nw;
}
  
void preorder(node* root)
{
    if (root != NULL)
    {
    	printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void postorder(node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
}
  
node* insert(node* node, int val)
{
    if (node == NULL) return new_node(val);
 
    if (val < node->val) {
        node->left  = insert(node->left, val);
    }
    else if (val > node->val) {
        node->right = insert(node->right, val);   
    }
 
    return node;
}

node* min_node(node* root)
{
    node* current = root;
 
    while (current->left != NULL)
    {
        current = current->left;
	}
    return current;
}
 
node* delete_node(node* root, int val)
{
    if (root == NULL) return root;
 
    if (val < root->val) {
        root->left = delete_node(root->left, val);
    }
    else if (val > root->val) {
        root->right = delete_node(root->right, val);
    }
    else {
        if (root->left == NULL)
        {
            node* nw = root->right;
            free(root);
            return nw;
        }
        else if (root->right == NULL)
        {
            node* nw = root->left;
            free(root);
            return nw;
        }
 
        node* nw = min_node(root->right);
 
        root->val = nw->val;
 
        root->right = delete_node(root->right, nw->val);
    }
    return root;
}

void nr_preorder(node* root)
{
    if (root == NULL) return;
 
    std::stack<node*> stk;
    stk.push(root);
 
    while (!stk.empty())
    {
        node* nw = stk.top();
        printf ("%d ", nw->val);
        stk.pop();
 
        if (nw->right) {
            stk.push(nw->right);
        }
        if (nw->left) {
            stk.push(nw->left);
        }
    }
} 

void nr_inorder(node* root)
{
	std::stack<node*> stk;
  	node* current = root;
 
  	while (1)
  	{
    	if(current !=  NULL)
    	{
    	 	stk.push(current);                                              
      		current = current->left;  
    	}
        
    	else {
      		if (!stk.empty()) {
        		current = stk.top();
        		stk.pop();
        		printf("%d ", current->val);
        		current = current->right;
      		}
      		else {
      			break;
      		} 
    	}
  	}  
}   

void nr_postorder(node* root)
{
	std::stack<node*> stk;
    if (root == NULL) return;

    do
    {
        while (root)
        {
            if (root->right) {
            	stk.push(root->right);
            }
            stk.push(root);
            root = root->left;
        }
   
        root = stk.top();
        stk.pop();
 		
 		node* nw = new node;
 		if(stk.empty()) nw = NULL;
 		else nw = stk.top();
 		
        if (root->right && nw == root->right) {
            stk.pop();
            stk.push(root);
            root = root->right; 
        }
        else  {
            printf("%d ", root->val);
            root = NULL;
        }
    } while (!stk.empty());
}
  
int main()
{
    node* root = NULL;
    int n;
    printf("No. of elements: ");
    scanf("%d",&n);
    
    int x;
    for(int i = 0; i < n; i++)
    {
    	scanf("%d",&x);
    	root = insert(root,x);
    }
    
    printf("Preorder Traversal Recursive: \n");
    preorder(root);
    printf("\n");
    printf("Preorder Traversal Non-Recursive: \n");
    nr_preorder(root);
    printf("\n");
    
    printf("Inorder Traversal Recursive: \n");
    inorder(root);
    printf("\n");
    printf("Inorder Traversal Non-Recursive: \n");
    nr_inorder(root);
    printf("\n");
    
    printf("Postorder Traversal Recursive: \n");
    postorder(root);
    printf("\n");
    printf("Postorder Traversal Non-Recursive: \n");
    nr_postorder(root);
    printf("\n");
    
    printf("Enter the number to delete: ");
    scanf("%d", &x);
    root = delete_node(root, x);
    
    printf("Preorder Traversal: \n");
    preorder(root);
    printf("\n");
    
    printf("Inorder Traversal: \n");
    inorder(root);
    printf("\n");
    
    printf("Postorder Traversal: \n");
    postorder(root);
    printf("\n");
  
    return 0;
}
