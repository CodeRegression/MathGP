#--------------------------------------------------------
# CMake for generating the MathGPLib
#
# @author: Wild Boar
#
# Date Created: 2022-10-30
#--------------------------------------------------------

# Setup the includes for the libraries
include_directories("../" "${LIBRARY_BASE}/NVLib" "${LIBRARY_BASE}/GeneticLib")

# Create Library
add_library (MathGPLib STATIC
	Grammar/LiteralNode.cpp
	Grammar/ConstantNode.cpp
	Grammar/AddNode.cpp
	Grammar/SubtractNode.cpp
	Grammar/MultiplyNode.cpp
	Grammar/DivideNode.cpp
	ArgUtils.cpp
	Candidate.cpp
	CandidateFactory.cpp
	Mutation.cpp
	ScoreFinder.cpp
)
