/*
hash table
find longest palindrome string
*/

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    int longestPalindrome(string s){
        int char_map[128] = {0};
        int max_length = 0;
        int flag = 0;
        for (int i = 0; i < s.length(); i++){
            char_map[s[i]]++;
        }
        for (int i = 0; i < 128; i++){
            if (char_map[i]%2 == 0){
                max_length += char_map[i];
            }
            else{
                max_length += char_map[i]-1;
                flag = 1;
            }
        }
        return max_length+flag;
    }
};

int main(){
    string s = "abccccddaa";
    Solution solve;
    cout<<solve.longestPalindrome(s)<<endl;
    return 0;
}
