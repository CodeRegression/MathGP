#--------------------------------------------------------
# CMake for generating MathGPLib Testing Suite
#
# @author: Wild Boar
#
# Date Created: 2022-10-30
#--------------------------------------------------------

# Add Google Test to the test group
find_package(GTest REQUIRED)

# Setup the includes
include_directories("../")

# Add the UnitTestLib library to the folder
add_library(UnitTestLib STATIC IMPORTED)
set_target_properties(UnitTestLib PROPERTIES
    IMPORTED_LOCATION "${LIBRARY_BASE}/UnitTestLib/build/UnitTestLib/libUnitTestLib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${LIBRARY_BASE}/UnitTestLib"
)

# Create the executable
add_executable (MathGPTests
	Tests/Example_Tests.cpp
	Tests/LiteralNode_Tests.cpp
	Tests/ConstantNode_Tests.cpp
	Tests/AddNode_Tests.cpp
	Tests/SubtractNode_Tests.cpp
	Tests/MultiplyNode_Tests.cpp
	Tests/DivideNode_Tests.cpp
)







# Add link libraries
target_link_libraries(MathGPTests MathGPLib NVLib ${OpenCV_LIBS} UnitTestLib GTest::Main)

# Find the associated unit tests
gtest_discover_tests(MathGPTests)
