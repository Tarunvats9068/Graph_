#include<bits/stdc++.h>

using namespace std;

class DSU 
{
public:
	vector<int> parent;
	vector<int> size;
	DSU(int n)
	{
		parent.resize(n);
		size.resize(n);
		for(int i=0;i<n;i++) parent[i]=i;
	}
     
     // union function for joining the two nodes using size concept

    void union_by_size(int x,int y)
    {
    	 int x_par = find_par(x);
    	 int y_par = find_par(y);
    	 if(size(x_par) > size(y_par))
    	 {
    	 	parent[y_yar] = x_par;
    	 	size[x_par]+=size[y_par]+1;
    	 }
    	 else 
    	 {
    	 	parent[x_par] = y_par;
    	 	size[y]+=1+size[x_par];
    	 }

    }

//  find ultimate parent with path compression
    int find_par(int x)
    {
    	if(parent[x]==x) return x;
    	else
    	{
    		return parent[x] = find_par(parent[x]);
    	}
    }
}