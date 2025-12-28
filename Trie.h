#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// TrieNode structure - represents each node in the Trie
class TrieNode
{
public:
  // Using unordered_map for O(1) average case lookup of children
  unordered_map<char, TrieNode *> children;
  bool isEndOfWord; // Flag to mark if this node represents end of a word

  // Constructor to initialize the node
  TrieNode()
  {
    isEndOfWord = false;
  }
};

// Trie class - Main data structure for search engine
class Trie
{
private:
  TrieNode *root; // Root node of the Trie

public:
  // Constructor - Initialize the Trie with empty root
  Trie();

  // Destructor - Free all allocated memory
  ~Trie();

  // Insert a word into the Trie
  // Time Complexity: O(L) where L is the length of the word
  void insert(string word);

  // Search for exact word in the Trie
  // Time Complexity: O(L) where L is the length of the word
  bool search(string word);

  // Check if any word starts with given prefix
  // Time Complexity: O(L) where L is the length of the prefix
  bool startsWith(string prefix);

  // Helper function to delete all nodes (used by destructor)
  void deleteAllNodes(TrieNode *node);
};

#endif
