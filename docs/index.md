# InfraBlockchain.CDT (Contract Development Toolkit)

InfraBlockchain.CDT is a toolchain for WebAssembly (WASM) and set of tools to facilitate smart contract development for the InfraBlockchain platform. In addition to being a general purpose WebAssembly toolchain, [InfraBlockchain](https://github.com/InfraBlockchain/infrablockchain) specific optimizations are available to support building InfraBlockchain smart contracts.  This new toolchain is built around [Clang 7](https://github.com/eosio/llvm), which means that InfraBlockchain.CDT has the most currently available optimizations and analyses from LLVM, but as the WASM target is still considered experimental, some optimizations are incomplete or not available.

## New Introductions

As of this release two new repositories are under the suite of tools provided by **InfraBlockchain.CDT**.  These are the [Ricardian Template Toolkit](https://github.com/eosio/ricardian-template-toolkit) and the [Ricardian Specification](https://github.com/eosio/ricardian-spec). The **Ricardian Template Toolkit** is a set of libraries to facilitate smart contract writers in crafting their Ricardian contracts.  The Ricardian specification is the working specification for the above mentioned toolkit.  Please note that both projects are **alpha** releases and are subject to change.


