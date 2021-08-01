// #include <iostream>
// using namespace std;

// int main() {
// 	string str = "123";
// 	int x = stoi(str);
// 	cout<<x<<endl;
// 	string s = to_string(x);
// 	cout<<s<<" "<<s.length()<<endl;
// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;
vector<int> divi;

void divisors(int n) 
{ 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                divi.push_back(i); 
            else
            {
                divi.push_back(i);
                divi.push_back(n/i);
            }
        } 
    } 
} 

int main() {
        int n,p,q;
        cin>>n;
        while(n--)
        {
            cin>>p>>q;
            divi.clear();
            divisors(p);
            sort(divi.begin(),divi.end());
            int s = divi.size();
            for(int i=s-1;i>=0;i--)
            {
                if(divi[i]%q!=0)
                {
                    cout<<divi[i]<<endl;
                    break;
                }
            }
        }
	return 0;
}