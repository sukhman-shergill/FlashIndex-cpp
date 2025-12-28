#include <iostream>
#include "Trie.h"

using namespace std;

// Function to display menu options
void displayMenu()
{
  cout << "\n========================================" << endl;
  cout << "   IN-MEMORY SEARCH ENGINE (TRIE)" << endl;
  cout << "========================================" << endl;
  cout << "1. Insert a word" << endl;
  cout << "2. Search for a word" << endl;
  cout << "3. Check if prefix exists" << endl;
  cout << "4. Exit" << endl;
  cout << "========================================" << endl;
  cout << "Enter your choice: ";
}

int main()
{
  // Create Trie object
  Trie searchEngine;
  int choice;
  string inputWord;

  cout << "Welcome to FlashIndex - Fast In-Memory Search Engine!" << endl;
  cout << "Built using Trie (Prefix Tree) Data Structure" << endl;

  // Menu-driven program loop
  while (true)
  {
    displayMenu();
    cin >> choice;

    // Clear input buffer
    cin.ignore();

    switch (choice)
    {
    case 1:
      // Insert word
      cout << "\nEnter word to insert: ";
      getline(cin, inputWord);

      // Convert to lowercase for consistency
      for (int i = 0; i < inputWord.length(); i++)
      {
        inputWord[i] = tolower(inputWord[i]);
      }

      searchEngine.insert(inputWord);
      cout << "✓ Word '" << inputWord << "' inserted successfully!" << endl;
      break;

    case 2:
      // Search for exact word
      cout << "\nEnter word to search: ";
      getline(cin, inputWord);

      // Convert to lowercase
      for (int i = 0; i < inputWord.length(); i++)
      {
        inputWord[i] = tolower(inputWord[i]);
      }

      if (searchEngine.search(inputWord))
      {
        cout << "✓ Word '" << inputWord << "' FOUND in search engine!" << endl;
      }
      else
      {
        cout << "✗ Word '" << inputWord << "' NOT FOUND in search engine!" << endl;
      }
      break;

    case 3:
      // Check if prefix exists
      cout << "\nEnter prefix to check: ";
      getline(cin, inputWord);

      // Convert to lowercase
      for (int i = 0; i < inputWord.length(); i++)
      {
        inputWord[i] = tolower(inputWord[i]);
      }

      if (searchEngine.startsWith(inputWord))
      {
        cout << "✓ Prefix '" << inputWord << "' EXISTS! Words starting with this prefix are present." << endl;
      }
      else
      {
        cout << "✗ Prefix '" << inputWord << "' DOES NOT EXIST!" << endl;
      }
      break;

    case 4:
      // Exit program
      cout << "\nThank you for using FlashIndex!" << endl;
      cout << "Exiting..." << endl;
      return 0;

    default:
      // Invalid choice
      cout << "\n✗ Invalid choice! Please enter 1-4." << endl;
      break;
    }
  }

  return 0;
}
