/* 

The structure of the class is
class MyQueue {
private:
    int arr[10001];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

/* The method push to push element into the queue */
void MyQueue :: push(int x)
{
        // Your Code
     if(rear>=10001)
        return;
     arr[rear++]=x;
}
/*The method pop which return the element 
  poped out of the queue*/
int MyQueue :: pop()
{
        // Your Code
        if(front>rear)
         front=rear=0;
        if(front==rear)
         return -1;
        else
         return (arr[front++]);
        
}