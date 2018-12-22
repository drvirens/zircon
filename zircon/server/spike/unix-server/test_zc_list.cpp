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
  unsigned long len = LIST_len(ll);
  REQUIRE(len == 0);
  REQUIRE(ll != 0);
}

TEST_CASE("delete list", "[zc_list]") {
  zc_list_t *ll = LIST_alloc(&__zc_test_fw_free);
  REQUIRE(ll != 0);
  unsigned long len = LIST_len(ll);
  REQUIRE(len == 0);
  LIST_dealloc(ll);
}

TEST_CASE("last node in list", "[zc_list]") {
  zc_list_t *ll = LIST_alloc(&__zc_test_fw_free);
  REQUIRE(ll != 0);
  zc_node_t *tail = LIST_tail(ll);
  REQUIRE(tail == 0);
  unsigned long len = LIST_len(ll);
  REQUIRE(len == 0);
  LIST_dealloc(ll);
}

TEST_CASE("add one node in list", "[zc_list]") {
  zc_list_t *ll = LIST_alloc(&__zc_test_fw_free);
  REQUIRE(ll != 0);
  int data = 1;
  zc_list_t *own = LIST_push_back(ll, &data);
  REQUIRE(own == ll);
  unsigned long len = LIST_len(ll);
  REQUIRE(len == 1);
  zc_node_t *tail = LIST_tail(ll);
  REQUIRE(tail != 0);
  LIST_dealloc(ll);
}


TEST_CASE("add two nodes in list", "[zc_list]") {
  zc_list_t *ll = LIST_alloc(&__zc_test_fw_free);
  REQUIRE(ll != 0);
  int data = 1;
  zc_list_t *own = LIST_push_back(ll, &data);
  REQUIRE(own == ll);
  unsigned long len = LIST_len(ll);
  REQUIRE(len == 1);
  zc_node_t *tail = LIST_tail(ll);
  REQUIRE(tail != 0);
  
  int data_2 = 2;
  LIST_push_back(ll, &data_2);
  len = LIST_len(ll);
  REQUIRE(len == 2);
  
  tail = LIST_tail(ll);
  REQUIRE(tail != 0);
  
  LIST_dealloc(ll);
}

#include <netdb.h>
static int foo() {
  struct addrinfo *ai, hints;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
  
  const char* host = "www.google.com";
  const char* port = 0;
  const int gai_err = getaddrinfo(host, port, &hints, &ai);
  
  if (gai_err != 0) {
    printf("Server get address info failed with [%s]", gai_strerror(gai_err));
    return -1;
  }
  return 0;
}
TEST_CASE("foff", "netdb") {
  foo();
}
