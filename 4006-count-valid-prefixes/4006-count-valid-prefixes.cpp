class Solution {
public:
    int countValidPrefixes(string s) {

        int zero = 0;
        int one = 0;
        int cnt = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '0')
                zero++;
            else
                one++;

            if (zero - one <= 1 && one - zero <= 1)
                cnt++;
        }

        return cnt;
    }
};