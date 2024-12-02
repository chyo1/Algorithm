class Solution {
public:
    vector<string> addresses;
    void getIP(string s, int cnt, string ip) {
        if (cnt == 4) {
            if (s.empty())
                addresses.push_back(ip.substr(0, ip.size() - 1));
            else
                return;
        }

        if (s[0] == '0') {
            return getIP(s.substr(1), cnt + 1, ip + "0.");
        }
    
        for (int i = 0; i < 3; i++) {
            if (s.size() <= i) break;
            string sub = s.substr(0, i + 1);
            if (0 <= stoi(sub) && stoi(sub) <= 255)
                getIP(s.substr(i + 1), cnt + 1, ip + sub + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        getIP(s, 0, "");
        return addresses;
    }
};