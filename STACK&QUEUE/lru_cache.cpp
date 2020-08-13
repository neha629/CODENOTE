#include<bits/stdc++.h>
list<pair<int,int>> q;
unordered_map<int,list<pair<int,int>>::iterator> mp;
int csize;
LRUCache::LRUCache(int capacity) {
    csize = capacity;
    q.clear();
    mp.clear();
}

int LRUCache::get(int key) {
    if(mp.find(key) == mp.end())
        return -1;
    auto it = mp[key];
    int val = it->second;
    q.erase(it);
    q.push_front({key,val});
    mp[key] = q.begin();
    return val;
}

void LRUCache::set(int key, int value) {
    if(mp.find(key) == mp.end())
    {
        if(csize == q.size())
        {
            pair<int,int> p = q.back();
            q.pop_back();
            mp.erase(p.first);
        }
    }
    else
        q.erase(mp[key]);
    q.push_front({key,value});
    mp[key] = q.begin();
}
