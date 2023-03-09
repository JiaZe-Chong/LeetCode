class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int i = 1;
        int t = 1;
        int f = 1;
        vector<string> ans;
        while (i <= n){
            if (t == 3 && f == 5){
                ans.push_back("FizzBuzz");
                t = f = 0;
            } 
            else if (f == 5){
                ans.push_back("Buzz");
                f = 0;
            }
            else if (t == 3){
                ans.push_back("Fizz");
                t = 0;
            }
            else ans.push_back(to_string(i));
            
            i++;
            t++;
            f++;
        }
        return ans;
    }
};