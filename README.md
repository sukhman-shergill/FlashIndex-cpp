# FlashIndex - In-Memory Search Engine

A fast and efficient search engine implementation using **Trie (Prefix Tree)** data structure in C++. This project demonstrates how Google's autocomplete-like features work under the hood!

## 🚀 What is this?

FlashIndex is an in-memory search engine that can store words and search them blazingly fast. Instead of searching through the entire list every time (which would be O(n)), we use a Trie data structure to get **O(L) time complexity** where L is just the length of the word!

Think of it like this - when you type "app" in Google search, it instantly shows "apple", "application", "approve" etc. That's basically what this does.

## 📚 What I Learned

This project helped me understand:

- **Trie Data Structure**: How prefix trees work and why they're so efficient for search operations
- **Memory Management in C++**: Using pointers, dynamic allocation, and proper cleanup with destructors
- **Hash Maps**: Using `unordered_map` for O(1) average lookups instead of arrays
- **Time Complexity Analysis**: Understanding why Trie operations are O(L) and not O(n)

## ✨ Features

- **Insert Words**: Add any word to the search engine
- **Search**: Check if an exact word exists (O(L) time)
- **Prefix Matching**: Find if any word starts with a given prefix (O(L) time)
- **Menu-Driven Interface**: Easy to use command-line interface
- **Memory Safe**: Proper destructor implementation to prevent memory leaks

## 🛠️ Technical Details

### Data Structure Used

- **Trie (Prefix Tree)** with `unordered_map<char, TrieNode*>` for storing children
- Each node stores a boolean flag to mark end of words
- Root node represents empty string

### Time Complexity

| Operation  | Time Complexity | Explanation                                      |
| ---------- | --------------- | ------------------------------------------------ |
| Insert     | O(L)            | L = length of word, we visit each character once |
| Search     | O(L)            | We traverse through each character of the word   |
| StartsWith | O(L)            | We traverse through each character of the prefix |

### Space Complexity

- O(ALPHABET_SIZE _ N _ L) in worst case
- Where N = number of words, L = average length of words

## 📁 Project Structure

```
FlashIndex-cpp/
│
├── Trie.h          # Header file with class declarations
├── Trie.cpp        # Implementation of Trie operations
├── main.cpp        # Menu-driven user interface
└── README.md       # You're reading this!
```

## 🔧 How to Compile and Run

### Requirements

- C++ compiler (g++, MinGW, or MSVC)
- C++14 or later

### Compilation

```bash
g++ -o FlashIndex main.cpp Trie.cpp -std=c++14
```

### Run

```bash
./FlashIndex          # On Linux/Mac
FlashIndex.exe        # On Windows
```

## 💡 Usage Example

```
========================================
   IN-MEMORY SEARCH ENGINE (TRIE)
========================================
1. Insert a word
2. Search for a word
3. Check if prefix exists
4. Exit
========================================
Enter your choice: 1

Enter word to insert: apple
✓ Word 'apple' inserted successfully!

Enter your choice: 2

Enter word to search: apple
✓ Word 'apple' FOUND in search engine!

Enter your choice: 3

Enter prefix to check: app
✓ Prefix 'app' EXISTS! Words starting with this prefix are present.
```

## 🎯 Future Improvements

I'm planning to add these features:

- [ ] Delete word functionality
- [ ] Display all words with a given prefix (autocomplete)
- [ ] Load words from a file
- [ ] Count total number of words
- [ ] Case-sensitive option

## 🤝 Why This Project?

I built this to understand how real search engines and autocomplete systems work. It's crazy to think that something as simple as a tree can make searches so fast! This also helped me prepare for coding interviews where Trie questions are pretty common.

## 📝 Note

This is a learning project I made during my 2nd year. The code follows standard practices and has detailed comments because I wanted to make sure I understand every part of it. If you find any bugs or have suggestions, feel free to let me know!

## 📜 License

MIT License - feel free to use this for learning purposes!

---

## 👨‍💻 Author

**Sukhman Singh**
B.Tech Computer Science (2nd Year)
*Passionate about Systems Engineering and Algorithms.*

---
Made with ☕ and C++ | 2025
