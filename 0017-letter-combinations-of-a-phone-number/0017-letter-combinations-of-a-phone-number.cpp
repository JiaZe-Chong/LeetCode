class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<int> input;
        for ( char c : digits ) input.push_back( c - '2' );
        const vector<string> dict = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> ret;
        dfs( input, dict, 0, ret, "" );
        return ret;
    }
    
    void dfs( const vector<int>& input, const vector<string>& dict, int ind, vector<string>& ret, string cur ) {
        if ( ind == input.size() ) {
            if ( ind ) ret.push_back( cur );
            return;
        }    
        
        for ( char c : dict[input[ind]] ) {
            dfs( input, dict, ind + 1, ret, cur + c );
        }
        
        
    }
};