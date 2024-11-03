class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for (int i = 0; i < flowerbed.size(); i++) {
            if (!flowerbed[i]) {
                if (i > 0 && flowerbed[i-1])
                    continue;
                if (i < flowerbed.size() - 1 && flowerbed[i+1])
                    continue;
                
                cout << i << endl;
                flowerbed[i] = 1;
                n--;
            }
        }
        
        return n <= 0;
    }
};