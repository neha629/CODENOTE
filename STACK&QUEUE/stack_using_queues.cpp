// Method 1 , making push operation costlier
void QueueStack :: push(int x)
{
        // Your Code
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
}

int QueueStack :: pop()
{
        // Your Code 
        if(q1.empty())
            return -1;
        int x = q1.front();
        q1.pop();
        return x;
}



// Method 2 , making pop operation costlier
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

int QueueStack :: pop()
{
        // Your Code 
        if(q1.empty())
            return -1;
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return x;
}