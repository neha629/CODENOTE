vector<int> arr,fact;

void factorial(int A)
{
    fact[0]=fact[1]=1;
    for(int i=2;i<=A;i++)
    {
        if(i>12)
            fact[i] = INT_MAX;
        else
            fact[i] = fact[i-1]*i;
    }
}

void func(string &res,int n,int k)
{
    if(n==0)
        return;
    int in = k/fact[n-1];
    if(k%fact[n-1]==0)
        in--;
    res+=to_string(arr[in]);
    arr.erase(arr.begin()+in);
    k = k - fact[n-1]*in;
    func(res,n-1,k);
}

string getPermutation(int A, int B) {
    fact.resize(A+1);
    factorial(A);
    string res = "";
    arr.resize(A);
    for(int i=0;i<A;i++)
        arr[i] = i+1;
    func(res,A,B);
    return res; 
}
