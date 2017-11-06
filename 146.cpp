#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>

using namespace std;

class LRUCache{
public:
	unordered_map<int,list<pair<int,int>>::iterator> m;
	list<pair<int,int>> cache;
	size_t m_capacity;
	LRUCache(int capacity){
		m_capacity=capacity;
	}

	int get(int key){
		auto it=m.find(key);
		if(it==m.end())
			return -1;
		cache.splice(cache.begin(),cache,it->second);
		m[key]=cache.begin();
		return it->second->second;	
	}

	void put(int key,int value){
		auto it=m.find(key);
		if(it!=m.end()){
			it->second->second=value;
			cache.splice(cache.begin(),cache,it->second);
			m[key]=cache.begin();
			return;
		}
		if(m.size()==m_capacity){
			int del=cache.back().first;
			m.erase(del);
			cache.pop_back();
		}
		cache.emplace_front(key,value);
		m[key]=cache.begin();
	}
};


int main(){

}




