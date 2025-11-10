// DAA_Huffman.cpp
#include <bits/stdc++.h>
using namespace std;

// Node structure for Huffman tree
struct Node {
  char ch;
  int freq;
  Node *left, *right;

  Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
  Node(int f, Node *l, Node *r) : ch('\0'), freq(f), left(l), right(r) {}
};

// Custom comparator for priority queue (min-heap)
struct Compare {
  bool operator()(Node *a, Node *b) { return a->freq > b->freq; }
};

// Recursive function to generate Huffman codes
void generateCodes(Node *root, string code,
                   unordered_map<char, string> &huffmanCode) {
  if (!root)
    return;

  // Leaf node — store the code
  if (!root->left && !root->right) {
    huffmanCode[root->ch] = code;
    return;
  }

  generateCodes(root->left, code + "0", huffmanCode);
  generateCodes(root->right, code + "1", huffmanCode);
}

int main() {
  string text = "huffman coding example";

  // Count frequency of each character
  unordered_map<char, int> freq;
  for (char ch : text)
    freq[ch]++;

  // Priority queue (min-heap) for building Huffman tree
  priority_queue<Node *, vector<Node *>, Compare> pq;

  // Create a leaf node for each character
  for (auto &[ch, f] : freq)
    pq.push(new Node(ch, f));

  // Build the Huffman tree
  while (pq.size() > 1) {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();

    Node *parent = new Node(left->freq + right->freq, left, right);
    pq.push(parent);
  }

  // Root of Huffman Tree
  Node *root = pq.top();

  // Generate Huffman codes
  unordered_map<char, string> huffmanCode;
  generateCodes(root, "", huffmanCode);

  // Print the codes
  cout << "Huffman Codes:\n";
  for (auto &[ch, code] : huffmanCode)
    cout << ch << " : " << code << "\n";

  // Encode the input text
  string encoded;
  for (char ch : text)
    encoded += huffmanCode[ch];

  cout << "\nOriginal text: " << text << endl;
  cout << "Encoded text: " << encoded << endl;

  return 0;
}
