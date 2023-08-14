#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //pwwkew
        // pw
        // wke <-- Solution
        // w
        int stringLength = s.length();
        string temp = "";
        int maxLength = 0;

        for (int i = 0; i < stringLength; i++) {
            size_t charIndex = temp.find(s[i]);
            if (temp.find(s[i]) != string::npos) {
                temp.erase(0, charIndex + 1); // Remove characters before the repeating one
                // "pw" -> ""
            }
            temp += s[i]; // "" -> "w-->k-->e"

            if (temp.length() > maxLength) {
                maxLength = temp.length();
            }
        }

        return maxLength;
    }
    
};