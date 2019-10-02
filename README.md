[![Build Status](https://travis-ci.org/senior-sigan/WHY_CPP.svg?branch=master)](https://travis-ci.org/senior-sigan/WHY_CPP)

# About

**WHYCPP** is a simple, fantacy-console inspired, library to create pixel-art games.
The main idea behind WHYCPP is to have fun by coding entire game, 
without all these fancy features a typical framework offers.

# Featues

You can:

- create games in C++, C, JavaScript;
- draw EACH pixel on the screen manually;
- draw primitive shapes; 
- load and draw png textures;
- play wav sounds;
- handle keyboard and mouse;
- compile game into Web Page using emscripten.

# Requirements

## Windows

On Windows you can only develop using MSYS2 and MinGW.

When you have MSYS2 installed, run these commands to install necessary tools:

```shell script
pacman -S mingw-w64-x86_64-make mingw-w64-x86_64-cmake mingw-w64-x86_64-gcc mingw-w64-x86_64-pkg-config mingw-w64-x86_64-SDL2 mingw-w64-x86_64-SDL2_mixer
```

## Linux

For Debian-based Linux run these commands:

```shell script
sudo apt install cmake make g++ libsdl2-dev libsdl2-mixer-dev
```

## Mac OS

I suppose you have Homebrew installed.

Run these commands:

```shell script
brew install sdl2 sdl2_mixer
```

You may need to activate developer tools: `xcode-select --install`

# How to create game?

## For C++

1. Fork template project [WHY_CPP_template](https://github.com/senior-sigan/WHY_CPP_template)
2. Write your code in `src` dir. 
3. Just run `make` in the terminal to compile and run. Template is preconfigured to automatically download the latest release of WHYCPP.

Or

1. Fork this repository. 
2. Create a new dir, for example `game`, with content like we have for `example`
3. Add line to the `CMakeLists.txt`: `add_subdirectory(game)`.
4. If you need, you can add to the `Makefile` new tasks like `example-compile` and `example-run`