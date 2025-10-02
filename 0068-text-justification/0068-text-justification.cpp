class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> result;
        //For each line, keep adding words while they fit
        vector<string> currLine;
        int currLength = 0; //length of words

        for(auto& word : words) {
            int spaceNeeded = currLine.size(); //spaces b/w words atleast one each
            int wordSize = word.size(); //exract size of each word
            //example --> 4 + 2 + 2 + 7 (4 words) = 15 characs + 3 spaces = 18 >= width
            //--> // 4 +2 + 2 (3 words) + 2 (extra spaces) = 10 <= 16 can fit in the curr line 
            if(currLength + spaceNeeded + wordSize <= maxWidth) {
                currLine.push_back(word);
                currLength += wordSize;
            } else {
                //this word do not fit, process curr line --> format the curr line and add to result
                //start new line

                string formattedLine = formatLine(currLine, currLength, maxWidth, false);
                result.push_back(formattedLine);

                //start new line with curr word
                currLine.clear();
                currLine.push_back(word);
                currLength = word.size();
            }

        }
        //After Loop last line is yet to process like format it

        string lastLine = formatLine(currLine, currLength, maxWidth, true);
        result.push_back(lastLine);

        return result;
    }

    string formatLine(vector<string>& words, int wordLength, int maxWidth, bool isLastLine) {

        string line = "";

        //format last line --> left justified
        //format normal case --> full justified
        //format single word --> left justified

        //last line left justified
        if (isLastLine) {
            for (int i = 0; i < words.size(); i++) {
                line += words[i];
                if (i < words.size() - 1) {
                    line += " "; // just 1 space between words
                }
            }
            // Pad remaining spaces on the right
            while (line.length() < maxWidth) {
                line += " ";
            }
            return line;
        }

        // Special case: only one word (left-justified)
        if (words.size() == 1) {
            line = words[0];
            while (line.length() < maxWidth) {
                line += " ";
            }
            return line;
        }

        // Normal case: distribute spaces evenly (fully justified)
        int totalSpaces = maxWidth - wordLength;
        int gaps = words.size() - 1;
        int spacesPerGap = totalSpaces / gaps;
        int extraSpaces = totalSpaces % gaps;
        
        for (int i = 0; i < words.size(); i++) {
            line += words[i];
            
            if (i < words.size() - 1) { // not the last word
                // Add base spaces
                for (int j = 0; j < spacesPerGap; j++) {
                    line += " ";
                }
                // Add extra space if this is one of the leftmost gaps
                if (i < extraSpaces) {
                    line += " ";
                }
            }
        }
        
        return line;
    }
};