class Solution {
public:
//calculate permutations
const int MOD = 1e9 + 7;
    int countAnagrams(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word) {
            words.push_back(word);
        }
        
        long long result = 1;
        
        // For each word, calculate distinct permutations
        for(const string& word : words) {
            long long wordPermutations = getDistinctPermutations(word);
            result = (result * wordPermutations) % MOD;
        }
        
        return result;
    }
    
private:
    long long getDistinctPermutations(const string& word) {
        // Count frequency of each character
        unordered_map<char, int> freq;
        for(char c : word) {
            freq[c]++;
        }
        
        // Calculate n! / (count1! * count2! * ... * countk!)
        long long numerator = factorial(word.length());
        long long denominator = 1;
        
        for(auto& p : freq) {
            denominator = (denominator * factorial(p.second)) % MOD;
        }
        
        // Return numerator / denominator mod MOD
        return (numerator * modInverse(denominator, MOD)) % MOD;
    }
    
    long long factorial(int n) {
        long long result = 1;
        for(int i = 2; i <= n; i++) {
            result = (result * i) % MOD;
        }
        return result;
    }
    
    // Calculate modular inverse using Fermat's little theorem
    // a^(-1) ≡ a^(p-2) (mod p) where p is prime
    long long modInverse(long long a, long long mod) {
        return power(a, mod - 2, mod);
    }
    
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while(exp > 0) {
            if(exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
};