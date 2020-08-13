vector<vector<string> > res;
vector<string> curr;

bool isPal(int l,int r,string s)
{
    while(l<r)
    {
        if(s[l]!=s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

void func(int start,int n,string s)
{
    if(start>=n)
    {
        res.push_back(curr);
        return;
    }
    for(int i=start;i<n;i++)
    {
        if(isPal(start,i,s))
        {
            curr.push_back(s.substr(start,i-start+1));
            func(i+1,n,s);
            curr.pop_back();
        }
    }
}

vector<vector<string> > partition(string A) {
    res.clear();
    curr.clear();
    int n = A.length();
    func(0,n,A);
    return res;
}
