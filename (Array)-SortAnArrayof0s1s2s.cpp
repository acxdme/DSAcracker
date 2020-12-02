/*
Time complexity : O(N)
Space complexity : O(1)
My approach : Use pointer positions for 0(low) 1(mid) and 2(high) , swap for appropriate positions.
*/

void sort012(int nums[], int n)
{
     
        int low=0,mid=0, high=n-1;
        
        while(mid<=high) 
        {
            if(nums[mid]==1)  // if the value is 1 then just increment mid;
                mid++;
            else if(nums[mid]==0)  // if the element is 0 then swap it with low position, increment low and mid also
                {
                    swap(nums[mid],nums[low]);
                    low++;
                    mid++;   
                 }
            else  // when the element is 2 swap it with the high position, here we are not incrementing mid as a 2 might come after swapping which results 2 at a wrong position.
            {
                swap(nums[high],nums[mid]);
                high--;
            }
        }
        
    
}
