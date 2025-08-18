#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        
        int currentLength = 0;
        int startIndex = 0;
        for(int i=0; i<words.size(); i++) {
            int wordLen = words[i].size();
            if(currentLength+wordLen>maxWidth) {
                result.push_back(getFormattedString(words, startIndex, i, maxWidth));
                startIndex = i;
                currentLength = wordLen;
            } else {
                currentLength+=wordLen;
            }
            currentLength+=1;
        }
        std::string lastLine("");
        for(int i=startIndex; i<words.size(); i++) {
            lastLine.append(words[i]);
            lastLine.append(1, ' ');
        }
        if(lastLine.size() < maxWidth) {
            lastLine.append(lastLine.size()-maxWidth, ' ');
        } else if(lastLine.size() > maxWidth) {
            lastLine.pop_back();
        }
        result.push_back(lastLine);
        return result;

    }

private:
    std::string getFormattedString(vector<string>& words, int startIndex, int endIndex, int maxWidth) {
        int gapNum = endIndex-startIndex-;
        std::string res("");
        
        if(gapNum == 0) {
            res.append(words[startIndex]);
            res.append(maxWidth=words[startIndex].size(), ' ');
            return res;
        }
        int wordLenSum = 0;
        for(int i=startIndex; i<endIndex; i++) {
            wordLenSum = words[i].size();
        }
        int base = maxWidth/gapNum;
        int needAddOne = maxWidth%gapNum;
        for(int i=startIndex, j=0; i<endIndex; i++, j++) {
            res.append(words[i]);
            if(needAddOne>j) {
                res.append(base+1, ' ');
            } else {
                res.append(base, ' ');
            }
        }
        return res;
    }
};