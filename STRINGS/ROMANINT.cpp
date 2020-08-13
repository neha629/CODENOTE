// ROMAN TO INT
int value(char r) 
{ 
    if (r == 'I') 
        return 1; 
    if (r == 'V') 
        return 5; 
    if (r == 'X') 
        return 10; 
    if (r == 'L') 
        return 50; 
    if (r == 'C') 
        return 100; 
    if (r == 'D') 
        return 500; 
    if (r == 'M') 
        return 1000; 
  
    return -1; 
}

int romanToInt(string A) {
    int n = A.length(),ans = 0;
    for(int i=0;i<n;i++)
    {
        int x = value(A[i]);
        if(i+1<n)
        {
            int y = value(A[i+1]);
            if(x>=y)
                ans+=x;
            else
            {
                ans+=(y-x);
                i++;
            }
        }
        else
            ans+=x;
    }
    return ans;
}

//INT TO ROMAN
string intToRoman(int A) {
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    int i=12;
    string res = "";
    while(A>0)
    {
        int div = A/num[i];
        A = A%num[i];
        while(div--)
            res+=sym[i];
        i--;
    }
    return res;
}