class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> st;
        if (n == 0) st.insert("");
        else {
            vector<string> last = generateParenthesis(n - 1);
            for (auto a : last) {
                for (int i = 0; i < a.size(); ++i) {
                    if (a[i] == '(') {
                        a.insert(a.begin() + i + 1, '(');
                        a.insert(a.begin() + i + 2, ')');
                        st.insert(a);
                        a.erase(a.begin() + i + 1, a.begin() + i + 3);
                    }
                }
                st.insert("()" + a);
            }
        }
        return vector<string>(st.begin(), st.end());
    }
};
