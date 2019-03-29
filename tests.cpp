#include <fstream>
#include "catch.hpp"
#include "huffman_tree.h"

std::string file_as_string(std::string file){
    std::ifstream in(file);
    std::string string((std::istreambuf_iterator<char>(in)),
                 std::istreambuf_iterator<char>());
    return string;
}

void test_encode_decode(const huffman_tree &tree, const std::vector<std::string> &files_to_test) {
    for(std::string file_name: files_to_test) {
        std::string encoded_string = tree.encode(file_name);

        bool valid_chars = true;
        for(char c: encoded_string) {
            valid_chars &= (c == '0') || (c == '1');
        }
        CHECK(valid_chars);
        CHECK(tree.decode(encoded_string) == file_as_string(file_name));
    }
}

TEST_CASE("Iliad") {
    huffman_tree tree("texts/iliad_1.txt");

    SECTION("Encode/Decode") {
        std::vector<std::string> files_to_test = {"texts/iliad_1.txt",
                                                    "balanced_alphabet.txt",
                                                    "texts/litany.txt",
                                                    "texts/mississippi.txt"
                                                    "texts/single_letter.txt",
                                                    "unbalanced_alphabet.txt"};
        test_encode_decode(tree, files_to_test);
    }
}

TEST_CASE("Balanced Tree") {
    huffman_tree tree("texts/balanced_alphabet.txt");

    SECTION("Verify Huffman Code Length") {
        std::string encoded_string = tree.encode("texts/balanced_alphabet.txt");
        CHECK(encoded_string.length() == 130);
    }

    SECTION("Encode/Decode") {
        std::vector<std::string> files_to_test = {"texts/balanced_alphabet.txt",
                                                    "texts/unbalanced_alphabet.txt"};
        test_encode_decode(tree, files_to_test);
    }
}

TEST_CASE("Tall Tree") {
    huffman_tree tree("texts/unbalanced_alphabet.txt");

    SECTION("Verify Huffman Code Length") {
        std::string encoded_string = tree.encode("texts/unbalanced_alphabet.txt");
        CHECK(encoded_string.length() == 2035);
    }

    SECTION("Verify Character Code Lengths") {
        // for this tree, a and b should have a code length of 9
        // after that, each consecutive letter's code length should
        // decrease by 1 until we get to j, which has a code length of 1
        CHECK(tree.get_character_code('a').length() == 9);
        for(char c = 'b'; c <= 'j'; ++c) {
            CHECK(tree.get_character_code(c).length() == 9 - (c - 'b'));
        }
    }

    SECTION("Encode/Decode") {
        std::vector<std::string> files_to_test = {"texts/unbalanced_alphabet.txt"};
        test_encode_decode(tree, files_to_test);
    }
}

TEST_CASE("All ASCII Values") {
    huffman_tree tree("texts/all_ascii.txt");

    SECTION("Verify Huffman Code Length") {
        std::string encoded_string = tree.encode("texts/all_ascii.txt");
        // every code has a length of 7, except for 1, which has a length of 6
        // so the total length is 126 * 7 + 6 = 888
        CHECK(encoded_string.length() == 888);
    }

    SECTION("Encode/Decode") {
        std::vector<std::string> files_to_test = {"texts/all_ascii.txt",
                                                    "texts/balanced_alphabet.txt",
                                                    "texts/iliad_1.txt",
                                                    "texts/litany.txt",
                                                    "texts/unbalanced_alphabet.txt"};
        test_encode_decode(tree, files_to_test);
    }
}

TEST_CASE("Single Letter") {
  huffman_tree tree("texts/single_letter.txt");

  SECTION("Verify Huffman Code Length") {
      std::string encoded_string = tree.encode("texts/single_letter.txt");
      CHECK(encoded_string.length() == 1);
  }

  SECTION("Encode/Decode") {
      std::vector<std::string> files_to_test = {"texts/single_letter.txt"};
      test_encode_decode(tree, files_to_test);
  }
}

TEST_CASE("Encoding Mississippi") {
  huffman_tree tree("texts/mississippi.txt");

  SECTION("Verify Huffman Code Length") {
      std::string encoded_string = tree.encode("texts/mississippi.txt");
      CHECK(encoded_string.length() == 21);
  }

  SECTION("Encode/Decode") {
      std::vector<std::string> files_to_test = {"texts/mississippi.txt"};
      test_encode_decode(tree, files_to_test);
  }
}

TEST_CASE("Invalid Encode/Decode") {
    huffman_tree tree("texts/balanced_alphabet.txt");

        CHECK(tree.encode("texts/doesnt_exist.txt") == "");
        CHECK(tree.encode("texts/all_ascii.txt") == "");
        CHECK(tree.encode("texts/iliad_1.txt") == "");
        CHECK(tree.encode("texts/litany.txt") == "");
        CHECK(tree.decode("") == "");
        CHECK(tree.decode("WAIT_NO_DON'T") == "");
}
