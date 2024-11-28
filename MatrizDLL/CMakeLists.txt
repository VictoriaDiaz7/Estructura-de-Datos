cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(MatrizDLL)

# Establece el estándar de C++
set(CMAKE_CXX_STANDARD 17)

# Archivos fuente
set(SOURCES
    matrizLambda.cpp
    matrizLambda.h
    MatrizDLL.h
    MatrizDLL.cpp
    Main.cpp
)

# Genera el ejecutable
add_executable(MatrizDLL ${SOURCES})
