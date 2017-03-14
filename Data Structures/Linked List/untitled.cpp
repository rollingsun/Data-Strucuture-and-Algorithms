

void afterKey(struct node* head, int data, int key){
	node *ptr=head;

	while(ptr->next!=NULL){
		if(ptr->data==key){
			node* newnode=CreateNode();
			newnode->data=data;
			newnode->next=ptr->next;
			ptr->next=newnode;
			break;
		}
		else
			ptr=ptr->next;
	}

	if(ptr->next==NULL){
		node* newnode=CreateNode();
		newnode->data=data;
		newnode->next=NULL;
		ptr->next=newnode;;
	}
}	
