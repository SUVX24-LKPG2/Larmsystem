# Larmsystem

## Overview
Larmsystem is a security alarm management system. It includes various components such as customer management, event handling, and database interactions.

## Build Instructions

### Prerequisites
- CMake 3.31.2 or higher
- Ninja build system
- C++ Compiler
- SQLite3 library

### Steps
1. Clone the repository:
    ```sh
    git clone https://github.com/SUVX24-LKPG2/Larmsystem
    cd Larmsystem
    ```

2. Create a build directory and navigate into it:
    ```sh
    mkdir build
    cd build
    ```

3. Configure the project using CMake:
    ```sh
    cmake -G Ninja ..
    ```

4. Build the project:
    ```sh
    ninja
    ```

### Alternative
1. Use build script:
    ```sh
    bash ./build.sh
    ```

## Running the Application
After building the project, you can run the application using:
```sh
./larmsystem
```
