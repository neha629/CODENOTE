int maxSubArray(const vector<int> &A) {
    int curr=A[0],res = A[0];
    for(int i=1;i<A.size();i++)
    {
        curr = max(A[i],curr+A[i]);
        res = max(res,curr);
    }
    return res;
}