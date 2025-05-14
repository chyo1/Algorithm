import java.util.*;

class Solution {
    private char[][] result = new char[3][3];
    
    public int solution(String[] board) {
        
        char[][] state = new char[3][3];
        for (int i = 0; i < 3; i++) {
            result[i] = board[i].toCharArray();
            Arrays.fill(state[i], '.');
        }
        
        return findState(state, false) ? 1 : 0;
    }
    
    private boolean findState(char[][] board, boolean bef) {
        // compare now state with board
        boolean isSameState = true;
        out: for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != result[i][j]) {
                    isSameState = false;
                    break out;
                }
            }
        }
        if (isSameState) {
            return true;
        }
        
        // check end condition
        for (int i = 0; i < 3; i++) {
            if ( (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
               || (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) ) {
                return false;
            }
        }
        if (board[1][1] != '.' && ((board[0][0] == board[1][1] && board[1][1] == board[2][2])
            || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) ) {
            return false;
        }
        
        // make nextState
        char nowChar = bef ? 'X' : 'O';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '.') {
                    board[i][j] = nowChar;
                    if (findState(board, !bef)) {
                        return true;
                    }
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }
}