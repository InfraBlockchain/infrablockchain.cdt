---
content_title: How to compile a smart contract via CLI
---

## Overview

This guide provides instructions how to compile a smart contract using the command line interface (CLI).

## Reference

See the following code reference:

* The [`infrablockchain-cpp`](https://developers.infrablockchain.com/manuals/infrablockchain.cdt/v2.0/command-reference/infrablockchain-cpp) tool.

## Before you begin

* You have the source of the contract saved in a local folder, e.g. `./examples/hello/`
For details on how to create your first contract follow the [Hello World Contract](https://developers.infrablockchain.com/welcome/latest/smart-contract-guides/hello-world) guide.

## Procedure

Follow the following steps to compile your contract.

1. Navigate to the hello folder in examples `./examples/hello`. You should see the `./src/hello.cpp` file.

2. Run the following commands:

    ```sh
    mkdir build
    cd build
    infrablockchain-cpp -abigen ../src/hello.cpp -o hello.wasm -I ../include/
    ```

    Where:
    - `infrablockchain-cpp` = Is the [`infrablockchain-cpp`](https://developers.infrablockchain.com/manuals/infrablockchain.cdt/v2.0/command-reference/infrablockchain-cpp) tool.
    - `-abigen` = It instructs the `infrablockchain-cpp` tool to generate ABI file.
    - `../src/hello.cpp` = Is the input cpp source file to be compiled.
    - `-o hello.wasm` = It instructs the `infrablockchain-cpp` tool who to name the output wasm file.
    - `-I ../include/` = It tells `infrablockchain-cpp` tool what the include folder path is, in this particular case it is a relative path.

3. Verify the following two files were generated:

* the compiled binary wasm: `hello.wasm`,
* and the generated ABI file: `hello.abi`.

## Summary

In conclusion, the above instructions show how to compile a smart contract using the command line interface (CLI).
