#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char value;
    bool isTerminal;
    TrieNode* childeren[26];

    TrieNode(char val){
        this->value = val;
        this->isTerminal = false;
        for(int i=0; i<26; i++){
            childeren[i]=NULL;
        }
    }
};

//insert_in_TieNode

void insertInTrieNode(TrieNode* root, string word){
    //cout<<"inserting: "<<word<<endl;
    //base case 
    if(word.length()==0){
        root->isTerminal = true;
        return;
    }
    //1 case me solve karunga
    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;
    if(root->childeren[index]==NULL){
        //present nahi hai
        //creating New Node
        child = new TrieNode(ch);
        //root k is index me child daal diya
        root->childeren[index] = child;
    }else{
        //present hai
        child = root->childeren[index];
    }

    //baki kam recursion karega
    insertInTrieNode(child,word.substr(1));
}

bool searchInTrieNode(TrieNode* root, string word){
  //base case 
  if(word.length()==0){
    if(root->isTerminal == true){
      return true;
    }
    else{
      return false;
    }
  }
  //1 case mujhe solve karna hai
  char ch = word[0];
  int index = ch-'a';
  TrieNode* child; //adress store karega
  if(root->childeren[index]==NULL){
    return false;
  }
  else{
    //character wala node mil gya trie me 
    //new root ab child ho gya
    child = root->childeren[index];
  }
  //aage ka answer recursion karega
  bool recKaAns = searchInTrieNode(child,word.substr(1));

  return recKaAns;
}

void deleteFromTrie(TrieNode* root,string word){
  if(word.length()==0){
    root->isTerminal = false;
  }
  //1 case mera
  char ch = word[0];
  int index = ch-'a';
  TrieNode* child;

  if(root->childeren[index]==NULL){
    return;
  }
  else{
    child = root->childeren[index];
  }
  //baki recursion tera
  deleteFromTrie(child, word.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('-');
    insertInTrieNode(root, "Rohit");
    insertInTrieNode(root,"roman");
    insertInTrieNode(root, "abhishek");
    insertInTrieNode(root, "abhisarika");
    cout<<"Insertion done"<<endl;

    cout<<"Checking in Trie for roman"<<endl;
    bool result = searchInTrieNode(root, "roman");
    if(result){
      cout<<"found"<<endl;
    }
    else {
      cout<<"not found"<<endl;
    }

    cout<<"deletion code begin"<<endl;

    deleteFromTrie(root,"roman");

    bool result2 = searchInTrieNode(root, "roman");
    if(result2){
      cout<<"found"<<endl;
    }
    else {
      cout<<"not found"<<endl;
    }

}