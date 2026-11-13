

#include<iostream>
#include<vector>
using namespace std;


class Node{
    public:
    char data;
    bool isTerminal;
    Node* children[26];
    int countOfWord;
    int prefixCount;

    Node (char data){
        this->data = data;
        this->isTerminal = false;
        this->countOfWord = 0;
        this->prefixCount = 0;
        for(int i=0 ; i<26 ; i++){
            this->children[i] = NULL;
        }
    }
};

class Trie {
	public:
    Node* root;
	    Trie() {
	        root = new Node('\0');
	    }

	    void insert(string word) {
            Node* curr = root;
	        for(int i = 0 ; i < word.length() ; i++){
                char ch = word[i];
                int num = ch - 'a';
                if(curr -> children[num]==NULL){
                    Node* temp = new Node(ch);
                 
                    curr -> children[num] = temp;
                }
                curr = curr -> children[num];
                curr -> prefixCount++;
            }
            curr -> isTerminal = true;
            curr -> countOfWord++;
    	}

	    int countWordsEqualTo(string word) {
            Node* curr = root;
            for(int i=0;i<word.length();i++){
                char ch = word[i];
                int num = ch - 'a';

                if(curr -> children[num] == NULL){
                    return 0;
                }
                curr = curr -> children[num];
            }
            return curr -> countOfWord;
	        
    	}

	    int countWordsStartingWith(string word) {

            Node* curr = root;

            for(int i =0 ;i< word.length();i++){
                char ch = word[i];
                int num = ch - 'a';
                if(curr -> children[num]== NULL) return 0;

                curr = curr -> children[num];
            }
            return curr -> prefixCount;
	        
    	}

	    void erase(string word) {
             Node* curr = root;

            // first check whether complete word exist or not
            for(int i=0;i<word.length(); i++){
                int num = word[i] - 'a';
                if(curr -> children[num]== NULL) return ;

                curr = curr -> children[num];
            }

             // Do not erase a word that was never inserted.
            if(curr->countOfWord==0) return;

             // Update counts along the word's path
            curr = root;
             for(int i=0;i<word.length(); i++){
                int num = word[i] - 'a';
                curr = curr -> children[num];
                curr->prefixCount--;
            }
            
            curr->countOfWord--;
            if(curr->countOfWord==0) curr -> isTerminal = false;

	        
	    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */

int main (){

}