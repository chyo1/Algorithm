class Solution {
public:
    string convert(string s, int numRows) {
        string con[1000] = {"", };

        int row = 0, add = 1;
        if (numRows == 1)
            return s;
        for (int i = 0; i < s.size(); i++) {
            con[row].append(1, s[i]);

            if (row == numRows - 1)
                add = -1;
            else if (row == 0)
                add = 1;
            row += add;
        }

        string ans = "";
        for (int i = 0; i < numRows; i++)
            ans.append(con[i]);
        return ans;
    }
};