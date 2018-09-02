// Text justification
// Given an array of words and a width maxWidth, format the text such that each
// line has exactly maxWidth characters and is fully (left and right) justified.
//
// You should pack your words in a greedy approach; that is, pack as many words
// as you can in each line. Pad extra spaces ' ' when necessary so that each
// line has exactly maxWidth characters.
//
// Extra spaces between words should be distributed as evenly as possible. If
// the number of spaces on a line do not divide evenly between words, the empty
// slots on the left will be assigned more spaces than the slots on the right.
//
// For the last line of text, it should be left justified and no extra space is
// inserted between words.
//
// Note:
//
// A word is defined as a character sequence consisting of non-space characters
// only. Each word's length is guaranteed to be greater than 0 and not exceed
// maxWidth. The input array words contains at least one word. Example 1:
//
// Input:
// words = ["This", "is", "an", "example", "of", "text", "justification."]
// maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Example 2:
//
// Input:
// words = ["What","must","be","acknowledgment","shall","be"]
// maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall be",
//              because the last line must be left-justified instead of
//              fully-justified. Note that the second line is also
//              left-justified becase it contains only one word.
// Example 3:
//
// Input:
// words =
// ["Science","is","what","we","understand","well","enough","to","explain",
//          "to","a","computer.","Art","is","everything","else","we","do"]
// maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for (int i = 0, j; i < words.size(); i = j) {
            int width = 0;
            for (j = i; j < words.size()
                        && width + j - i + words[j].size() <= maxWidth;
                 ++j) {
                width += words[j].size();
            }

            string tmp = words[i];
            int space = 1,
                extra = 0; // the default space we need for the last row.
            if (j - i > 1 && j < words.size()) {
                // we have j-i strings, then need j-i-1 space
                space = (maxWidth - width) / (j - i - 1);
                extra = (maxWidth - width) % (j - i - 1);
            }

            for (int k = i + 1; k < j; ++k) {
                tmp += string(space, ' ');
                if (extra-- > 0) {
                    tmp += " ";
                }
                tmp += words[k];
            }

            // add the remaining space.
            tmp += string(maxWidth - tmp.size(), ' ');
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {}
