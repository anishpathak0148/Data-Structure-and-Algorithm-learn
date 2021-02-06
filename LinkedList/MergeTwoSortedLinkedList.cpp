/*************
 Following is the Node structure already written.

 template <typename T>
 class Node {
	public:
	T data;
	Node* next;
 
	Node(T data) {
 next = NULL;
 this->data = data;
	}
 
	~Node() {
 if (next != NULL) {
 delete next;
 }
	}
 };
 
*************/


Node<int>* merge_list(Node<int>* head1,Node<int>* head2) {
	// Write your code here
    if(head1==NULL)
	return head2;
    if(head2==NULL)
	return head1;
    Node<int>*head = NULL;
    Node<int>*temp = NULL;
    //Node<int>*temp = head1->data > head2->data ? head1:head2;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data > head2->data)
        {
            if(head==NULL)
            {
                head = head1;
                temp = head1;
            }
            else
            {
                temp->next = head1;
                temp = temp->next;
            }
            head1 = temp->next;
        }
        else
        {
            if(head==NULL)
            {
                head = head2;
                temp = head2;
            }
            else
            {
                temp->next = head2;
                temp = temp->next;
            }
            head2 = temp->next;
        }
    }
    if(head1==NULL)
    {
        temp->next = head2;
    }
    if(head2==NULL)
    {
        temp->next = head1;
    }
    return head;
}

