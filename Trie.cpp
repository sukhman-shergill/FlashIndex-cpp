#include "Trie.h"

// Constructor - Create root node
Trie::Trie()
{
  root = new TrieNode();
}

// Destructor - Free all memory to prevent memory leaks
Trie::~Trie()
{
  deleteAllNodes(root);
}

// Helper function to recursively delete all nodes
void Trie::deleteAllNodes(TrieNode *node)
{
  if (node == nullptr)
  {
    return;
  }

  // Delete all children first
  for (auto &pair : node->children)
  {
    deleteAllNodes(pair.second);
  }

  // Then delete current node
  delete node;
}

// Insert function - Add a word to the Trie
// Time Complexity: O(L) where L is word length
// Space Complexity: O(L) in worst case when all characters are new
void Trie::insert(string word)
{
  TrieNode *currentNode = root;

  // Traverse through each character of the word
  for (int i = 0; i < word.length(); i++)
  {
    char ch = word[i];

    // Check if character already exists in children
    if (currentNode->children.find(ch) == currentNode->children.end())
    {
      // Character not found, create new node
      currentNode->children[ch] = new TrieNode();
    }

    // Move to the child node
    currentNode = currentNode->children[ch];
  }

  // Mark the last node as end of word
  currentNode->isEndOfWord = true;
}

// Search function - Check if exact word exists in Trie
// Time Complexity: O(L) where L is word length
// Returns true if word exists, false otherwise
bool Trie::search(string word)
{
  TrieNode *currentNode = root;

  // Traverse through each character
  for (int i = 0; i < word.length(); i++)
  {
    char ch = word[i];

    // Check if character exists in children
    if (currentNode->children.find(ch) == currentNode->children.end())
    {
      // Character not found, word doesn't exist
      return false;
    }

    // Move to child node
    currentNode = currentNode->children[ch];
  }

  // Return true only if this node marks end of a word
  return currentNode->isEndOfWord;
}

// StartsWith function - Check if any word starts with given prefix
// Time Complexity: O(L) where L is prefix length
// Returns true if prefix exists, false otherwise
bool Trie::startsWith(string prefix)
{
  TrieNode *currentNode = root;

  // Traverse through each character of prefix
  for (int i = 0; i < prefix.length(); i++)
  {
    char ch = prefix[i];

    // Check if character exists in children
    if (currentNode->children.find(ch) == currentNode->children.end())
    {
      // Character not found, prefix doesn't exist
      return false;
    }

    // Move to child node
    currentNode = currentNode->children[ch];
  }

  // If we reached here, prefix exists
  return true;
}
