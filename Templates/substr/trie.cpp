#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

class Trie {
private:
	enum : short {
		N = 256,
	};
	const char base = '\0';

	struct node {
		int next[N];
		int freq;
		bool isEnd;
		node() : freq(0), isEnd(false) { 
			memset(next, -1, sizeof(next));
		}
	};
	vector<node> tree;
	
	auto idx(char c) -> int { return c - base; }

public:
	Trie() { tree.push_back(node()); }
	
	auto insert(const string& word) -> void {
		int p = 0;
		for (auto c: word) {
			tree[p].freq++;
			if (tree[p].next[idx(c)] == -1) {
				tree.push_back(node());
				tree[p].next[idx(c)] = tree.size() - 1;
			}
			p = tree[p].next[idx(c)];
		}
		tree[p].isEnd = true;
	}

	auto findStr(const string& word) -> bool {
		int p = 0;
		for (auto c: word) {
			p = tree[p].next[idx(c)];
			if (p == -1) return false;
		}
		return true;
	}
	
	auto findPrefix(const string& prefix) -> int {
		int p = 0;
		for (auto c: prefix) {
			p = tree[p].next[idx(c)];
			if (p == -1) return 0;
		}
		return tree[p].freq;
	}
};


int main(void) {
	Trie testTrie;

	testTrie.insert("Hello World!");
	testTrie.insert("Hello!");
	testTrie.insert("Hi!");
	testTrie.insert("Hollo");
	testTrie.insert("HHHH");

	if (testTrie.findStr("Hello!")) {
		cout << "Found!" << endl;
	} else {
		cout << "Not Found!" << endl;
	}

	cout << testTrie.findPrefix("H") << endl;

	return 0;
}
