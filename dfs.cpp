#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> g;

public:
    void Addedge(T x, T y)
    {
        g[x].push_back(y);
        g[y].push_back(x);
    }
    void DFS(int src)
    {
        map<T,bool> vi;
        stack<T> st;
        st.push(src);
        while (!st.empty())
        {
            T y = st.top();
            cout << y << " ";
            vi[y] = true;
            st.pop();
            for (auto x : g[y])
            {
                if (!vi[x])
                {
                    st.push(x);
                }
            }
        }
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
    gr.DFS(1);
    gr.DFS(4);
    return 0;
}