class Solution {
  public:
    string addString(string &s1, string &s2) {
    
    int i = s1.length() - 1;
    int j = s2.length() - 1;

    // initial carry is zero
    int carry = 0;

    // we will calculate and store the
    // resultant sum in reverse order in res
    string res = "";
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0)
            sum += (s1[i] - '0');

        if (j >= 0)
            sum += (s2[j] - '0');

        res.push_back(sum % 10 + '0');
        carry = sum / 10;
        i--;
        j--;
    }

    // remove leading zeroes which are currently
    // at the back due to reversed string res
    while (!res.empty() && res.back() == '0')
        res.pop_back();

    // reverse our final string
    reverse(res.begin(), res.end());

    return res;
}
    string minSum(vector<int> &arr) {
       
         vector<int> count(10, 0);
    
    // Count occurrences of each digit
    for (int num : arr) {
        count[num]++;
    }
    
    // Two strings for storing the two minimum numbers
    string s1 = "", s2 = "";
    
    // Flag to alternate between s1 and s2
    bool firstNum = true;
    
    // Traverse count array from 0 to 9
    for (int digit = 0; digit < 10; digit++) {
        
        // Add digit to appropriate string 
        // while it has occurrences
        while (count[digit]--) {
            if (firstNum) {
                
                // Avoid leading zeros for both numbers
                if (!(s1.empty() && digit == 0))
                    s1.push_back(digit + '0');
                firstNum = false;
            } else {
                if (!(s2.empty() && digit == 0))
                    s2.push_back(digit + '0');
                firstNum = true;
            }
        }
    }
    
    // Handle case where s1 or s2 might be empty
    if (s1.empty()) s1 = "0";
    if (s2.empty()) s2 = "0";
    
    return addString(s1, s2);
    }
};