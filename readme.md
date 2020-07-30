<h1 align = 'center'>Chirp</h1>

<div align = 'center'>
  <strong>Chirp is a modern low-level programming language</strong>
</div>

<br><br><br>

<p align = 'center'>
  <img src = 'https://camo.githubusercontent.com/641f171b8217bb22d5951086a25c7c7a037a106c/68747470733a2f2f63646e2e646973636f72646170702e636f6d2f6174746163686d656e74732f3530363135323839363631383935343831322f3538323035313338303737373435313534312f4368697270536d616c6c49636f6e2e706e67'>
</p>

<br>

# What's this

Currently, this repository is hosting the source code for an *experimental* compiler, that only targets C. The goal is to write a compiler in chirp using the one we have right now. If you are looking to contribute, improvements to the user experience would greatly be appreciated.

# Building

## Unix

These are the dependencies required to build Chirp on Unix-like systems:
* `g++` 5.5 or later
* GNU `make`
* `nasm`

```sh
# Creates the bin directory
$ make setup

# Compiles the code
$ make

# You can use chirp now!
$ ./chirp 
```

## Windows

Currently there's no official way to build on windows, contribution would be greatly apreciated.
