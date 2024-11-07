//Write a program to implement Huffman Encoding using a greedy strategy


#include <bits/stdc++.h> 
using namespace std; 

// A Huffman tree node 
struct Node { 
	char data; 
	int freq; 
	// Left and right child 
	Node *left, *right; 

	Node(char data, int freq) 
	{ 
		left = right = NULL;
		this->data = data; 
		this->freq = freq; 
	} 
}; 

// For comparison of two heap nodes (needed in min heap) 
struct compare { 
	bool operator()(Node* l, Node* r) 
	{ 
		return (l->freq > r->freq); 
	} 
}; 

// Prints huffman codes from the root of Huffman Tree. 
void printCodes(Node* root, string str) 
{ 
	if (!root) 
		return; 

	if (root->data != '$') 
		cout << root->data << ": " << str << "\n"; 

	printCodes(root->left, str + "0"); 
	printCodes(root->right, str + "1"); 
} 

// The main function that builds a Huffman Tree and 
// print codes by traversing the built Huffman Tree 
void HuffmanCodes(vector<pair<char,int>> &data, int size) 
{ 
	struct Node *left, *right, *top; 

	// Create a min heap & inserts all characters of data[] 
	priority_queue<Node*, vector<Node*>, compare> minHeap; 

	for (int i = 0; i < size; ++i){ 
		minHeap.push(new Node(data[i].first, data[i].second)); 
	}

	// Iterate while size of heap doesn't become 1 
	while (minHeap.size() != 1) { 
		// Extract the two minimum  freq items from min heap 
		left = minHeap.top(); 
		minHeap.pop(); 

		right = minHeap.top(); 
		minHeap.pop(); 

		// Create a new internal node with frequency equal to the sum of the 
		// two nodes frequencies. Make the two extracted node as left and right children 
		// of this new node. Add this node to the min heap '$' is a special value 
		// for internal nodes, not used 
		top = new Node('$',left->freq + right->freq); 

		top->left = left; 
		top->right = right; 

		minHeap.push(top); 
	} 

	// Print Huffman codes using the Huffman tree built above 
	printCodes(minHeap.top(), ""); 
} 

int main() 
{ 

	int n;
	cout<<"Enter number of values = ";
	cin>>n;
	vector<pair<char,int>> val;
	for(int i=0;i<n;i++){
		char c;
		int freq;
		cin>>c>>freq;
		val.push_back({c,freq});
	}
	// char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
	// int freq[] = { 5, 9, 12, 13, 16, 45 }; 

	// int size = sizeof(arr) / sizeof(arr[0]); 

	HuffmanCodes(val, n); 

	return 0; 
} 


