class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        //edge cases:
        // 'A' --> Bob wins; return false
        // 'B' --> Alice can't make first move; return false
        // 'AA' --> Bob wins; return false
        // 'BB' --> Alice can't make first move; return false
        // 'AB' --> No one makes a move bob wins; return false
        // 'BA' --> No one makes a move bob wins; return false
        //so (n < 3) --> return false; 
        if(n < 3) {
            return false;
        }

        int a_moves = 0, b_moves = 0;
        for(int i = 1; i < n-1; i++) {
            if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A') {
                a_moves++;
            }
            if(colors[i-1] == 'B' && colors[i] == 'B' && colors[i+1] == 'B') {
                b_moves++;
            }
        }
        return a_moves > b_moves;
    }
};