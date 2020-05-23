#include <iostream>
using namespace std;
void func(int n,char from,char to,char help)
{
    if(n==0)
    {
     return;
    }
    func(n-1,from,help,to);
    cout<<"Move "<<n<<" disc from "<<from<<" to "<<to<<endl;
    func(n-1,help,to,from);
    
}
int main() {
	func(4,'A','C','B');
	return 0;
}