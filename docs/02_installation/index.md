---
content_title: Binary Releases
---

InfraBlockchain.CDT currently supports Mac OS X brew, Linux x86_64 Debian packages, and Linux x86_64 RPM packages.

**If you have previously installed InfraBlockchain.CDT, run the `uninstall` script (it is in the directory where you cloned InfraBlockchain.CDT) before downloading and using the binary releases.**

## Mac OS X Brew Install

```sh
brew tap infrablockchain/infrablockchain.cdt
brew install infrablockchain.cdt
```

## Mac OS X Brew Uninstall

```sh
brew remove infrablockchain.cdt
```

## Debian Package Install

```sh
wget https://github.com/InfraBlockchain/infrablockchain.cdt/releases/download/v2.0.0/infrablockchain.cdt_2.0.0-ubuntu-18.04_amd64.deb
sudo apt install ./infrablockchain.cdt_2.0.0-ubuntu-18.04_amd64.deb
```

## Debian Package Uninstall

```sh
sudo apt remove infrablockchain.cdt
```

## RPM Package Install

```sh
wget https://github.com/InfraBlockchain/infrablockchain.cdt/releases/download/v2.0.0/infrablockchain.cdt-1.8.1.el7.x86_64.rpm
sudo yum install ./infrablockchain.cdt-2.0.0.el7.x86_64.rpm
```

## RPM Package Uninstall

```sh
sudo yum remove infrablockchain.cdt
```

# Guided Installation or Building from Scratch

```sh
git clone --recursive https://github.com/InfraBlockchain/infrablockchain.cdt
cd infrablockchain.cdt
mkdir build
cd build
cmake ..
make -j8
```

From here onward you can build your contracts code by simply exporting the `build` directory to your path, so you don't have to install globally (makes things cleaner).
Or you can install globally by running this command

```sh
sudo make install
```

## Uninstall after manual installation

```sh
sudo rm -fr /usr/local/infrablockchain.cdt
sudo rm -fr /usr/local/lib/cmake/infrablockchain.cdt
sudo rm /usr/local/bin/infrablockchain-*
```

# Installed Tools

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

The following tools are not installed after brew install, you get them when you build the repository and install it from scratch, [see here](#guided-installation-or-building-from-scratch):

* infrablockchain-abidiff
* infrablockchain-ranlib
* infrablockchain-ar
* infrablockchain-objdump
* infrablockchain-readelf

License
[MIT](../LICENSE)
