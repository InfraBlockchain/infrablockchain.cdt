---
content_title: infrablockchain-abidiff tool
---

The infrablockchain-abidiff tool is used to diff two ABI files to flag and output differences.
To report differences with ```infrablockchain-abidiff```, you only need to pass the two ABI file names as command line arguments.

Example:
```bash
$ infrablockchain-abidiff hello.abi old_hello.abi
```

This will generate dump the report output to the console.
```
OVERVIEW: infrablockchain-abidiff
USAGE: infrablockchain-abidiff [options] <input file1> ... <input file2> ...

OPTIONS:

Generic Options:

  -help      - Display available options (-help-hidden for more)
  -help-list - Display list of available options (-help-list-hidden for more)
  -version   - Display the version of this program
```
