int largestRectangleArea(vector<int> &A) {
    int n = A.size(), i = 0, curr = 0, maxar = 0;
    stack<int> s;
    while(i<n)
    {
        if(s.empty() || A[s.top()]<=A[i])
            s.push(i++);
        else
        {
            int tp = s.top();
            s.pop();
            curr = A[tp] * (s.empty() ? i : i-s.top()-1);
            maxar = max(curr,maxar);
        }
    }
    while(!s.empty())
    {
        int tp = s.top();
        s.pop();
        curr = A[tp] * (s.empty() ? i : i-s.top()-1);
        maxar = max(curr,maxar);
    }
    return maxar;
}
