/* The method push to push element into the queue*/
void MyQueue:: push(int x)
{
        // Your Code
        QueueNode *temp = new QueueNode(x);
        if(rear == NULL)
        {
            rear = front = temp;
            return;
        }
        rear->next = temp;
        rear = rear->next;
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
        // Your Code    
        if(front == NULL)
            return -1;
        QueueNode *temp = front;
        front = front->next;
        
        if(front==NULL)
            rear = NULL;
        return temp->data;
}