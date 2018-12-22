//
//  test_zc_list.cpp
//  client
//
//  Created by Virendra Shakya on 12/21/18.
//

#include <catch2/catch.hpp>
#include "zc_list.h"

static void __zc_test_fw_free(void *ptr) {
  free(ptr);
}

TEST_CASE("create list", "[zc_list]") {
  zc_list_t *ll = LIST_alloc(&__zc_test_fw_free);
  REQUIRE(ll != 0);
}

TEST_CASE("delete list", "[zc_list]") {
  zc_list_t *ll = LIST_alloc(&__zc_test_fw_free);
  REQUIRE(ll != 0);
  LIST_dealloc(ll);
}

TEST_CASE("last node in list", "[zc_list]") {
  zc_list_t *ll = LIST_alloc(&__zc_test_fw_free);
  REQUIRE(ll != 0);
  zc_node_t *tail = LIST_tail(ll);
  REQUIRE(tail != 0);
  LIST_dealloc(ll);
}

TEST_CASE("add node in list", "[zc_list]") {
  zc_list_t *ll = LIST_alloc(&__zc_test_fw_free);
  REQUIRE(ll != 0);
  int data = 1;
  zc_list_t *own = LIST_push_back(ll, &data);
  REQUIRE(own == ll);
  unsigned long len = LIST_len(ll);
  REQUIRE(len == 1);
  LIST_dealloc(ll);
}

//TEST_CASE("create kist", "[zc_list]") {
//  zc_list_t *ll = LIST_alloc();
//  REQUIRE(ll != 0);
//}
//
//TEST_CASE("create kist", "[zc_list]") {
//  zc_list_t *ll = LIST_alloc();
//  REQUIRE(ll != 0);
//}
