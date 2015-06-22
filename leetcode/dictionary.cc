#include <string>
#include <stdio.h>
using namespace std;

class WordDictionary {
public:
    class Node{
    public:
        bool found;
        Node* child[26];
        Node():
        found(false) {
            for(int i = 0; i < 26; ++i){
                child[i] = NULL;
            }
        }
    };

    WordDictionary(){
        m_root = new Node();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
    	recurAddParent(word, m_root, 0);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return recurSearchWord(word, m_root, 0);
    }

    void recurAddParent(string& word, Node* parent, int p){
        if (p == word.size()) {
            parent->found = true;
            return;
        }
        Node*& curr = *(parent->child + word[p]-'a');
        if (!curr) curr = new Node();
        recurAddParent(word, curr, p+1);
    }

    void recurAddCurrent(string& word, Node** current, int p){
        if (p+1 == word.size()) {
            (*current)->found = true;
            return;
        }
        Node** next = current + word[p]-'a';
        if (!*next) *next = new Node();
        recurAddCurrent(word, next, p+1);
    }
    bool recurSearchWord(string& word, Node* node, int p){
        if (!node) return false;
        if (word.size() == p && node->found) return true;
        if (word.size() == p && !node->found) return false;
        if (word[p] == '.') {
            bool found = false;
            for (int i = 0; i < 26; ++i){
                Node* next = *(node->child + i);
                found |=recurSearchWord(word, next, p+1);
                if (found) return true;
            }
            return false;
        } else{
            Node* next = *(node->child + word[p]-'a');
            return recurSearchWord(word, next, p+1);
        }

    }
private:
    Node* m_root;
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern")

};

int main(){
	WordDictionary d;
	string s = "ab";
	string t = "ac";
	d.addWord(s);
	if (d.search(t)) printf ("found\n");

}
