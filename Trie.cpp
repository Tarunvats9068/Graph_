#include<bits/stdc++.h>
using namespace std;
void trace(string str="",int y=0,int z=0)
{  
       cout << str << " " << y << " " << z << endl;
}
class Node
{    
	 public :
     Node* links[26];
     bool flag=false;
     bool containsKey(Node* temp,char ch)
     {   
     	if(temp->links[ch-'a']==NULL) return false;
     	else return true;
     }
     Node *getNext(Node* temp,char ch)
     {
     	 return temp->links[ch-'a'];
     }
     Node *insertNode(Node *temp,char ch,Node *n)
     {    
     	  temp->links[ch-'a'] = n;
     	  return n;
     }

};
class Trie
{
    private:
    	 Node *root;
    public:
    	  Trie()
    	  {
    	  	root  = new Node();
     	  }
          void insertWord(string str)
          {  
          	int n = str.length();
          	Node *temp = root;
          	for(int i=0;i<n;i++)
          	{
          		if(temp->containsKey(temp,str[i]))
          		{
                    temp = temp->getNext(temp,str[i]);
          		}
          		else
          		{
          			temp = temp->insertNode(temp,str[i],new Node());
          		}
          	}
          	temp->flag = true;
          }
          bool searchWord(string word)
          {
               int n = word.length();
               Node *next = root;
               for(int i=0;i<n;i++)
               {
               	  if(next->containsKey(next,word[i]))
               	  {   
               	  	  next = next->getNext(next,word[i]);
               	  }
               	  else return false;
               }
               if(next->flag) return true;
               return false;
          }
};
void solve()
{   
       Trie chtree;
       chtree.insertWord("tarun");
       chtree.insertWord("vats");
       cout << chtree.searchWord("sharma") << "\n";
       cout <<  chtree.searchWord("tarun") << "\n";
       cout <<  chtree.searchWord("vats") << "\n";
}
int main()
{
   ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
       int t;
       cin >> t;
       while(t--)
       {       
           solve();

             }
       
    return 0;
}
