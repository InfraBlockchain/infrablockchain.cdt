---
content_title: infrablockchain-init tool
---

This tool is used to generate a skeleton smart contract and directory structure.
To generate a new smart contract project you can either generate a "bare" project (no CMake) or the default is to generate a CMake project.

Example:
```bash
$ infrablockchain-init --path=\destination\path\where\to\generate\project\ --project=hello_contract_folder
```

This will generate a project folder `hello_contract_folder` in the path `\destination\path\where\to\generate\project\` containing the skeleton smart contract and directory structure.

```
USAGE: infrablockchain-init [options]

OPTIONS:

Generic Options:

  -help             - Display available options (-help-hidden for more)
  -help-list        - Display list of available options (-help-list-hidden for more)
  -version          - Display the version of this program

infrablockchain-init:
generates an InfraBlockchain smart contract project

  -bare             - produces only a skeleton smart contract without CMake support
  -path=<string>    - directory to place the project
  -project=<string> - output project name
```
