# InfraBlockchain.CDT (Contract Development Toolkit)

InfraBlockchain.CDT is a C/C++ toolchain targeting WebAssembly (WASM) and a set of tools to facilitate development of smart contracts written in C/C++ that are meant to be deployed to an [InfraBlockchain](https://github.com/InfraBlockchain/infrablockchain) blockchain.

In addition to being a general purpose WebAssembly toolchain, specific features and optimizations are available to support building InfraBlockchain-based smart contracts. This new toolchain is built around [Clang 9](https://github.com/AntelopeIO/cdt-llvm), which means that InfraBlockchain.CDT inherits the optimizations and analyses from that version of LLVM, but as the WASM target is still considered experimental, some optimizations are incomplete or not available.

## Upgrading

If you are upgrading to InfraBlockchain.CDT version 3.0 or later from version 1.8.1 (or earlier) of [EOSIO.CDT](https://github.com/EOSIO/eosio.cdt), then please read [EOSIO.CDT to CDT](./04_upgrading/eosio.cdt-to-cdt.md).

## License

[MIT](../LICENSE)
