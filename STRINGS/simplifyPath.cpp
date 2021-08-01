    string simplifyPath(string path) 
    {
        int n = path.length();
        stack<string> s;
        string temp = "",ans="";
        
        for(int i=0;i<n;i++)
        {
            temp="";
            while(path[i]=='/')
                i++;
            while(i<n && path[i]!='/')
                temp+=path[i++];
            if(temp==".")
                continue;
            else if(temp=="..")
            {
                if(!s.empty())
                    s.pop(); 
            }
            else if(temp!="")
                s.push(temp);
        }
     
        if(s.empty())
            ans = "/";
        else
        {
            while(!s.empty())
            {
                ans = s.top()+ans;
                ans="/"+ans;
                s.pop();
            }
        }
        return ans;