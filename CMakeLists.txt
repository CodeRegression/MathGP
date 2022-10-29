#--------------------------------------------------------
# Top-Level: MathGP
#
# @author: Wild Boar
#
# @Date Created: 2022-10-30
#--------------------------------------------------------

# Create the main application
cmake_minimum_required(VERSION 3.0.0)
project(MathGP VERSION 0.1.0)

# Enable Testing
enable_testing()

# Set the correct version of C++
set(CMAKE_CXX_STANDARD 17)

# Setup base directory
set(LIBRARY_BASE $ENV{HOME}/Libraries)

# Add the NVLib library to the folder
add_library(NVLib STATIC IMPORTED)
set_target_properties(NVLib PROPERTIES
    IMPORTED_LOCATION "${LIBRARY_BASE}/NVLib/build/NVLib/libNVLib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${LIBRARY_BASE}/NVLib"
)

# Add the GeneticLib to the folder
add_library(GeneticLib STATIC IMPORTED)
set_target_properties(GeneticLib PROPERTIES
    IMPORTED_LOCATION "${LIBRARY_BASE}/GeneticLib/build/GeneticLib/libGeneticLib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${LIBRARY_BASE}/GeneticLib"
)

# Add opencv to the solution
find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Add the available subfolders
add_subdirectory(MathGPLib)
add_subdirectory(MathGPTests)
add_subdirectory(MathGP)

