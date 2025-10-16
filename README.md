# PyTha++

A simple C++ console application that computes the third side of a right triangle using the Pythagorean theorem. It includes robust input validation and colored console output.

Build
- CMake project targeting C++14.
- Primary target: Test (executable).
- CLion profile: Debug (MinGW toolchain).

Distribution and running on another computer
- The produced executable (PyTha++.exe) is Windows-only.
- When built with MinGW, this project links libgcc and libstdc++ statically so the exe is more self-contained and typically does not require MinGW runtime DLLs on another Windows 10/11 machine.
- Console colors: On modern Windows 10/11 consoles, colors should work. The app enables Virtual Terminal processing automatically. On older Windows versions, the colors may not render; functionality is unaffected.
- Screen clear uses system("cls"), which is specific to Windows.

Requirements on the target machine
- A standard Windows console.
- No additional runtimes should be needed for the default build produced by this CMake configuration.

Usage
- Run PyTha++.exe, enter non-negative numeric lengths for sides A and B, and the program will display side C.

Known limitations
- ANSI colors may not render on very old Windows versions.
- The program expects numeric, non-negative values.

Rebuild locally
- Use the existing CLion Debug profile and build the Test target.
