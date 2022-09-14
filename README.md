# InfraBlockchain.CDT (Contract Development Toolkit)
## Version : 3.0.0

InfraBlockchain Contract Development Toolkit (InfraBlockchain.CDT) is a C/C++ toolchain targeting WebAssembly (WASM) and a set of tools to facilitate development of smart contracts written in C/C++ that are meant to be deployed to an [InfraBlockchain](https://github.com/infrablockchain/infrablockchain) blockchain.

In addition to being a general purpose WebAssembly toolchain, specific features and optimizations are available to support building Antelope-based smart contracts. This new toolchain is built around [Clang 9](https://github.com/AntelopeIO/cdt-llvm), which means that InfraBlockchain.CDT inherits the optimizations and analyses from that version of LLVM, but as the WASM target is still considered experimental, some optimizations are incomplete or not available.

## Binary packages

InfraBlockchain.CDT currently supports Linux x86_64 Debian packages. Visit the [release page](https://github.com/InfraBlockchain/infrablockchain.cdt/releases) to download the package for the appropriate version of InfraBlockchain.CDT. This is the fastest way to get started with the software.
### Debian package install

The latest version of InfraBlockchain.CDT is 3.0. Download the appropriate version of the Debian package and then install as follows:

```sh
wget https://github.com/InfraBlockchain/infrablockchain.cdt/releases/download/v3.0.0/cdt_3.0.0_amd64.deb
sudo apt install ./infrablockchain.cdt_3.0.0_amd64.deb
```
### Debian package uninstall

To remove InfraBlockchain.CDT that was installed using a Debian package, simply execute the following command:

```sh
sudo apt remove infrablockchain.cdt
```

## Building from source

Recent Ubuntu LTS releases are the only Linux distributions that we fully support. Other Linux distros and other POSIX operating systems (such as macOS) are tended to on a best-effort basis and may not be full featured. 

The instructions below assume that you are building on Ubuntu 20.04. 

### Install dependencies

```sh
apt-get update && apt-get install   \
        build-essential             \
        clang                       \
        cmake                       \
        git                         \
        libxml2-dev                 \
        opam ocaml-interp           \
        python3                     \
        python3-pip                 \
        time
```

```sh
python3 -m pip install pygments
```

### Allowing integration tests to build

Integration tests require access to a build of [InfraBlockchain](https://github.com/infrablockchain/infrablockchain), a C++ implementation of the Antelope protocol. Simply installing InfraBlockchain from a binary package will not be sufficient.

If you do not wish to build InfraBlockchain, you can continue with building InfraBlockchain.CDT but without building the integration tests. Otherwise, follow the instructions below before running `cmake`.

First, ensure that InfraBlockchain has been built from source (see InfraBlockchain's [README](https://github.com/infrablockchain/infrablockchain#building-from-source) for details) and identify the build path, e.g. `/path/to/infrablockchain/build/`.

Then, execute the following command in the same terminal session that you will use to build InfraBlockchain.CDT:

```sh
export infrablockchain_DIR=/path/to/infrablockchain/build/lib/cmake/infrablockchain
```

Now you can continue with the steps to build InfraBlockchain.CDT as described. When you run `cmake` make sure that it does not report `infrablockchain package not found`. If it does, this means InfraBlockchain.CDT was not able to find a build of Leap at the specified path in `infrablockchain_DIR` and will therefore continue without building the integration tests.

### ccache

If issues persist with ccache when building InfraBlockchain.CDT, you can disable ccache:

```sh
export CCACHE_DISABLE=1
```

### Build InfraBlockchain.CDT

**A Warning On Parallel Compilation Jobs (`-j` flag)**: When building C/C++ software often the build is performed in parallel via a command such as `make -j $(nproc)` which uses the number of CPU cores as the number of compilation jobs to perform simultaneously. However, be aware that some compilation units (.cpp files) in InfraBlockchain.CDT are extremely complex and can consume a large amount of memory to compile. If you are running into issues due to amount of memory available on your build host, you may need to reduce the level of parallelization used for the build. For example, instead of `make -j $(nproc)` you can try `make -j2`. Failures due to memory exhaustion will typically but not always manifest as compiler crashes.

```sh
git clone --recursive https://github.com/InfraBlockchain/infrablockchain.cdt
cd infrablockchain.cdt
mkdir build
cd build
cmake ..
make -j $(nproc)
```

The binaries will be located at in the `build/bin` directory. You can export the path to the directory to your `PATH` environment variable which allows you to conveniently use them to compile contracts without installing CDT globally. Alternatively, you can use CMake toolchain file located in `build/lib/cmake/InfraBlockchainWasmToolchain.cmake` to compile the contracts in your CMake project, which also allows you to avoid installing InfraBlockchain.CDT globally.

If you would prefer to install InfraBlockchain.CDT globally, see the section [Install InfraBlockchain.CDT](#install-infrablockchain-cdt) below.

### Run tests

#### Run unit tests

```sh
cd build

ctest
```

#### Run integration tests (if built)

```sh
cd build/tests/integration

ctest
```

### Install InfraBlockchain.CDT

Installing InfraBlockchain.CDT globally on your system will install the following tools in a location accessible to your `PATH`:

* infrablockchain-abidiff
* infrablockchain-ar
* infrablockchain-cc
* infrablockchain-cpp
* infrablockchain-init
* infrablockchain-ld
* infrablockchain-nm
* infrablockchain-objcopy
* infrablockchain-objdump
* infrablockchain-ranlib
* infrablockchain-readelf
* infrablockchain-strip
* infrablockchain-pp
* infrablockchain-wasm2wast
* infrablockchain-wast2wasm 

It will also install CMake files for InfraBlockchain.CDT accessible within a `cmake/infrablockchain` directory located within your system's `lib` directory.
#### Manual installation

One option for installing InfraBlockchain.CDT globally is via `make install`. From within the `build` directory, run the following command:

```
sudo make install
```

#### Package installation

A better option for installing InfraBlockchain.CDT globally is to generate a package and then install the package. This makes uninstalling CDT much easier.

From within the `build` directory, run the following commands to generate a Debian package:

```sh
cd packages
bash ./generate_package.sh deb ubuntu-20.04 amd64
sudo apt install ./infrablockchain.cdt_*_amd64.deb
```

### Uninstall InfraBlockchain.CDT

#### Uninstall InfraBlockchain.CDT after manual installation with make

```sh
sudo rm -fr /usr/local/infrablockchain
sudo rm -fr /usr/local/lib/cmake/infrablockchain
sudo rm /usr/local/bin/infrablockchain-*
```

#### Uninstall InfraBlockchain.CDT that was installed using a Debian package

```sh
sudo apt remove infrablockchain.cdt
```

## License

[MIT](./LICENSE)