#include "linked_list.h"

//create a node with value v
node * create_node(int v) 
{
    node	* p = malloc(sizeof(node)); // Allocate memory
    assert(p != NULL);		// you can be nicer
    
    // Set the value in the node. 
    p->v = v;		
    p->next = NULL;  
    return p;			// return
}

//TODO:
void insert(node **head, node *newnode)
{
    if((*head) == NULL)
    {
		*head = (newnode);
    }
    node *p = (*head);
	node *q = p;
	while(p->next != NULL && newnode->v > p->v)
	{
		if (newnode->v <= p->next->v){ // this checks if the value is less than or equal tothe next one, meaning we found the gap it belongs in.
			node *temp = p->next; // using a temp, we are able to set the next of p equal to the new node, and the next of new node to the old next of p.
			p->next = newnode;
			newnode->next = temp;
		}
		else{
			p = p->next;
		}

	}
	if(newnode->v > p->v)
	{ // we only get here if next becomes NULL, in which case the list is done, and we append it to the end.
		p->next = newnode;
	}
	//fill in code below

	return;
}

//add newnode the last of the linked list determined by *head and *tail
//note **head, **tail
void insert_last(node **head, node **tail, node *newnode)
{
	if((*head) == NULL)
	{
		(*head) = (*tail) = newnode;
	}
	else
	{
		(*tail)->next = newnode;
		(*tail) = newnode;
	}
}

//remove the first node from the list
//note **head
//return a pointer to the removed content

node * remove_first(node **head) 
{
        node *p;

        p = (*head);
        if((*head)!=NULL) (*head) = (*head)->next;
        return p;
}

//print the list pointed by head
void print_list(node *head)
{
	node *p = head;

	while(p!=NULL)
	{
		printf("%d ", p->v);
		p = p->next;
	}
	printf("\n");
}

//TODO
//merge two sorted linked list as one
node * merge(node **p1, node **p2)
{
	node *head = NULL, *tail = NULL;
	node *q1 = (*p1), *q2 = (*p2), *p;

	if(q1 == NULL && q2 == NULL) return NULL;
	if(q1 != NULL && q2 == NULL) 
	{
		p = q1;
		(*p1) = NULL;
		return p;
	}
	if(q1 == NULL && q2 != NULL) 
	{
		p = q2;
		(*p2) = NULL;
		return p;
	}

	while(q1 != NULL && q2!= NULL) // we never increment q1, so this goes till we increment through list two, and adds the the element
	// we are on using the insert() function.
	{
		// head = q1;
		insert (head, q2);
		// tail = q2;
		q2 = q2->next;

		// I troubleshooted this code, and the head and tail assignments get it stuck.
	}
	while(q1 != NULL) // this is triggered when the previous step is done, and now we increment through list one to set the tail
	{
		head = q1;
		if (tail->next!=NULL){
			tail = tail->next;
		}
		else{
			break;
		}
	}
	while(q2 != NULL) // this should never be triggered (q1 is null and q2 isn't), but if it somehow is, we again find the tail (we set the head in advance)
	{	
		head = q2;
		if (tail->next!=NULL){
			tail = tail->next;
		}
		else{
			break;
		}
	}
	//fill in code below
	// I cannot figure out what there is to fill here. The two lists should be merged, and by returning the head, we return the pointer to the head of the merged list.
	return 	head;
}
int main(int argc, char *argv[])
{
	assert(argc == 2);
	int n = atoi(argv[1]);
	
	int a[n];
	int b[n];
	
	for(int i = 0; i < n; i++)
	{
		a[i] = i;
		b[i] = 2*i;
	}

	node *p1 = NULL, *p2 = NULL;

	for(int i = 0; i < n; i++)
	{
		node *p = create_node(a[i]);
 		insert(&p1, p);
	}
	print_list(p1);

	for(int i = 0; i < n; i++)
    {
        node *p = create_node(b[i]);
        insert(&p2, p);
    }
	print_list(p2);
	
	node *p = merge(&p1, &p2);
	print_list(p);
	printf("%p\n", p1);
	printf("%p\n", p2);

	//TODO
	//fill in code below
	printf("%p\n", p);

	return 0;
}
