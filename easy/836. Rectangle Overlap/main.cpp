class Solution {
public:
    bool line_overlap1(int xl, int xr, int yl, int yr){
        return (xl >= yl && xl < yr) || (xr > yl && xr <= yr);
    }
    
    bool line_overlap(int xl, int xr,  int yl, int yr){
        return line_overlap1(xl, xr, yl, yr) || line_overlap1(yl, yr, xl, xr);
    }
    
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool horizontal = line_overlap(rec1[0], rec1[2], rec2[0], rec2[2]);
        bool vertical = line_overlap(rec1[1], rec1[3], rec2[1], rec2[3]);
        return horizontal && vertical;
    }
};
