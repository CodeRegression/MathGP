//--------------------------------------------------
// Unit Tests for Arguments
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include <fstream>
#include <iostream>
using namespace std;

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/TreeFactory.h>
using namespace NVL_AI;

//--------------------------------------------------
// Prototypes
//--------------------------------------------------

void WriteHeader(ofstream& writer, const vector<double>& params);
void WriteMethod(ofstream& writer, int index, const string& expression, double value);

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm that the arguments are initialized correct
 */
TEST(Consistency_Test, test_example)
{
	// Setup the factory
    auto generator = new NVL_AI::RandomGenerator(); generator->Initialize();
    auto factory = NVL_AI::TreeFactory(generator, 10, 3, new NVLib::Range<int>(-1, 1));

    // Create the writer
    auto writer = ofstream("unit_test.cpp");

    // Write File header
    auto params = vector<double> { 1, 2, 3,};
    WriteHeader(writer, params );

    // Write out the test
    for (auto i = 0; i < 50; i++) 
    {
        auto tree = factory.GetRandomTree();
        auto expression = tree->ToString();
        auto value = tree->Evaluate(params);
        WriteMethod(writer, i, expression, value);
        delete tree;
    }

    // Write file closing
    writer.close();
}

//--------------------------------------------------
// Prototypes
//--------------------------------------------------

/**
 * @brief Generate the header of the unit test file
 * @param writer The writer for the header
 * @param params The resultant params
 */
void WriteHeader(ofstream& writer, const vector<double>& params) 
{
    auto paramString = stringstream();
    for (auto i = 0; i < params.size(); i++) 
    {
        if (i > 0) paramString << ",";
        paramString << params[i];
    }

    writer << "//--------------------------------------------------" << endl;
    writer << "// Unit Tests for Arguments" << endl;
    writer << "//" << endl;
    writer << "// @author: Wild Boar" << endl;
    writer << "//" << endl;
    writer << "// @date: 2022-10-30" << endl;
    writer << "//--------------------------------------------------" << endl;
    writer << endl;
    writer << "#include <fstream>" << endl;
    writer << "#include <iostream>" << endl;
    writer << "using namespace std;" << endl;
    writer << endl;
    writer << "#include <gtest/gtest.h>" << endl;
    writer << endl;
    writer << "//--------------------------------------------------" << endl;
    writer << "// Set the parameters here" << endl;
    writer << "//--------------------------------------------------" << endl;
    writer << endl;
    writer << "inline vector<double> GetP() { return vector<double> {" << paramString.str() << "}; }" << endl;
}

/**
 * @brief Generate a unit test
 * @param writer The writer that we are writing to
 * @param index The index of the test
 * @param expression The expression that we are evaluating
 * @param value The value that the expression should have
 */
void WriteMethod(ofstream& writer, int index, const string& expression, double value) 
{
    auto functionName = stringstream(); functionName << "expression_" << setw(4) << setfill('0') << index;
    writer << endl;
    writer << "/**" << endl;
    writer << " * Expression Unit test " << index << endl;
    writer << " */" << endl;
    writer << "TEST(Consistency_Test, " << functionName.str() << ")";
    writer << "{" << endl;
    writer << "\tauto p = GetP();" << endl;
    writer << "\tauto actual = " << expression << ";" << endl;
    writer << endl;
    writer << "\tASSERT_NEAR(actual, " << value << ", 1e-4);" << endl;
    writer << "}" << endl;
}
