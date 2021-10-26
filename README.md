# InfraBlockchain.CDT (Contract Development Toolkit)
## Version : 2.0.0

InfraBlockchain.CDT is a toolchain for WebAssembly (WASM) and a set of tools to facilitate smart contract development for the InfraBlockchain platform. In addition to being a general purpose WebAssembly toolchain, [InfraBlockchain](https://github.com/InfraBlockchain/infrablockchain) specific optimizations are available to support building InfraBlockchain smart contracts.  This new toolchain is built around [Clang 9](https://github.com/eosio/llvm), which means that InfraBlockchain.CDT has the most currently available optimizations and analyses from LLVM, but as the WASM target is still considered experimental, some optimizations are incomplete or not available.

### New Introductions
As of this release two new repositories are under the suite of tools provided by **InfraBlockchain.CDT**.  These are the [Ricardian Template Toolkit](https://github.com/eosio/ricardian-template-toolkit) and the [Ricardian Specification](https://github.com/eosio/ricardian-spec).  The **Ricardian Template Toolkit** is a set of libraries to facilitate smart contract writers in crafting their Ricardian contracts.  The Ricardian specification is the working specification for the above mentioned toolkit.  Please note that both projects are **alpha** releases and are subject to change.

### Attention
- There is currently a known issue that a minimum of 2 CPU cores is required for using InfraBlockchain.CDT

## Binary Releases
InfraBlockchain.CDT currently supports Mac OS X brew, Linux x86_64 Debian packages, and Linux x86_64 RPM packages.

**If you have previously installed InfraBlockchain.CDT, run the `uninstall` script (it is in the directory where you cloned InfraBlockchain.CDT) before downloading and using the binary releases.**

### Mac OS X Brew Install
```sh
brew tap infrablockchain/infrablockchain.cdt
brew install infrablockchain.cdt
```

### Mac OS X Brew Uninstall
```sh
brew remove infrablockchain.cdt
```

### Debian Package Install
```sh
wget https://github.com/InfraBlockchain/infrablockchain.cdt/releases/download/v2.0.0/infrablockchain.cdt_2.0.0-1-ubuntu-18.04_amd64.deb
sudo apt install ./infrablockchain.cdt_2.0.0-1-ubuntu-18.04_amd64.deb
```

### Debian Package Uninstall
```sh
sudo apt remove infrablockchain.cdt
```

### RPM Package Install
```sh
wget https://github.com/InfraBlockchain/infrablockchain.cdt/releases/download/v2.0.0/infrablockchain.cdt-2.0.0-1.el7.x86_64.rpm
sudo yum install ./infrablockchain.cdt-2.0.0-1.el7.x86_64.rpm
```

### RPM Package Uninstall
```sh
sudo yum remove infrablockchain.cdt
```

## Guided Installation or Building from Scratch
```sh
git clone --recursive https://github.com/InfraBlockchain/infrablockchain.cdt
cd infrablockchain.cdt
mkdir build
cd build
cmake ..
make -j8
```

From here onward you can build your contracts code by simply exporting the `build` directory to your path, so you don't have to install globally (makes things cleaner).
Or you can install globally by running this command:

```sh
sudo make install
```

### Uninstall after manual installation

```sh
sudo rm -fr /usr/local/infrablockchain.cdt
sudo rm -fr /usr/local/lib/cmake/infrablockchain.cdt
sudo rm /usr/local/bin/infrablockchain-*
```

## Installed Tools
---
* infrablockchain-cpp
* infrablockchain-cc
* infrablockchain-ld
* infrablockchain-init
* infrablockchain-abidiff
* infrablockchain-wasm2wast
* infrablockchain-wast2wasm
* infrablockchain-ranlib
* infrablockchain-ar
* infrablockchain-objdump
* infrablockchain-readelf

## Contributing

[Contributing Guide](./CONTRIBUTING.md)

[Code of Conduct](./CONTRIBUTING.md#conduct)

## License

[MIT](./LICENSE)

## Important

See [LICENSE](./LICENSE) for copyright and license terms.

All repositories and other materials are provided subject to the terms of this [IMPORTANT](./IMPORTANT.md) notice and you must familiarize yourself with its terms.  The notice contains important information, limitations and restrictions relating to our software, publications, trademarks, third-party resources, and forward-looking statements.  By accessing any of our repositories and other materials, you accept and agree to the terms of the notice.
