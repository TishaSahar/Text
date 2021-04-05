#include <gtest.h>
#include "TextAndGraph.h"

TEST(Node_tests, can_create_new_node) {
	string s = "some_string";
	ASSERT_NO_THROW(Node n(s));
}

TEST(Text_tests, can_create_test_obj) {
	ASSERT_NO_THROW(Text T);
}

TEST(Text_tests, test_print_text) {
	Text T;
	string s1 = "first";
	string s2 = "second";
	string s3 = "third";
	T.addLeft(s1); T.addRight(s2); T.addLeft(s3);
	ASSERT_NO_THROW(cout << T);
}

TEST(Text_test, remote_test) {
	Text T;
	string s1 = "first";
	string s2 = "second";
	string s3 = "third";
	T.addLeft(s1); T.addRight(s2); T.addLeft(s3);
	T.remote();
	EXPECT_EQ(T.getRoot(), NULL);
}