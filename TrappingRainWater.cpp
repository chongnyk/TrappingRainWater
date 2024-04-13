class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        int maxHeight = 0;
        int result = 0;
        for(int i = 0; i < height.size(); i++){
            maxHeight = max(maxHeight, height[i]);
            maxLeft[i] = maxHeight;
        }
        maxHeight = 0;
        for(int i = height.size() - 1; i >= 0; i--){
            maxHeight = max(maxHeight, height[i]);
            maxRight[i] = maxHeight;
        }
        for(int i = 0; i < height.size(); i++){
            result += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return result;
    }
};
