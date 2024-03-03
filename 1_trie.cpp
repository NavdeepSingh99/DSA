#include<iostream>
using namespace std;

class Node{
    public:
        char data;
        Node* childrens[26];
        bool isWord;

        Node(char ch){
            data = ch;
            isWord = false;
            for(int i=0; i<26; i++) childrens[i] = NULL;
        }
};



class Trie{
    public:
        Node* root;
        Trie(){
            root = new Node('\0');
        }

        void insertUtil(string word){
            int n = word.size();
            Node* temp = root;

            for(int i=0; i<n; i++){
                int pos = word[i] - 'a';
                
                if(temp->childrens[pos] == NULL) temp->childrens[pos] = new Node(word[i]);
                temp = temp->childrens[pos];

                if(i+1== n) temp->isWord = true;
            }
        }

        void insert(string word){
            insertUtil(word);
        }

        bool searchUtil(string word){
            Node *temp = root;
            int n = word.size();

            for(int i=0; i<n; i++){
                int pos = word[i] - 'a';

                if(temp->childrens[pos] == NULL) return false;
                temp = temp->childrens[pos];

                if(i+1 == n) return temp->isWord;
            }

            return false;
        }

        bool search(string word){
            return searchUtil(word);
        }

        bool isNoChild(Node *temp){
            if(temp->isWord == true) return false;
            for(int i=0; i<26; i++){
                if(temp->childrens[i] != NULL) return false;
            }
            return true;
        }
        bool removeUtil(Node* temp, string word, int i){
            if(i == word.size()){
                if(temp->isWord == false) return false;

                temp->isWord = false;
                if(isNoChild(temp)) return true;
                return false;
            }

            if('a' - word[i] > 26) return false;
            bool canRemove = removeUtil(temp->childrens[word[i] - 'a'] ,word, i+1);
            if(canRemove == false) return false;

            temp->childrens[word[i] -'a'] = NULL;
            
            if(isNoChild(temp)) {
                delete temp;
                return true;
            }
            return false;
        }
        void remove(string word){
            Node *temp = root;
            removeUtil(temp, word, 0);
        }
};

int main(){
    Trie *root = new Trie();

    int choice;
    string word;
    
    do{
        cout << "1: Insert\n2: Search\n3: Remove\n4: Exit\n";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
                cout << "Enter word: ";cin >> word; cout <<endl;
                root->insert(word);
                break;
            case 2:
                cout << "Enter word: ";cin >> word; cout <<endl;
                cout << root->search(word) << endl;
                break;
            case 3:
                cout << "Enter word: ";cin >> word; cout <<endl;
                root->remove(word);
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Enter number between 1 to 4" << endl;
        }

    }while(true);


    return 0;
}
