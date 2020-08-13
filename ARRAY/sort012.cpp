void sortColors(vector<int>& a) {
        int n = a.size();
        int l=0,mid=0,h=n-1;
        while(mid<=h)
        {
            switch(a[mid])
            {
                case 0:
                    swap(a[l++],a[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(a[mid],a[h--]);
                    break;
            }
        }
}