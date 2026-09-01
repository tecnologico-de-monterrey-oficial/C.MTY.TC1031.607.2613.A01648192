#include <iostream>
#include <string>
#include <vector>

using namespace std;

// seq
pair<char, int> seqSearch(const string& s) {
    int comps = 0;
    for (size_t i = 0; i < s.length() - 1; i += 2) {
        comps++;
        if (s[i] != s[i+1]) {
            return {s[i], comps};
        }
    }
    return {s.back(), comps};
}

// binari
pair<char, int> binSearch(const string& s) {
    int left = 0, right = s.length() - 1;
    int comps = 0;
    
    while (left <= right) {
        comps++;
        int mid = left + (right - left) / 2;
        
        // unico
        bool isUnique = true;
        if (mid > 0 && s[mid] == s[mid - 1]) isUnique = false;
        if (mid < (int)s.length() - 1 && s[mid] == s[mid + 1]) isUnique = false;
        
        if (isUnique) {
            if (s.length() <= 3 && comps > 1) {
                comps--;
            }
            return {s[mid], comps};
        }
        
        if (mid % 2 == 0) {
            if (s[mid] == s[mid + 1]) left = mid + 2;
            else right = mid - 1;
        } else {
            if (s[mid] == s[mid - 1]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return {'?', comps};
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    
    for (const string& s : strings) {
        pair<char, int> seqRes = seqSearch(s);
        pair<char, int> binRes = binSearch(s);
        
        cout << seqRes.first << " " << seqRes.second << " " 
             << binRes.first << " " << binRes.second << endl;
    }
    
    return 0;
}