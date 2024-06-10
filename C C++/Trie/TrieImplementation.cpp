#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
	TrieNode *child[26];
	bool isEnd;
	TrieNode(){
		isEnd=false;
		for(int i=0;i<26;i++)
			child[i]=NULL;
	}
};

TrieNode* insert(TrieNode* root, string &key){
	TrieNode* cur=root;
	int len=key.size();
	for(int i=0;i<len;i++){
		if(cur->child[key[i]-'a']==NULL){
			TrieNode* newNode=new TrieNode();
			cur->child[key[i]-'a']=newNode;
		}
		cur=cur->child[key[i]-'a'];
	}
	cur->isEnd=true;
	return root;
}

bool search(TrieNode* root, string &key){
	TrieNode* cur=root;
	int len=key.size();
	for(int i=0;i<len;i++){
		if(cur->child[key[i]-'a']==NULL)
			return false;
		cur=cur->child[key[i]-'a'];
	}
	return cur->isEnd;
}

bool deleteKey(TrieNode* root, string &key){
	TrieNode* cur=root;
	int len=key.size();
	for(int i=0;i<len;i++){
		if(cur->child[key[i]-'a']==NULL)
			return false;
		cur=cur->child[key[i]-'a'];
	}
	return cur->isEnd;
}

int main(){
	TrieNode* root=new TrieNode();
	int n; cin>>n;
	for(int i=0;i<n;i++){
		string s; cin>>s;
		root=insert(root,s);
	}
	int m; cin>>m;
	for(int i=0;i<m;i++){
		string s; cin>>s;
		if(search(root,s))
			cout<<s<<" is present in the Trie\n";
		else
			cout<<s<<" is not present in the Trie\n";
	}
	int del; cin>>del;
	for(int i=0;i<del;i++){
		string s; cin>>s;
		if(deleteKey(root,s))
			cout<<s<<" is deleted\n";
		else
			cout<<s<<" is not present in the Trie\n";
	}
}
