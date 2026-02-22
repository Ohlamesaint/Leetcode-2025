/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Copyright (c) 2025
 * 
 * Time Complexity: O(m+n) where m is the length of words and n is the number of words
 * Space Complexity: O(1) // excluding the space for the output
 * 
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int wordStart = 0, totalLength = words[0].length(), wordCharLength = words[0].length();
        vector<string> res;
        for(int i=1; i<words.size(); i++) {
            int nextWordLength = words[i].length();
            
            if(totalLength + nextWordLength + 1 > maxWidth) {

                res.push_back("");
                int blankCount = i-wordStart-1;
                int blankSize = maxWidth-wordCharLength;

                while(wordStart < i) {
                    res.back().append(words[wordStart]);
                    if(blankCount > 0) {
                        int blankLen = (blankSize+blankCount-1)/blankCount;
                        res.back().append(string(blankLen, ' '));
                        blankCount--;
                        blankSize-=blankLen;
                    }
                    wordStart++;
                }

                if(res.back().length()!=maxWidth) {
                    res.back().append(string(maxWidth-res.back().length(), ' '));
                }
                
                
                wordCharLength = 0;
                totalLength = -1;
            } 
            wordCharLength += nextWordLength;
            totalLength += nextWordLength+1;
                
            
        }

        if(wordCharLength != 0) {
            res.push_back("");
            int blankCount = words.size()-wordStart-1;
            int blankSize = maxWidth-wordCharLength;

            while(wordStart <  words.size()) {
                res.back().append(words[wordStart]);
                if(blankCount > 0) {
                    int blankLen = (blankSize+blankCount-1)/blankCount;
                    res.back().append(string(1, ' '));
                    blankCount--;
                    blankSize-=blankLen;
                }
                wordStart++;
            }

            if(res.back().length()!=maxWidth) {
                res.back().append(string(maxWidth-res.back().length(), ' '));
            }
                
        }
        return res;
    }

    
};