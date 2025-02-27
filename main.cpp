#include<iostream>
#include<string>
using namespace std;

void IsKPeriodic(const string& str) {
    int len = str.length();
    if (len == 0) {
        cout << "Periodicity: 0, Substring empty" << endl;
        return;
    }

    for (int k = 1; k <= len; ++k) {
        if (len % k == 0) {
            string substring = str.substr(0, k);
            bool isPeriodic = true;
            for (int i = k; i < len; i += k) {
                if (str.substr(i, k) != substring) {
                    isPeriodic = false;
                    break;
                }
            }
            if (isPeriodic) {
                cout << "Periodicity: " << k << ", Substring: " << substring << endl;
                return;
            }
        }
    }
    cout << "Periodicity: " << len << ", Substring: " << str << endl;
}

int main() {
    IsKPeriodic("abcabcabcabc");
    IsKPeriodic("abcdabcd");
    IsKPeriodic("aaaaaa");
    IsKPeriodic("abcdef");
    IsKPeriodic("abcdeabcdeabcde");
    return 0;
}