CLion example project for STM32H745 MCU and NUCLEO-H745ZI-Q board
====
Example project for [STM32H745 Nucleo-144](https://www.st.com/en/evaluation-tools/nucleo-h755zi-q.html) board.
Only CM7 is actually used.

**This example is specially made for multi-core MCUs, like some of STM32H7xx chips**

**Single-core STM32 MCUs are [supported out-of-the-box](https://www.jetbrains.com/help/clion/embedded-development.html)**



Tools required
====
* [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) and STM32H7 software pack
* [CLion 2022.2+](https://www.jetbrains.com/clion/) and it's bundled `Embedded Development Support` plugin
* [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)
* [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
* (Windows only) [MinGW](https://sourceforge.net/projects/mingw-w64/files/mingw-w64/mingw-w64-release/)

Steps to make a similar project
====
1. Install and configure all the required tools. See [CLion Quick start guide](https://www.jetbrains.com/help/clion/clion-quick-start-guide.html)
2. Start STM32CubeMX and make a new project.
    * **Note I. On the `Project Manager` tab, `Toolchain/IDE` field must be set to `STM32CubeIDE`**
    * **Note II. Do not use space, international, or special characters for project name or path**
3. Generate the project code. STM32CubeMX will create a project folder with two separate subprojects
4. Download and put [CMakeLists.txt for this gist](https://gist.github.com/elmot/c48f756c5443c4a003978db94392e00d) to the projects root
5. Now check all the `TODO` comments in the `CMakeLists.txt` file and put actual values instead.
   [TODO tool window](https://www.jetbrains.com/help/clion/todo-tool-window.html)
6. Open the root project in [CLion](https://www.jetbrains.com/help/clion/opening-reopening-and-closing-projects.html).
7. Your CMake project will be parsed. If there are errors, correct them and select `Tools -> CMake -> Reset Cache and Reload Prpject` from the main menu.
   Repeat until everything is fixed and the CMakeLists is successfully parsed.
8. Create `Run Configurations` for both core binaries - CM4 and CM7. 
    1. Select create new [Embedded GDB Server](https://www.jetbrains.com/help/clion/embedded-gdb-server.html) run configuration.
    2. Select `Target` and `Executable`for correaponding core.
    4. Set `tcp::<port number>` to `'target remote' args` field.
       The port number may be virtually any in range 1024..65535 but it must nt clash with the conterpart project port number.
       Use the same number below
    5. Locate `ST-LINK_gdbserver` executable and select for as `GDB server`
       The executable resides in the in `STM32CubeIDE` installation folder,
       `plugins/com.st.stm32cube.ide.mcu.externaltools.stlink-gdb-server.????/tools/bin/` subfolder.
       Actual name varies from version to version, and exact name can't be provided
    6. Locate `STM32_Programmer_CLI` executable similar way, but the folder expected to be
       `plugins/com.st.stm32cube.ide.mcu.externaltools.cubeprogrammer.???/tools/bin/` then add
       *path to the folder* as a `-cp` key value to `GDB Server args` field
    7. Add `-t -d -p <port number> -m <core num>` keys to `GDB Server args` field.
        * The `<core num>` parameter is `0` for Cortex-M7 or `3` for Cortex-M4 kernels. Other MCU models may support other numbers.
        * Final arguments form is `-cp <STM32_Programmer_CLI bin folder path> -t -d -p <port number> -m <core num>`
9. Try to build both executables. If something goes wrong, fix your `CMakeLists.txt` and sources.
10. Click `Debug` for both executables. The firmware for both kernels should be flashed and started.
11. Enjoy your newly-created project.
