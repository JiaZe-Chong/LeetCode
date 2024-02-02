class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        
        for (int i = 0; i < flowerbed.size(); i++) {
            if (!flowerbed[i]) {
                bool left = i == 0 || !flowerbed[i - 1];
                bool right = i == flowerbed.size() - 1 || !flowerbed[i + 1];
                
                if (left && right) {
                    count++;
                    if (count >= n) return true;
                    flowerbed[i] = 1;
                }
            }
        }
        
        return count >= n;
    }
};