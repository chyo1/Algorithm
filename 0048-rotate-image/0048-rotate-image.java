class Solution {
    public void rotate(int[][] matrix) {
        int size = matrix.length;
        int leftIdx = 0, rightIdx = size - 1;

        int l, r, u, d;
        while (leftIdx < rightIdx) {

            // u -> r -> d -> l
            for (int i = leftIdx; i < rightIdx; i++) {
                u = matrix[leftIdx][i];
                d = matrix[rightIdx][size - i - 1];
                l = matrix[size - i - 1][leftIdx];
                r = matrix[i][rightIdx];
                
                matrix[i][rightIdx] = u;
                matrix[rightIdx][size - i - 1] = r;
                matrix[size - i - 1][leftIdx] = d;
                matrix[leftIdx][i] = l;
            }
            leftIdx++;
            rightIdx--;
        }
    }
}