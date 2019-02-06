#ifndef _HUFFMAN_TREE_H_
#define _HUFFMAN_TREE_H_
#include <iostream>

class huffman_tree {
	public:
		huffman_tree();
		~huffman_tree();
		
		void build_tree(std::string filename);
		void print_frequencies(std::ostream &out);
		std::string encode(std::string filename);
		std::string decode(std::string filename);
};

#endif