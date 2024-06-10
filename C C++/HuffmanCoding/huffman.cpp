#include<bits/stdc++.h>
using namespace std;

//string encoded_string="";
vector<bool>encoded_string;
string decode_string="";
map<char,string>mp;


struct Node{
	char data;
	int freq;
	Node* left;
	Node* right;
	Node(char d, int f){
		data=d;
		freq=f;
		left=right=NULL;
	}
};


void encode(Node* root, string key){
	if(root==NULL)
		return ;
	if(root->data!='#'){
		//cout<<root->data<<" "<<key<<endl;
		mp[root->data]=key;
	}
	encode(root->left,key+'0');
	encode(root->right,key+'1');
	return ;
}

void decode(Node* root){
	Node* cur=root;
	for(auto it:encoded_string){
		cur= it == 0 ? cur->left : cur->right;
		if(cur->data!='#'){
			decode_string+=cur->data;
			cur=root;
		}
	}
}


int main(){
	string str; getline(cin,str);
	map<char,int>fq;
	for(char it:str)
		fq[it]++;

	priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
	
	for(auto it:fq){
		Node* cur=new Node(it.first,it.second);
		pq.push({it.second,cur});
	}
	if(fq.size()==1){
		Node* cur=new Node('#',INT_MAX);
		pq.push({INT_MAX,cur});
	}
	while(pq.size()>1){
		pair<int,Node*>p1=pq.top();
		pq.pop();
		pair<int,Node*>p2=pq.top();
		pq.pop();
		int val=p1.first+p2.first;
		Node* newNode=new Node('#',val);
		newNode->left=p1.second;
		newNode->right=p2.second;
		pq.push({val,newNode});
	}

	Node* root=pq.top().second;
	encode(pq.top().second,"");
	pq.pop();

	for(auto it:mp)
		cout<<it.first<<" "<<it.second<<endl;

	for(auto it:str){
		string t=mp[it];
		for(char it1:t){
			if(it1=='0')
				encoded_string.push_back(0);
			else
				encoded_string.push_back(1);
		}
	}
	
	for(auto it:encoded_string){
		if(it)
			cout<<1;
		else
			cout<<0;
	}
	cout<<endl;
	decode(root);
	cout<<decode_string<<endl;
} 