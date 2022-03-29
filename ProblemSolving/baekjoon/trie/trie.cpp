#include <bits/stdc++.h>
using namespace std;

class Trie {
    private:
        int toInteger(char alphabet) {
            return alphabet - 'a';
        }

    public:
        bool isTerminal;
        Trie* children[26];

        Trie() {
            this->isTerminal = false;
            for (int i=0; i<26; i++) {
                this->children[i] = NULL;
            }
        }

        void insert(const string str) {
            Trie* cursor = this;
            for (char element : str) {
                if (!cursor->children[toInteger(element)]) {
                    cursor->children[toInteger(element)] = new Trie();
                    cout << "insert " << element << "\n";
                }
                cursor = cursor->children[toInteger(element)];
            }
            cursor->isTerminal = true;
        }

        bool find(const string str) {
            bool result = true;
            Trie* cursor = this;
            for (char element : str) {
                if (!cursor->children[toInteger(element)]) {
                    result = false;
                    break;
                }
                cursor = cursor->children[toInteger(element)];
            }
            if (!cursor->isTerminal) {
                result = false;
            }
            return result;
        }
};

int main(void) {
    Trie trie;
    trie.insert("pen");
    trie.insert("pin");
    trie.insert("hi");
    cout << trie.find("pen") << "\n";
    cout << trie.find("pin") << "\n";
    cout << trie.find("hi") << "\n";
    return 0;
}