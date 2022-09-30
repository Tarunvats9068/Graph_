#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph
{
    map<T,pair<bool,list<T>>> mp;
    int flag =0;
    public:
    void Addedge(T x,T y)
    {
        mp[x].second.push_back(y);
        // mp[y].second.push_back(x);
    }
    void Cycle_Check()
    {
        for(auto x:mp)
        {
            if(!mp[x.first].first)
            {
             Cycle_Checker(x.first,x.first);
            }
        }
    }
    void Cycle_Checker(T child,T parent)
    {  

            if((mp[child].first) && (child != parent))
            {
                 cout<<"Cycle is present in the graph \n";
                 flag = 1;
                 return ;
            }
            else
            {    
                mp[child].first = true;
                 for(auto x:mp[child].second)
                  {
                    if(flag==1)
                {
                    return ;
                }
                else if(x != parent)
                { 
                Cycle_Checker(x,child);
                }
                      
                  }
            }
    }
};


int main()
{
  Graph<int> gr;
  gr.Addedge(1,2);
  gr.Addedge(1,4);
  gr.Addedge(2,3);
  gr.Addedge(3,5);
  gr.Addedge(4,6);
  gr.Addedge(6,3);
  gr.Cycle_Check();
  return 0;
}