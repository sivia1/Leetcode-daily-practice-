class Solution {
public:
//without using + operator; bit manipulation
    int sum(int num1, int num2) {
        while(num2 != 0) {
            int carry = num1 & num2; //calculate carry
            num1 = num1 ^ num2; // add without carry
            num2 = carry << 1; //shift carry to the left
        }
        return num1;
    }
};