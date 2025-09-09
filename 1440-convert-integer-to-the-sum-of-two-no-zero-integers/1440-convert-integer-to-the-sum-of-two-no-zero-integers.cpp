class Solution {
public:
//approach --> we can do one sweep from 1 to n for a and get the complement of the number which is b then check for both a and b numbers to not have zero then we consider it as valid. 
    bool hasNoZero(int num) {
        while(num > 0) {
            if(num % 10 == 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int a = 1; a < n; a++) {
            int b = n-a;

            if(hasNoZero(a) && hasNoZero(b)) {
                return{a, b};
            }
        }
        return {};
    }
};