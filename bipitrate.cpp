#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph 
{
    map<T,pair<bool,list<T>>> mp;
    int flag =0;
    public:
    int count=0;
    void Addedge(T x,T y)
    {
        mp[x].second.push_back(y);
        mp[y].second.push_back(x);
    }
    void checkbipitrate()
    {
        for(auto x:mp)
        {
            if(!mp[x.first].first)
            {
             BI_helper(x.first,x.first);
            }
        }
    }
    void BI_helper(T child,T parent)
    {  

            if((mp[child].first) && (child != parent))
            {   
                if(count%2==0)
                {
                cout<<"cyle is detected "<<count<<"\n";
                 flag = 1;
                 return ;
                }
                else
            {
                 cout<<"No cycle is found in the graph \n";   
            }
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
                 count++;
                BI_helper(x,child);
                    count--;
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
  gr.Addedge(4,5);
  gr.checkbipitrate();
  return 0;
}