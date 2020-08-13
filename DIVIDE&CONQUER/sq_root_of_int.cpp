ll bs(ll n)
{
    ll ans=0,l=1,r=n;
    while(l<=r)
    {
        ll mid = (l+r)/2;
    
        if((mid*mid)==n)
            return mid;
        if((mid*mid)<n)
        {
            l = mid+1;
            ans = mid;
        }
        else
            r = mid-1;
    }
    return ans;
}