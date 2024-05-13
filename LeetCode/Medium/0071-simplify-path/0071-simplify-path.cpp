class Solution {
public:
    string simplifyPath(string path) {
        deque<string> directories;
        
        int idx = 0, len = path.length();
        while(idx < len) {
            string dir = "";
            
            while (idx < len && path[idx] == '/')
                idx++;
            while (idx < len && path[idx] != '/')
                dir += path[idx++];
            
            if (dir == "")
                break ;
            if (dir == "..") {
                if (directories.size())
                    directories.pop_front();
            }
            else if (dir != ".")
                directories.push_front(dir);    
        }
        
        string ans = "";
        while (directories.size()) {
            ans += "/";
            ans += directories.back();
            directories.pop_back();
        }           
        return ans == "" ? "/" : ans;   
    }
};