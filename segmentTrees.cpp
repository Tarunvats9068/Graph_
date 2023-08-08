#include<bits/stdc++.h> 
using namespace std;



class SegTree
{ 
  private:
    vector<int> seg;
    vector<int> lazy;
  public:
  	SegTree(int n)
  	{
       seg.resize(4*n);
       lazy.resize(4*n);
  	}
     void BuildTree(int idx,int low,int high,vector<int> &nums)
     {   
     	if(low==high) 
     	{     
     		seg[idx] = nums[low];
     		return ;
     	}
     	else
     	{    
     		int mid  = (high-low)/2 + low;
     		BuildTree(2*idx,low,mid,nums);
     		BuildTree(2*idx+1,mid+1,high,nums);
     		seg[idx] = max(seg[2*idx],seg[2*idx+1]);
        }
     }
     int Query(int idx,int low,int high,int lou,int highu)
     {
     	if(lou > high || highu<low) return 0;
     	else if(lou<= low && highu >= high) return seg[idx];
     	else
     	{
     		int mid  = (high-low)/2 + low;
     		int left = Query(2*idx,low,mid,lou,highu);
     		int right = Query(2*idx+1,mid+1,high,lou,highu);
     		return max(left,right);
     	}
     }
     void UpdateTree(int idx,int low,int high,int index,int value)
     {   
        if(low==index) 
        {
            seg[idx] = value;
        }
        if(low>=high)
        {
           return ;          
        }
        else
        {
            int mid  = (high-low)/2 + low;
            if(index <= mid )  UpdateTree(2*idx,low,mid,index,value);
            else UpdateTree(2*idx+1,mid+1,high,index,value);
            seg[idx] = max(seg[2*idx],seg[2*idx+1]);
        }
     }
     void LazyUpdate(int idx,int low,int high,int low_rang,int high_rang,int value)
     {
         if(lazy[idx]!=0)
         {
            seg[idx]+=(high-low+1)*lazy[idx];
            if(low!=high)
            {
                lazy[2*idx] = lazy[idx];
                lazy[2*idx+1] = lazy[idx];
            }
            lazy[idx] = 0;
         }
         else if(low_rang > high || low > high_rang) return ;
         else if(low_rang<=low && high <=high_rang) 
         {
            seg[idx]+=(high-low+1)*value;
            if(low!=high)
            {
                lazy[2*idx] = value;
                lazy[2*idx+1] = value;
            }
            return ;
         }
         else
         {
            int mid = ((high-low)>>1) + low;
            LazyUpdate(2*idx,low,mid,low_rang,high_rang,value);
            LazyUpdate(2*idx+1,mid+1,high,low_rang,high_rang,value);
            seg[idx] = max(seg[2*idx],seg[2*idx+1]);
         }
     }

     int LazyRange(int idx,int low,int high,int low_rang,int high_rang)
     {  
        if(lazy[idx]!=0)
        {
            seg[idx]+=(high-low+1)*lazy[idx];
            if(low!=high)
            {
                lazy[2*idx] = lazy[idx];
                lazy[2*idx+1] = lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(low > high_rang || high < low_rang) return 0;
        else if(low_rang<=low && high <=high_rang) 
        {
            return seg[idx];
        }
        else
        {
            int mid = ((high-low)>>1)+low;
            int left = LazyUpdate(2*idx,low,high,low_rang,high_rang);
            int right = LazyUpdate(2*idx+1,low,high,low_rang,high_rang);  
            return max(left,right);
        }
     }

};



int main() 
{    
	freopen("out.txt","w",stdout);
	vector<int> ans{2,6,7,3,8,9,45,67,43,23,56};
     SegTree maxx = SegTree(11);
	maxx.BuildTree(1,0,ans.size()-1,ans);
    cout << maxx.Query(1,0,ans.size()-1,3,8);
    maxx.UpdateTree(1,0,ans.size()-1,7,90);
        cout << " \n";
    cout << maxx.Query(1,0,ans.size()-1,3,8);
     maxx.UpdateTree(1,0,ans.size()-1,4,105);
        cout << " \n";
    cout << maxx.Query(1,0,ans.size()-1,3,8);
    return 0;
}