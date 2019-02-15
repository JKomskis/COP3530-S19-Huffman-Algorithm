#include <fstream>
#include "catch.hpp"
#include "huffman_tree.h"

std::string file_as_string(std::string file){
    std::ifstream in(file);
    std::string string((std::istreambuf_iterator<char>(in)),
                 std::istreambuf_iterator<char>());
    return string;
}

TEST_CASE("Test case on file.txt") {
    const std::string file_to_test = "texts/iliad_1.txt";
    huffman_tree tree(file_to_test);

    std::string encoded_file_string = tree.encode(file_to_test);    
    CHECK( tree.decode(encoded_file_string) == file_as_string(file_to_test));
}

TEST_CASE("Balanced Tree") {
    huffman_tree tree("texts/balanced_alphabet.txt");

    SECTION("Verify Huffman Code") {
        std::string encoded_string = tree.encode("texts/balanced_alphabet.txt");
        CHECK(encoded_string.length() == 130);
    }

    SECTION("Encode/Decode") {
        std::string file_name = GENERATE(as<std::string>{}, "texts/balanced_alphabet.txt",
                                                            "texts/unbalanced_alphabet.txt");
        std::string encoded_string = tree.encode(file_name);
        CHECK( tree.decode(encoded_string) == file_as_string(file_name) );
    }
}

TEST_CASE("Tall Tree") {
    huffman_tree tree("texts/unbalanced_alphabet.txt");

    SECTION("Verify Huffman Code") {
        std::string encoded_string = tree.encode("texts/unbalanced_alphabet.txt");
        CHECK(encoded_string.length() == 2035);
    }

    SECTION("Encode/Decode") {
        std::string file_name = GENERATE(as<std::string>{}, "texts/unbalanced_alphabet.txt");
        std::string encoded_string = tree.encode(file_name);
        CHECK( tree.decode(encoded_string) == file_as_string(file_name) );
    }
}

TEST_CASE("All ASCII Values") {
    huffman_tree tree("texts/all_ascii.txt");

    SECTION("Verify Huffman Code") {
        std::string encoded_string = tree.encode("texts/all_ascii.txt");
        CHECK(encoded_string.length() == 896);
    }

    SECTION("Encode/Decode") {
        std::string file_name = GENERATE(as<std::string>{}, "texts/all_ascii.txt",
                                                            "texts/balanced_alphabet.txt",
                                                            "texts/iliad_1.txt",
                                                            "texts/litany.txt",
                                                            "texts/unbalanced_alphabet.txt");
        std::string encoded_string = tree.encode(file_name);
        CHECK( tree.decode(encoded_string) == file_as_string(file_name) );
    }
}