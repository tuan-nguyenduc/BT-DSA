#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode *getNode () {
    TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(TrieNode *root, string str) {
    TrieNode* temp = root;

    for (int i = 0; i < str.length(); i++) {
        int index = str[i] - 'a';
        if (!temp->children[index]) {
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
    }
    temp->isEndOfWord = true;
}

bool isContain(TrieNode* root, string str) {
    TrieNode* temp = root;
    for (int i = 0; i < str.length(); i++) {
        int index = str[i] - 'a';
        if (!temp->children[index]) {
            return false;
        }
        temp = temp->children[index];
    }

    return (temp->isEndOfWord);
}

void deleteTrie(TrieNode* node) {
    if (node == nullptr) {
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        deleteTrie(node->children[i]);
    }
    delete node;
}

void search_by_prefix(TrieNode* root, string prefix, vector<string>& results, string current_prefix = "") {
    if (root == nullptr) {
        return;
    }

    if (!prefix.empty()) {
        char nextChar = prefix[0];
        int index = nextChar - 'a';
        if (root->children[index]) {
            string newPrefix = prefix.substr(1);
            search_by_prefix(root->children[index], newPrefix, results, current_prefix + nextChar);
        }
        else {
            return;
        }
    }
    else {
        if (root->isEndOfWord) {
            results.push_back(current_prefix);
        }
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root->children[i]) {
                char nextChar = 'a' + i;
                search_by_prefix(root->children[i], prefix, results, current_prefix + nextChar);
            }
        }
    }
}


int main() {
    string values[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(values)/sizeof(values[0]);
    vector<string> all_words;
    string prefix;;

    cout << "Type your word: ";
    cin >> prefix;
    

    struct TrieNode* root = getNode();

    for (int i = 0; i < n; i++) {
        insert(root, values[i]);
    }

    cout << "Search for 'the': " << (isContain(root, "the") ? "Found" : "Not found") << endl;
    cout << "Search for 'there': " << (isContain(root, "there") ? "Found" : "Not found") << endl;
    cout << "Search for 'abcde': " << (isContain(root, "abcde") ? "Found" : "Not found") << endl;

    search_by_prefix(root, prefix, all_words);

    if (all_words.empty()) {
        cout << "No words found with the prefix '" << prefix << "'" << endl;
    } else {
        cout << "Words with the prefix '" << prefix << "': ";
        for (const string& word : all_words) {
            cout << word << " ";
        }
        cout << endl;
    }
    deleteTrie(root);
    return 0;

}

