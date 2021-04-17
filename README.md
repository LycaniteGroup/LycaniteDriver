# LycaniteDriver
Kernel mode driver for Lycanite.

___

### Add tests to LycaniteDriver

In the folder `tests/`:
- Write the tests using [GoogleTest](https://google.github.io/googletest/primer.html), here is an example :
```cpp
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(SampleTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("Sample", "test");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}
```

 - In `CMakeLists.txt` add an executable for your test file :
```cmake
add_executable(
  sample_test
  tests/sample_test.cc
)
```

 - In `CMakeLists.txt` link the GoogleTest library to the test binary :
```cmake
target_link_libraries(
  sample_test
  gtest_main
)
```

 - In `CMakeLists.txt` use the `gtest_discover_tests` command for your binary:
```cmake
gtest_discover_tests(sample_test)
```

___

### Execute the LycaniteDriver tests :

In the project root folder execute those commands:

```sh
cmake -S . -B build

cmake --build build

cd build && ctest
```

___
