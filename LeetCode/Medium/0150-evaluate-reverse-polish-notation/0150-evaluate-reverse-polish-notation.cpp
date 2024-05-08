class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> nums;
        
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i]; 
       
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num1, num2;
                num2 = nums.top();
                nums.pop();
                
                num1 = nums.top();
                nums.pop();

                if (tokens[i] == "+")
                    nums.push(num1 + num2);
                else if (tokens[i] == "-")
                    nums.push(num1 - num2);
                else if (tokens[i] == "*")
                    nums.push(num1 * num2);
                else if (tokens[i] == "/")
                    nums.push(num1 / num2);
            }
            else
                nums.push(stoi(tokens[i]));
        }       
        return nums.top();
    }
};