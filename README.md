# C++ Data Structures

# nix

`flake.nix` defines the development environment. To regenerate `flake.lock`, run `nix flake update`. To activate the development environment, run `nix develop`.

# CMake

`cmake` is a meta build system for C++. It makes it so you don't have to manually add all the filepaths of your source files manually to a `g++` command. It is very necessary for C++ projects larger than a single source file.

# Makefile

The Makefile contains recipes that wrap CMake invocations to organize all the commands used when working with this project.
