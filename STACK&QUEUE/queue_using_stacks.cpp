//Method 1 ENQUEUE OPERATION IS COSTLY
void StackQueue :: push(int x)
 {
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
 }

int StackQueue :: pop()
{
        // Your Code  
        if(s1.empty())
            return -1;
        int x = s1.top();
        s1.pop();
        return x;
}

//Method 2 DEQUEUE OPERATION IS COSTLY (BETTER METHOD)
void StackQueue :: push(int x)
 {
    s1.push(x);
 }

int StackQueue :: pop()
{ 
    if(s1.empty() && s2.empty())
        return -1;
    if(s2.empty()) 
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int x = s2.top();
    s2.pop();
    return x;
}
