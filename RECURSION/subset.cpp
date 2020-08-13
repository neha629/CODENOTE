#include <bits/stdc++.h> 
using namespace std;
vector<char> subset,permutation;
string a;
int n;
vector<bool> chosen;

void search(int k) 
{
    if(k==n) 
    {
        for(auto it:subset)
            cout<<it<<" ";
        cout<<endl;
    } 
    else 
    {
        subset.push_back(a[k]);
        search(k+1);
        subset.pop_back();
        search(k+1);
    }
}

void func(string s,int n,int i,string curr)
{
     if(n==i)
     return ;
     cout<<curr<<endl;
     for(int j=i+1;j<n;j++)
     {
         curr += s[j];
         func(s,n,j,curr);
         curr=curr.erase(curr.size()-1);
     }
}

void permute(string s,int l,int r)
{
    if(l==r)
        cout<<s<<endl; 

    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(s[l],s[i]);
            permute(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}

void func(int start,vector<int> &A)
{
    if(start==A.size()-1)
        res.push_back(A);
    else
    {
        for(int i=start;i<A.size();i++)
        {
            swap(A[i],A[start]);
            func(start+1,A);
            swap(A[i],A[start]);
        }
    }
}

void permute2()
{
    if (permutation.size() == n) 
    {
        for(auto it:permutation)
            cout<<it<<" ";
        cout<<endl;
    } 
    else 
    {
        for (int i=0;i<n;i++) 
        {
            if(chosen[i]) 
                continue;
            chosen[i] = true;
            permutation.push_back(a[i]);
            permute2();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

void lex_permute()
{
    for (int i=0;i<n;i++) 
    {
        permutation.push_back(a[i]);
    }
    do 
    {
        for(auto it:permutation)
            cout<<it<<" ";
        cout<<endl;
    }while(next_permutation(permutation.begin(),permutation.end()));
}

int main() {
    // string s="abc";
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    // n=3;
    // a="abcde";
    // // search(0);
    chosen.assign(n,false);
    permute2();
    lex_permute();
	return 0;
}