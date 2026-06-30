class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;
        st.reserve(operations.size());   // Avoids repeated reallocations

        int sum = 0;

        for (const string &op : operations) {
            if (op == "+") {
                int val = st[st.size() - 1] + st[st.size() - 2];
                st.push_back(val);
                sum += val;
            }
            else if (op == "D") {
                int val = st.back() * 2;
                st.push_back(val);
                sum += val;
            }
            else if (op == "C") {
                sum -= st.back();
                st.pop_back();
            }
            else {
                int val = stoi(op);
                st.push_back(val);
                sum += val;
            }
        }

        return sum;
    }
};
