/*
Time comlexity :  O(n+m)
space complexity : O(1)
My approach :  The naive way is to count in each row the number of 1's , this would take O(N*M) time , the naive appraoch  does not take advantage of the fact that the 
              matrix is row wise sorted.
*/


class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	     int r=0, c= m-1;
	     int count =0 , row_position =-1; // starting with matrix[0][column-1] position ,initially row position = -1  indicates no row has 1
    
	     while(r< n and c>= 0)    // while r is less than #rows and c >= columns
	     {
	         if(arr[r][c] == 1 )   // if the cell value is 1, update row_position to current row and decrement c
	           {
	               row_position = r;
	               c--;
	           }
	        else   // if the value is 0 then increment row 
	        {
	            r++;
	        }
	        
	     }
	     
	     
	     return row_position;
	}

};

/*
Binary Search Method  
Time complexity : O(N*logM) , space complexity : O(1)
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
     vector<vector<int>> Matrix
     {
        {0,0,0,0,1},
        {0,0,0,1,1},
        {0,0,1,1,1},  // this is the row with max ones.
        {0,0,0,0,1}
     };

     int row = Matrix.size();
     int col = Matrix[0].size();
     for(int i=0;i<row;i++)
     {
         for(int j=0;j<col;j++)
          cout<<Matrix[i][j]<<" ";
          cout<<endl;
     }
      int row_number =0, count = 0;
      for(int i=0;i<row;i++)  // applying binary search in for each row to find the number of in each row
      {
        int t =  upper_bound(Matrix[i].begin(),Matrix[i].end(),0) - Matrix[i].begin();   
        // cout<<t<<endl;
         if(count < (col-t))
          {
              count = col-t;
              row_number = i;
          }
      }
      
      cout<<row_number<<endl;
     return 0;
}

