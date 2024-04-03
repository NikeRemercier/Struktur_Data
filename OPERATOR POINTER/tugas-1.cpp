#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    if (n == 0)
        return 0;

    int Index = 0;
    int anchor = 0;

    for (int i = 0; i < n; i++) {
        if (i + 1 == n || chars[i] != chars[i + 1]) {
            chars[Index++] = chars[anchor];
            if (i > anchor) {
                string countStr = to_string(i - anchor + 1);
                for (char c : countStr)
                    chars[Index++] = c;
            }
            anchor = i + 1;
        }
    }
    return Index;
}

int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};
    int compressedLength = compress(chars);
    cout << "Output: " << compressedLength << ", [";
    for (int i = 0; i < compressedLength; ++i) {
        cout << "\"" << chars[i] << "\"";
        if (i != compressedLength - 1)
            cout << ",";
    }
    cout << "]" << endl;
    return 0;
}
