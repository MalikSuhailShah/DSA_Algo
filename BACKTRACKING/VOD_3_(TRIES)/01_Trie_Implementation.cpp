

#include<iostream>
#include<vector>
using namespace std;


class Node {
public:
    char data;
    bool isTerminal;
    Node* children[26];

    Node(char data) {
        this->data = data;
        this->isTerminal = false;

        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
    }
};
class Trie {
public:
    Node* root;
    Trie() { root = new Node('\0'); }

    void insert(string word) {

        Node* curr = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int index = ch - 'a';
            if (curr->children[index] == NULL) {
                curr->children[index] = new Node(ch);
            }

            curr = curr->children[index];
        }
        curr->isTerminal = true;
    }

    bool search(string word) {

        Node* curr = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int index = ch - 'a';
            if (curr->children[index] == NULL)
                return false;
            curr = curr->children[index];
        }
        if (curr->isTerminal == false)
            return false;

        return true;
    }

    bool startsWith(string prefix) {

        Node* curr = root;

        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];
            int index = ch - 'a';
            if (curr->children[index] == NULL)
                return false;
            curr = curr->children[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


int main (){

}