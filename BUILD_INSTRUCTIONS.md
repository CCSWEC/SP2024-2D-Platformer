# Build instructions for 2D Platformer

This project uses CMake, a C/C++ build system. It allows us to use any supported operating system and C++ compiler on the same codebase.

If you have any problems while following these instructions, feel free to shoot us a message in the Discord! 
The subpoints in these instructions are for Windows and MacOS. If you're on Linux, you likely know what you're doing -- use your package manager to install packages as required.


## Installation
1. Download [VSCode](https://code.visualstudio.com/download) and run it.
   - You *could* use a C++ editor of your choice; ideally one with CMake integrations. We'll support VSCode.
2. Download [CMake](https://cmake.org/download/)
   - To test that it's installed, run `cmake --version` in the terminal.
     - In VSCode, a terminal should already be open at the bottom. If not, hit Ctrl + ` (the little key under Esc) to open one.
     - Type in the command. If you get some output that's *not* "command not found", you're good!
3. Install the CMake extension for VSCode.
   - Go to the extensions menu: it's in the little squares on the left side of the screen, as shown below.
   - Search for "CMake Tools" and install the extension.![where the extension button is](images\extensions_button_in_vscode.png)
4. Ensure you have a C++ compiler installed.
   - `g++` is recommended and supported, but thanks to CMake, you should be able to use `clang` which is often installed by default on MacOS.
     - To check for `clang`, open a terminal and run `clang --version`. If it fails, run `xcode-select --install`.
   - To install `g++`, you can get one from [MinGW](https://sourceforge.net/projects/mingw/).
     - In the installer, make sure to check the boxes for `mingw32-base`, `mingw32-gcc-g++`, and `msys-base`.

## To run and debug the code:
1. Run "CMake: Scan for Kits".
   - To open the VSCode Command Palette, use Ctrl+Shift+P. Then type in "cmake scan" (like a search bar!) and hit enter.
   - It should locate the g++ install from earlier. It may not detect it if it wasn't added to your PATH.
     - // TODO: add notes about PATH?
2. Run "CMake: Select a Kit".
3. **Use "CMake: Debug" to run and debug the code.**
   - This will use VSCode's debugger. You can set breakpoints, pause the code, watch variable values, and more.
   - You can use "CMake: Run Without Debugging" or "CMake: Build" instead -- running without the debugger may have some more realistic performance, and just building won't immediately auto-run the output right after compiling.