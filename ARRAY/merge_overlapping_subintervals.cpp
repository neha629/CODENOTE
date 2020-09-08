/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool comparefunc(Interval i1, Interval i2)
{
    return (i1.start<i2.start);
}

vector<Interval> merge(vector<Interval> &A) {
    sort(A.begin(),A.end(),comparefunc);
    int k = 0;
    vector<Interval> res;
    for(int i=1;i<A.size();i++)
    {
        if(A[i].start<=A[k].end)
        {
            // A[k].start = min(A[i].start,A[k].start);
            A[k].end = max(A[i].end,A[k].end);
        }
        else
        {
            k++;
            A[k].start = A[i].start;
            A[k].end = A[i].end;
        }
    }
    res.assign(A.begin(),A.begin()+k+1); 
    return res;
}