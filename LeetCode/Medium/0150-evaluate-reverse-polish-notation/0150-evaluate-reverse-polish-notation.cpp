class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> nums;
        
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i]; 
       
            // 연산자라면 제일 최근에 저장된 값 2개를 꺼내 계산 후 다시 넣음
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
            
            // 숫자라면 스택에 값 넣기
            else
                nums.push(stoi(tokens[i]));
        }       
        return nums.top();
    }
};