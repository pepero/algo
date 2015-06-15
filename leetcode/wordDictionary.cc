class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {


    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {

    }

    void recurAddWord(string& word, Node*& child, int p){
        if (p == word.size()) return;
        Node* curr = child + word[p]-'a';
        if (!curr)  = new Node(word[p]);
        recurAddWord(word, curr->child, p+1);
    }

};
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern")

class Node{
    char m_c;
    Node* child[26];
    Node(char c):
    m_c(c){
        for(int i = 0; i < 26; ++i){
            n[i] = NULL;
        }
    }
}
