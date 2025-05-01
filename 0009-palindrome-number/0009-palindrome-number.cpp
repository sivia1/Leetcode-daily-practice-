class Solution {
public:
//idea is to revert the number itself, and then compare the number with original number. if they are same
//then the number is a plaindrome.
//to take care of overflow issue, revert only half of int
    bool isPalindrome(int x) {
        //special cases:
        //when x < 0, x is not a palindrome, also if the last digit of the number is 0, in order to be a
        //palindrome, the first digit of the number also needs to be 0. Only 0
        //satisfy this property
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        //When the length is an odd number, we can get rid of the middle digit
        //by revertedNumber/10 for example when the input is 12321, at the end
        //of the while loop we get x = 12, revertedNumber = 123, since the 
        //middle digit doesn't matter in palindrome(it will always equal to 
        //itself), we can simply get rid of it
        return x == revertedNumber || x == revertedNumber / 10;
    }
};