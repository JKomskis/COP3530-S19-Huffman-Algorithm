#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "huffman_tree.h"

TEST_CASE("Test case on file.txt"){
    const std::string file_to_test = "file.txt";
    const char char_to_test = ' ';

    huffman_tree tree(file_to_test);

    //REQUIRE( tree.get_character_code(char_to_test) == "00" );

    //std::string encoded_file_string = tree.encode(file_to_test);
    REQUIRE(test_encode(encoded_file_string, &tree, file_to_test));
    
    REQUIRE( tree.decode(encoded_file_string) == file_as_string(file_to_test));
}