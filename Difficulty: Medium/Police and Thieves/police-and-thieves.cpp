class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
         deque<int> police_q, thief_q;
    int caught_count = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 'P') {
            // Clean up old thieves
            while (!thief_q.empty() && thief_q.front() < i - k)
                thief_q.pop_front();

            if (!thief_q.empty()) {
                thief_q.pop_front();
                caught_count++;
            } else {
                police_q.push_back(i);
            }
        } else if (arr[i] == 'T') {
            // Clean up old police
            while (!police_q.empty() && police_q.front() < i - k)
                police_q.pop_front();

            if (!police_q.empty()) {
                police_q.pop_front();
                caught_count++;
            } else {
                thief_q.push_back(i);
            }
        }
    }

    return caught_count;
    }
};