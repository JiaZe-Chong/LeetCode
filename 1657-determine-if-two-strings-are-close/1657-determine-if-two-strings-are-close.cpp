class Solution {
public:
    bool closeStrings(string word1, string word2) {
        array<int, 26> arr1;
        array<int, 26> arr2;
        
        for (char c : word1) arr1[c - 'a']++;
        for (char c : word2) arr2[c - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if ((bool)arr1[i] != (bool)arr2[i]) return false;
        }
        
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        
        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) return false;
        }
        
        return true;
    }
};