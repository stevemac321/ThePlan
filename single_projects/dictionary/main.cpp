#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <cassert>

enum state { FOUND, NOTFOUND };

bool lookup(const char *s, int left, int right, const std::map<std::string, int> &m) {
    std::string key(s + left, right - left + 1);
    return m.find(key) != m.end();
}

bool is_words(const char *s, const std::map<std::string, int> &m, const size_t max_len) {
    std::queue<int> q;
    q.push(0);
    int length = strlen(s);
    
    while (!q.empty()) {
        int left = q.front();
        q.pop();

        if (left == length) {
            return true;
        }

        for (int right = left; right < length && (right - left) < max_len; ++right) {
            if (lookup(s, left, right, m)) {
                q.push(right + 1);
            }
        }
    }
    return false;
}

int main() {
    size_t max_len = 7; // Correct max length of the longest word
    std::map<std::string, int> m = {
        {"i", 1}, {"like", 4}, {"sam", 3}, {"sung", 4}, {"samsung", 6}, {"mobile", 6}
    };

    // Test cases
    char s1[] = "ilike";
    char s2[] = "idlike";
    char s3[] = "ilikesamsung";
    char s4[] = "ilikemobile";

    assert(is_words(s1, m, max_len) == true);
    assert(is_words(s2, m, max_len) == false);
    assert(is_words(s3, m, max_len) == true);
    assert(is_words(s4, m, max_len) == true);

    std::cout << "All tests passed.\n";
    return 0;
}
