/*
An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.

 

Example 1:

Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true
Example 2:

Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false
Example 3:

Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
Output: false

*/

/*ALGO
If low x of r2 >= upper x of r1 or low x of r1 >= upper x of r2 then cannot overlap
If upper y of r1 <= low y of r2 or upper y of r2 <= low y of r1 then cannot overlap

*/
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int lx_1=rec1[0], ly_1=rec1[1], ux_1=rec1[2], uy_1=rec1[3];
        int lx_2=rec2[0], ly_2=rec2[1], ux_2=rec2[2], uy_2=rec2[3];
        if(lx_1==ux_1 || ly_1==uy_1 || lx_2==ux_2 || ly_2==uy_2) return false;
        if(lx_2>=ux_1 || lx_1>= ux_2) return false;
        if(uy_1<=ly_2 || uy_2<= ly_1) return false;
        
        return true;
    }
};