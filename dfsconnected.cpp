#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
  map<T,pair<bool,list<T>>> g;
  public:
  void Addedge(int x,int y)
  {
      g[x].second.push_back(y);
  }
  void DFS(int src)
  { 
      Dfs_helper(src);
     for(auto x:g)
     {
        if(!g[x.first].first)
        {
            Dfs_helper(x.first);
        }
     }
  }
  void Dfs_helper(int node)
  {
     stack<T> st;
    st.push(node);
    while(!st.empty())
    {
        T y = st.top();
        st.pop();
        cout<<y<<" ";
        g[y].first = true;
        for(auto x:g[y].second)
        {
            if(!g[x].first)
            {
                st.push(x);
            }
        }
       
    } 
    cout<<"\n";
  }
};

int main()
{
    Graph<int> gr;
    gr.Addedge(1, 2);
    gr.Addedge(1, 3);
    gr.Addedge(1, 4);
    gr.Addedge(2, 5);
    gr.Addedge(5, 6);
    gr.Addedge(7, 8);
    gr.Addedge(7, 9);
    gr.Addedge(8, 10);
    gr.DFS(2);
    return 0;
}