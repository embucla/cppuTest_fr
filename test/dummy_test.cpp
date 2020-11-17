#include <string.h>
#include "CppUTest/TestHarness.h"

extern "C"{
    #include "cli.h"

}

static char output[100];
static const char * expected;

// create a test group
TEST_GROUP(dummy_test){
   
   void setup(){
       memset(output, 0xaa, sizeof output);
       expected = "";
   }

   void teardown(){

   }


};

static void expect(const char * s)
{
    expected = s;
}

static void given(long unsigned charsWritten)
{
    CHECK_EQUAL(strlen(expected), charsWritten);
    STRCMP_EQUAL(expected, output);
}


//create a test for that test group
TEST (dummy_test, pass_me){
    CHECK_EQUAL(1,1);
}

TEST (dummy_test, fail_me){
    CHECK_EQUAL(1,cli_init());
}

TEST(dummy_test, NoFormatOperations)
{
    CHECK_EQUAL(11, sprintf(output, "Hello %s", "World"));
    STRCMP_EQUAL("Hello World", output);
}

TEST(dummy_test , buffer_overrun){
    memset(output, 0xaa, sizeof output);

}


TEST(dummy_test, 1111 ){

    expect("hey");
}

TEST(dummy_test, InsertString)
{
    expect("Hello World\n");
    given(sprintf(output, "Hello %s\n", "World"));
}

