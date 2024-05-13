class Solution {
public:
    string simplifyPath(string path) {
        deque<string> directories;
        
        int idx = 0, len = path.length();
        while(idx < len) {
            string dir = "";
            
            // "/" 를 기준으로 디렉토리 분리
            while (idx < len && path[idx] == '/')
                idx++;
            while (idx < len && path[idx] != '/')
                dir += path[idx++];
            
            // 문장 끝까지 탐색
            if (dir == "")
                break ;
            
            // 이전 디렉토리, 디렉토리 하나 위로 이동
            if (dir == "..") {
                if (directories.size())
                    directories.pop_front();
            }
            
            // 현재 디렉토리, 경로에 넣지 않음
            else if (dir != ".")
                directories.push_front(dir);    
        }
        
        // 최종 path 생성
        string ans = "";
        while (directories.size()) {
            ans += "/";
            ans += directories.back();
            directories.pop_back();
        } 
        
        return ans == "" ? "/" : ans;   
    }
};