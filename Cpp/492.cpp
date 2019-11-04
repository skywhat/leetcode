class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width = sqrt(area);
        while(area%width != 0){
            width--;
        }
        
        return vector<int>{area/width, width};
    }
};
