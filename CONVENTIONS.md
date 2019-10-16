# Ledger Core coding and hacking style conventions

Here are the list of conventions we make our best to follow throughout the code we write. If you
find some code that doesn’t respect this current document, please open a PR to fix the formatting
and/or style.

If you want to modify our convention, please open an issue modifying that file by adding new items
in the lists below.

## C++

- _Date created: 2019/09/03._
- _Date modified: 2019/09/03._

1. We indent with 4 spaces and don’t use tabs.
2. Even if our legacy code contains some, we try not to use [include guard] anymore. Please
  use `#pragma once` instead.
3. Most of our code lives in, at least, the `ledger::core` namespace. We declare both
  namespaces as `namespace ledger { namespace core {`.
4. Every file must start with the _license header_. Please use this one:
  ```
  /*
   *
   * <name>
   * ledger-core
   *
   * Created by <Your Name Here> on YYYY/MM/DD.
   *
   * The MIT License (MIT)
   *
   * Copyright (c) YYYY Ledger
   *
   * Permission is hereby granted, free of charge, to any person obtaining a copy
   * of this software and associated documentation files (the "Software"), to deal
   * in the Software without restriction, including without limitation the rights
   * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   * copies of the Software, and to permit persons to whom the Software is
   * furnished to do so, subject to the following conditions:
   *
   * The above copyright notice and this permission notice shall be included in all
   * copies or substantial portions of the Software.
   *
   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   * SOFTWARE.
   *
   */
  ```
5. Functions signatures with many arguments or long arguments (making the function signature
  longer than 100 characters) are spread on several lines. We break the line after the `(` and
  each line receives an argument (type + variable name + comma) with one level more of
  indentation. The last argument is alone on its line and the very next line only contains `) {`,
  reindented at the same level as the function signature. Example:
  ```cpp
  void foo(
    int x,
    char y,
    std::string const& z
  ) {
    // …
  }
  ```
6. For constructors, (5.) rule applies too but the initialization list is treated separately. It
  immediately follows the ending `)` of the arguments list and starts a new indent block. The
  rule remains the same for the members (one on each line with the comma) and the last member gets
  `{`. Example:
  ```cpp
  class Foo {
    int _x;
    char _y;
    std::string _z;

  public:
    Foo(
      int x,
      char y,
      std::string const& z
    ): _x(x),
       _y(y),
       _z(z) {
    }
  };
  ```
7. `#include` statements must be sorted (lexical sort) and always prefers absolute path than relative.
  The header name follows PascalCase convention.
 
8. Try as much as possible to document all **public symbols** you add. Private symbols just at
  least contain some comments about they are about. Exception made for public implementations:
  you don’t have to copy the documentation that is already present on the interface.

10. Each header file must contain at maximum one class/struct definition except for nested ones.

[include guard]: https://en.wikipedia.org/wiki/Include_guard
