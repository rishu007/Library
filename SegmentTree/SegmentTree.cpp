#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
using namespace std;

int a[] = {4, 5, 6,7};

const int size_ST = sizeof(a)/sizeof(a[0]);

int segmentTree[2*size_ST-1];

int getMid(int start, int end)
{
   return start + (end - start) / 2;
}

void constructSegmentTree(int input[], int position, int left, int right)
{

   if (left == right)
   {
      segmentTree[position] = input[left];
   }
   else
   {
      int mid = getMid(left, right);
      constructSegmentTree(input, 2 * position + 1, left, mid);      //should call left subtree
      constructSegmentTree(input, 2 * position + 2, mid + 1, right); //should call right subtree
      segmentTree[position]=segmentTree[2 * position + 1]+segmentTree[2 * position + 2];
   }
}

int  query(int node,int start,int end,int rangeStart,int rangeEnd)
{
       if(rangeStart<start || rangeEnd>end)
       {
         
           cout <<"invalid input"<<endl;
           return 0;
       }
   
       if(rangeStart>end || rangeEnd<start)
       {
          return 0;  //no overlap
       }
       if(rangeStart<=start && end<=rangeEnd)
       {
          return segmentTree[node];   //complete overlap
       }  
       else{
            int mid=getMid(start ,end);
            int p=query(2*node+1,start,mid,rangeStart,rangeEnd);
            int q= query(2*node+2,mid+1,end,rangeStart,rangeEnd);
            return p+q;
       }

}



int main()
{

   constructSegmentTree(a,0,0,size_ST-1);
   
   cout<<query(0,0,3,-1,3);
}
