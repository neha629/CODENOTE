//METHOD 1
stack<int> temp;
void push(int a)
{
    s.push(a);
    if(!temp.empty())
        temp.push(min(temp.top(),a));
    else
        temp.push(a);
}

int pop()
{
    int x=s.top();
    s.pop();
    temp.pop();
    return x;
}

int getMin()
{
   return temp.top();
}

//METHOD 2
int minele;
void push(int a)
{
    if(s.empty())
    {
        s.push(a);
        minele = a;
    }
    else if(a<minele)
    {
        s.push(2*a - minele);
        minele = a;
    }
    else
        s.push(a);
}

int pop()
{
    if(s.empty())
        return -1;
    int t = s.top(),ans;
    s.pop();
    if(t<minele)
    {
        ans = minele;
        minele = 2*minele - t;
    }
    else 
        ans = minele;
    return ans;
}

int getMin()
{
   return minele;
}