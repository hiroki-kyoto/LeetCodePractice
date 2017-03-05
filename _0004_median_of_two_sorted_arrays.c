/************************
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
**************************/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
     // when nums1[p-1] <= nums2[q] and nums1[p] >= nums2[q-1] then we got median
     int p, q, c; // indexes
     int a1,a2,b1,b2; // temp number
     int l1,l2; // edges 
     c = (nums1Size + nums2Size)/2;
     p = nums1Size / 2;
     q = c - p;
     l1 = 0;
     l2 = nums1Size;
     
     if ( nums1Size==0 ) {
         if(nums2Size%2) {
             return nums2[nums2Size/2];
         } else {
             return (nums2[nums2Size/2-1] + nums2[nums2Size/2])/2.0;
         }
     }
     if ( nums2Size==0 ) {
         if(nums1Size%2) {
             return nums1[nums1Size/2];
         } else {
             return (nums1[nums1Size/2-1] + nums1[nums1Size/2])/2.0;
         }
     }
        
     while ( 1 ) {
         // check if meets edge
         if ( p==0 ) {
             b2 = nums2[q];
             a1 = b2-1;
         } else {
            a1 = nums1[p-1];
         }
         if ( p==nums1Size ) {
             b1 = nums2[q-1];
             a2 = b1 + 1;
         } else {
            a2 = nums1[p];
         }
         if ( q==0 ) {
             a2 = nums1[p];
             b1 = a2-1;
         } else {
             b1 = nums2[q-1];
         }
         if ( q==nums2Size ) {
             a1 = nums1[p-1];
             b2 = a1 + 1;
         } else {
             b2 = nums2[q];
         }
         if ( a1 <= b2 && a2 >= b1 ) { // median found
             if((nums1Size+nums2Size)%2) {
                 if (p==nums1Size) { // so q will be in middle
                     return b2;
                 } else if (q==nums2Size) {
                     return a2;
                 } else {
                     return b2>a2?a2:b2;
                 }
             } else {
                 if ( p==0){
                     a1 = b1-1;
                 } else if ( p==nums1Size ) {
                     a2 = b2+1;
                 }
                 if ( q==0 ) {
                     b1 = a1-1;
                 } else if ( q==nums2Size){
                     b2 = a2+1;
                 }
                 return ((a1>b1?a1:b1) + (a2>b2?b2:a2))/2.0;
             }
         } else if( a1>b2 ){ // move to left
             l2 = p-1;
             p = (l1 + l2)/2;
             q = c - p;
             if ( q>nums2Size ) {
                 q = nums2Size;
                 p = c - q;
             }
         } else if ( a2<b1 ) { // move to right
             l1 = p+1;
             p = (l1+l2)/2;
             q = c - p;
             if ( q<0 ) {
                 q = 0;
                 p = c - q;
             }
         }
     }
     return 404.402;
}
