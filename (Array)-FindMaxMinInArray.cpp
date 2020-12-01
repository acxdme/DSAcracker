/*
Time complexity : O(N)
Space complexity : O(1)
My approach : There can be multiple approaches, but the task here is to find the answer in minimum number of comparisons.
*/

Approach - 1: Linearly search in the array , for each element compare it with mx and mn and update accordingly. 
              In this method, the total number of comparisons is 1 + 2(n-2) in the worst case and 1 + n – 2 in the best case. 
              the worst case occurs when elements are sorted in descending order and the best case occurs when elements are sorted in ascending order.

Approach-2 : Tournament Method (aka divide and conquer) ,T(n) = 2T(n/2) + 2  which is  T(n)  = 3n/2 -2

Approach-3 : Compare Mn and Mx in pair ,If n is odd then initialize min and max as first element. 
              If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
              For rest of the elements, pick them in pairs and compare their maximum and minimum with max and min respectively. T(n)  = 3n/2 -2
