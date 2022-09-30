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
void Cycle_Check()
{
  map<T,bool> path;
  map<T,bool> visitied;
  for(auto x:gr)
  {
    if(!visitied[x.first])
    {
      Cycle_helper(x.first,visitied,path);
    }
  }
}
void Cycle_helper(T src,map<T,bool> &visitied,map<T,bool> &path)
{
      stack<T> st;
      st.push(src);
      path[src] = true;
      while(!st.empty())
      {
        T node = st.top();
        visitied[node]=true;
        for(auto nbr:gr[node])
        {
          if(!visitied[nbr])
          {
              st.push(nbr);
              Cycle_helper(nbr,visitied,path);
          }
          else if(visitied[nbr] && path[nbr])
          {
            cout<<"Cycle is present in the graph \n";
          }
          
        }
        
        path[node]=false;
        st.pop();
      }
     
}

};


int main()
{
    Graph<int> gr;
  gr.Addedge(0,1);
  gr.Addedge(1,5);
  gr.Addedge(1,2);
  gr.Addedge(2,3);
  gr.Addedge(3,4);
  gr.Addedge(4,7);
  gr.Addedge(4,5); 
  gr.Addedge(5,6);
  gr.Cycle_Check();
    return 0;
}