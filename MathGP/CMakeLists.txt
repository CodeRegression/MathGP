#--------------------------------------------------------
# CMake for generating the main executable
#
# @author: Wild Boar
#
# Date Created: 2022-10-30
#--------------------------------------------------------

# Setup the includes
include_directories("../" "${LIBRARY_BASE}/NVLib" "${LIBRARY_BASE}/GeneticLib")

# Create the executable
add_executable(MathGP
    Engine.cpp
    Source.cpp
)

# Add link libraries                               
target_link_libraries(MathGP MathGPLib NVLib GeneticLib ${OpenCV_LIBS})

# Copy Resources across
add_custom_target(resource_copy ALL
	COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/Resources ${CMAKE_BINARY_DIR}/MathGP 
    DEPENDS ${MY_TARGET}
)
