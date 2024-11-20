class Solution {
public:
//IDEA is to :
//use a stack to reverse the words as it leverages the LAST IN FIRST OUT PROPERTY which would be apt to solve
//this problem

//HOW?
//SPLIT THE WORDS
//PUSH WORDS INTO A STACK
//POP WORDS TO FORM THE RESULT

    string reverseWords(string s) {
        stack<string> wordstack;
        string word;
        stringstream ss(s); //break string into words

        //put each word into the stack
        while(ss >> word) {
            wordstack.push(word);
        }

        //pop every word from stack to reverse their order
        string result;
        while(!wordstack.empty()) {
            result += wordstack.top();
            wordstack.pop();
            if(!wordstack.empty()) {
                result += " ";
            }
        }
        return result;
    }
};