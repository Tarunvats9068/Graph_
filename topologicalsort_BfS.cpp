#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph
{
    map<T,list<T>> gr;
    map<T,int> deg;
    
    map<T,bool> visitied;
    public:
    void Addedge(T x,T y)
    {
        gr[x].push_back(y);
        deg[y]++;
    }
    void topological_sort()
    {
        queue<T> qe;
        for(auto x:gr)
        {
            if(deg.find(x.first)==deg.end())
            {
                 qe.push(x.first);
            }  
        }
        Topo_helper(qe);
    }
    void Topo_helper(queue<T> &qe)
    {
        while(!qe.empty())
        {
             T node = qe.front();
             cout<<node<<" ";
             qe.pop();
             visitied[node]=true;
        for(auto x:gr[node])
        {
            if(!visitied[x])
            {
                deg[x]--;
            }
            if(!deg[x])
            {
                qe.push(x);
            }
        }
        }
    }
};
int main()
{
    Graph<int> gr;
    gr.Addedge(0,2);
    gr.Addedge(2,5);
    gr.Addedge(2,3);
    gr.Addedge(5,3);
    gr.Addedge(1,4);
    gr.Addedge(4,3);
    gr.topological_sort();
    return 0;
}