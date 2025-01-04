class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for(int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            encoded += to_string(str.size()) + ":" + str;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while(i < s.size()) {
            int delimiter_pos = s.find(":", i);

            int sLength = stoi(s.substr(i, delimiter_pos - i));
            string decodeString = s.substr(delimiter_pos + 1, sLength);
            decoded.push_back(decodeString);
            i = delimiter_pos + 1 + sLength;
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));