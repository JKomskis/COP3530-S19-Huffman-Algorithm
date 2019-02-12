#ifndef _HUFFMAN_TREE_H_
#define _HUFFMAN_TREE_H_

class huffman_tree {
	public:
		huffman_tree(std::string file_name);
		~huffman_tree();
		
		std::string get_character_code(char character);
		std::string encode(std::string filename);
		std::string decode(std::string string_to_decode);		
};
#endif