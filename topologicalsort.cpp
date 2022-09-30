#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<T>> gr;
    public:
    void Addedge(T x,T y)
    {
        gr[x].push_back(y);
    }
    void DFS_Helper(T src,map<T,bool> &visit,list<int> &ordering)
    {
         visit[src]=true;
         for(auto nbr:gr[src])
         {
            if(!visit[nbr])
            {
                DFS_Helper(nbr,visit,ordering);
            }
         }
         ordering.push_front(src);
         return ; 
    }
    void DFS()
    {
        map<T,bool> visitied;
        list<int> ordering;
        for(auto x:gr)
        {
            if(!visitied[x.first])
            {
                DFS_Helper(x.first,visitied,ordering);
            }
        }

        for(auto x:ordering)
        {
            cout<<x<<" ";
        }
        cout<<"\n";

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
    gr.DFS();
    return 0;
}