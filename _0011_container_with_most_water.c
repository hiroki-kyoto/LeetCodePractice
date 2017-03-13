/****************************
Given n non-negative integers a1, a2, ..., an, 
where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints 
of line i is at (i, ai) and (i, 0). Find two lines, 
which together with x-axis forms a container, 
such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
****************************/
int maxArea(int* height, int heightSize) {
    int i, k, m;
    i=m=0;
    k=heightSize-1;
    while (i<k) {
        if ( height[i]<height[k] ) {
            m = m<(height[i]*(k-i))?(height[i]*(k-i)):m;
            ++i;
        } else {
            m = m<(height[k]*(k-i))?(height[k]*(k-i)):m;
            --k;
        }
    }
    
    return m;
}
