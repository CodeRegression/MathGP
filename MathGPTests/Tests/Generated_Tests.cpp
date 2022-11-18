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

//--------------------------------------------------
// Set the parameters here
//--------------------------------------------------

inline vector<double> GetP() { return vector<double> {1,2,3}; }

/**
 * Expression Unit test 0
 */
TEST(Consistency_Test, expression_0000){
	auto p = GetP();
	auto actual = ((((((p[2] * p[1]) + 0.960) - (p[1] / p[2])) - (1.0 / (-0.050 - p[0]))) + 0.090) / p[2]);

	ASSERT_NEAR(actual, 2.44524, 1e-4);
}

/**
 * Expression Unit test 1
 */
TEST(Consistency_Test, expression_0001){
	auto p = GetP();
	auto actual = ((((0.770 - p[1]) - (p[2] + 0.590)) - ((-1 * p[1]) / p[2])) - ((0.500 + p[2]) - (0.080 - 0.770)));

	ASSERT_NEAR(actual, -8.34333, 1e-4);
}

/**
 * Expression Unit test 2
 */
TEST(Consistency_Test, expression_0002){
	auto p = GetP();
	auto actual = ((p[2] * p[2]) * (p[0] * ((((0.140 + -0.760) / 0.500) * (-1 * -0.590)) / -0.420)));

	ASSERT_NEAR(actual, 15.6771, 1e-4);
}

/**
 * Expression Unit test 3
 */
TEST(Consistency_Test, expression_0003){
	auto p = GetP();
	auto actual = ((((p[2] * p[2]) - (-0.220 - -0.290)) + (-1 * -0.150)) * ((-1 * (0.130 * -0.220)) * ((1.0 / p[0]) - p[0])));

	ASSERT_NEAR(actual, 0, 1e-4);
}

/**
 * Expression Unit test 4
 */
TEST(Consistency_Test, expression_0004){
	auto p = GetP();
	auto actual = ((-1 * (1.0 / (-1 * (0.200 / ((0.200 * p[0]) * p[0]))))) + (-1 * (-1 * -0.320)));

	ASSERT_NEAR(actual, 0.68, 1e-4);
}

/**
 * Expression Unit test 5
 */
TEST(Consistency_Test, expression_0005){
	auto p = GetP();
	auto actual = (((p[0] - (p[2] * 0.550)) - ((1.0 / p[0]) / (0.400 / 0.250))) / (p[1] / (-1 * (1.0 / p[2]))));

	ASSERT_NEAR(actual, 0.2125, 1e-4);
}

/**
 * Expression Unit test 6
 */
TEST(Consistency_Test, expression_0006){
	auto p = GetP();
	auto actual = (p[0] * ((p[2] + -0.030) + ((1.0 / (-0.310 + p[2])) - ((0.440 + p[2]) / (-0.490 + p[0])))));

	ASSERT_NEAR(actual, -3.40335, 1e-4);
}

/**
 * Expression Unit test 7
 */
TEST(Consistency_Test, expression_0007){
	auto p = GetP();
	auto actual = ((0.330 / (-1 * 0.490)) / (-0.730 / (((0.860 * 0.410) - (p[2] * -0.300)) * (-0.240 * 0.140))));

	ASSERT_NEAR(actual, -0.0388281, 1e-4);
}

/**
 * Expression Unit test 8
 */
TEST(Consistency_Test, expression_0008){
	auto p = GetP();
	auto actual = (((p[1] - (0.020 + p[2])) * (1.0 / (p[1] * 0.120))) / ((-1 * (0.100 + p[1])) - ((p[1] / p[2]) * 0.940)));

	ASSERT_NEAR(actual, 1.55868, 1e-4);
}

/**
 * Expression Unit test 9
 */
TEST(Consistency_Test, expression_0009){
	auto p = GetP();
	auto actual = (((-0.510 / 0.700) + ((1.0 / -0.740) + (1.0 / p[1]))) * (((0.900 - -0.430) - p[1]) - (-0.910 / 0.880)));

	ASSERT_NEAR(actual, -0.575236, 1e-4);
}

/**
 * Expression Unit test 10
 */
TEST(Consistency_Test, expression_0010){
	auto p = GetP();
	auto actual = ((0.490 + (1.0 / ((1.0 / p[0]) / -0.850))) - (((p[2] / -0.010) - p[0]) + (1.0 / (p[2] / 0.160))));

	ASSERT_NEAR(actual, 300.587, 1e-3);
}

/**
 * Expression Unit test 11
 */
TEST(Consistency_Test, expression_0011){
	auto p = GetP();
	auto actual = ((((1.0 / (p[0] / 0.890)) - 0.430) * (1.0 / (1.0 / (1.0 / p[1])))) - (-1 * (1.0 / (p[1] * p[0]))));

	ASSERT_NEAR(actual, 0.73, 1e-4);
}

/**
 * Expression Unit test 12
 */
TEST(Consistency_Test, expression_0012){
	auto p = GetP();
	auto actual = (((1.0 / ((p[0] - -0.130) * (1.000 / p[2]))) + p[1]) / (((p[2] - 0.320) / p[2]) / p[2]));

	ASSERT_NEAR(actual, 15.632, 1e-4);
}

/**
 * Expression Unit test 13
 */
TEST(Consistency_Test, expression_0013){
	auto p = GetP();
	auto actual = ((((0.310 * p[2]) + (0.670 + p[1])) / -0.480) * (((-1 * p[0]) / (-1 * p[1])) * ((p[2] + p[1]) * 0.350)));

	ASSERT_NEAR(actual, -6.5625, 1e-4);
}

/**
 * Expression Unit test 14
 */
TEST(Consistency_Test, expression_0014){
	auto p = GetP();
	auto actual = (p[2] + (1.0 / ((-1 * 0.300) - -0.510)));

	ASSERT_NEAR(actual, 7.7619, 1e-4);
}

/**
 * Expression Unit test 15
 */
TEST(Consistency_Test, expression_0015){
	auto p = GetP();
	auto actual = (0.580 * ((((-1 * 0.740) / (p[2] * p[1])) / (-1 * (0.740 + -0.590))) / ((0.980 + p[0]) - (0.250 - 0.850))));

	ASSERT_NEAR(actual, 0.184841, 1e-4);
}

/**
 * Expression Unit test 16
 */
TEST(Consistency_Test, expression_0016){
	auto p = GetP();
	auto actual = ((((0.480 + -0.040) + 0.560) / ((0.400 - p[1]) * -0.570)) * ((1.0 / (1.0 / p[0])) - (-1 * p[2])));

	ASSERT_NEAR(actual, 4.38596, 1e-4);
}

/**
 * Expression Unit test 17
 */
TEST(Consistency_Test, expression_0017){
	auto p = GetP();
	auto actual = (((1.0 / ((p[0] - p[2]) - (p[1] - p[2]))) / (((p[2] * p[0]) * p[1]) - (-1 * p[0]))) * (1.0 / p[1]));

	ASSERT_NEAR(actual, -0.0714286, 1e-4);
}

/**
 * Expression Unit test 18
 */
TEST(Consistency_Test, expression_0018){
	auto p = GetP();
	auto actual = (p[0] + (0.880 / (((1.0 / p[2]) - 0.800) - p[1])));

	ASSERT_NEAR(actual, 0.643243, 1e-4);
}

/**
 * Expression Unit test 19
 */
TEST(Consistency_Test, expression_0019){
	auto p = GetP();
	auto actual = (((1.0 / ((1.0 / -0.190) + 0.330)) * ((-1 * p[1]) - (0.390 * 0.200))) - (-1 * ((p[1] * p[2]) / (1.0 / 0.050))));

	ASSERT_NEAR(actual, 0.721231, 1e-4);
}

/**
 * Expression Unit test 20
 */
TEST(Consistency_Test, expression_0020){
	auto p = GetP();
	auto actual = (((p[2] * ((0.700 / (0.930 / 0.280)) * ((1.0 / p[0]) * p[1]))) * 0.130) - p[0]);

	ASSERT_NEAR(actual, -0.835613, 1e-4);
}

/**
 * Expression Unit test 21
 */
TEST(Consistency_Test, expression_0021){
	auto p = GetP();
	auto actual = ((((-1 * -0.790) * p[2]) - (-1 * (-0.500 * 0.510))) + (-0.730 / ((0.670 / p[0]) + (0.470 * -0.460))));

	ASSERT_NEAR(actual, 0.506362, 1e-4);
}

/**
 * Expression Unit test 22
 */
TEST(Consistency_Test, expression_0022){
	auto p = GetP();
	auto actual = (0.740 + ((-0.480 / ((-1 * 0.350) / (0.200 / p[1]))) + (((-1 * 0.740) / p[0]) - (p[0] * p[1]))));

	ASSERT_NEAR(actual, -1.86286, 1e-4);
}

/**
 * Expression Unit test 23
 */
TEST(Consistency_Test, expression_0023){
	auto p = GetP();
	auto actual = ((((p[1] / 0.060) - (p[2] + p[2])) / ((p[1] - p[1]) * (1.0 / p[0]))) / (((-0.030 + p[1]) * -0.620) + (-1 * p[2])));

	ASSERT_NEAR(actual, -236888, 1e-4);
}

/**
 * Expression Unit test 24
 */
TEST(Consistency_Test, expression_0024){
	auto p = GetP();
	auto actual = ((-1 * ((-1 * (p[0] * -0.080)) / (-0.110 * p[1]))) / ((1.0 / (0.870 * -0.970)) * (-1 * p[2])));

	ASSERT_NEAR(actual, 0.102291, 1e-4);
}

/**
 * Expression Unit test 25
 */
TEST(Consistency_Test, expression_0025){
	auto p = GetP();
	auto actual = ((((p[2] / 0.840) - (-0.840 - -0.510)) - (-1 * (-0.540 / p[0]))) - ((1.0 / 0.140) + ((p[2] + -0.110) / p[2])));

	ASSERT_NEAR(actual, -4.74476, 1e-4);
}

/**
 * Expression Unit test 26
 */
TEST(Consistency_Test, expression_0026){
	auto p = GetP();
	auto actual = (((p[1] + (p[1] - p[1])) - ((p[0] * 0.120) * (0.470 + -0.330))) + ((-0.090 / p[0]) - (p[1] / p[1])));

	ASSERT_NEAR(actual, 0.8932, 1e-4);
}

/**
 * Expression Unit test 27
 */
TEST(Consistency_Test, expression_0027){
	auto p = GetP();
	auto actual = (((-0.110 - (0.130 - 0.150)) - ((-1 * -0.680) * (-0.670 / p[1]))) / (-0.130 * (-1 * (-1 * -0.170))));

	ASSERT_NEAR(actual, 6.23529, 1e-4);
}

/**
 * Expression Unit test 28
 */
TEST(Consistency_Test, expression_0028){
	auto p = GetP();
	auto actual = (-0.690 * (1.0 / ((((-1 * (p[1] / p[0])) + ((-0.730 / p[2]) * 0.960)) * p[0]) - -0.030)));

	ASSERT_NEAR(actual, 0.313124, 1e-4);
}

/**
 * Expression Unit test 29
 */
TEST(Consistency_Test, expression_0029){
	auto p = GetP();
	auto actual = ((1.0 / ((p[2] / ((p[0] / p[2]) + (p[2] + -0.930))) / ((-1 * p[1]) - 0.050))) * 0.400);

	ASSERT_NEAR(actual, -0.656911, 1e-4);
}

/**
 * Expression Unit test 30
 */
TEST(Consistency_Test, expression_0030){
	auto p = GetP();
	auto actual = (((((p[0] + -0.560) / (p[1] / 0.370)) - (p[2] * -0.770)) - p[2]) + (-1 * ((p[1] * -0.560) / (0.340 * p[2]))));

	ASSERT_NEAR(actual, 0.489439, 1e-4);
}

/**
 * Expression Unit test 31
 */
TEST(Consistency_Test, expression_0031){
	auto p = GetP();
	auto actual = (p[2] + (1.0 / p[2]));

	ASSERT_NEAR(actual, 3.33333, 1e-4);
}

/**
 * Expression Unit test 32
 */
TEST(Consistency_Test, expression_0032){
	auto p = GetP();
	auto actual = ((((0.050 / 0.050) * (p[0] / -0.200)) / (-1 * (p[1] * p[2]))) + (((0.070 + p[1]) - 0.270) * -0.140));

	ASSERT_NEAR(actual, 0.581333, 1e-4);
}

/**
 * Expression Unit test 33
 */
TEST(Consistency_Test, expression_0033){
	auto p = GetP();
	auto actual = (((0.410 * p[1]) - -0.850) - (((-1 * -0.530) / (-0.150 + 0.660)) - (1.0 / (p[0] - 0.020))));

	ASSERT_NEAR(actual, 1.65119, 1e-4);
}

/**
 * Expression Unit test 34
 */
TEST(Consistency_Test, expression_0034){
	auto p = GetP();
	auto actual = ((((-0.730 - p[0]) + p[1]) * ((p[0] - 0.860) + (-0.730 * p[2]))) * ((1.0 / (p[0] - p[1])) + (0.800 * 0.940)));

	ASSERT_NEAR(actual, 0.137268, 1e-4);
}

/**
 * Expression Unit test 35
 */
TEST(Consistency_Test, expression_0035){
	auto p = GetP();
	auto actual = (p[1] * ((-1 * p[1]) + (1.0 / (1.0 / ((1.0 / (-1 * 0.130)) + ((0.910 + p[2]) / -0.130))))));

	ASSERT_NEAR(actual, -79.5385, 1e-4);
}

/**
 * Expression Unit test 36
 */
TEST(Consistency_Test, expression_0036){
	auto p = GetP();
	auto actual = ((1.0 / ((-1 * ((p[1] / p[2]) * (0.140 + p[1]))) - ((0.660 / 0.440) * (p[1] + p[1])))) - (1.0 / p[2]));

	ASSERT_NEAR(actual, -0.467983, 1e-4);
}

/**
 * Expression Unit test 37
 */
TEST(Consistency_Test, expression_0037){
	auto p = GetP();
	auto actual = ((-1 * ((p[0] + p[2]) * (-1 * -0.930))) / (((p[1] + p[2]) * (-1 * -0.220)) + ((-0.910 - p[1]) / (p[2] * -0.340))));

	ASSERT_NEAR(actual, -0.941071, 1e-4);
}

/**
 * Expression Unit test 38
 */
TEST(Consistency_Test, expression_0038){
	auto p = GetP();
	auto actual = ((((-0.180 * p[1]) - (0.770 + p[0])) * ((p[2] / -1.000) / (p[1] * -0.480))) + (((p[0] - -0.480) - p[0]) - (p[0] + -0.640)));

	ASSERT_NEAR(actual, -6.53625, 1e-4);
}

/**
 * Expression Unit test 39
 */
TEST(Consistency_Test, expression_0039){
	auto p = GetP();
	auto actual = ((((-1 * ((p[1] - p[2]) - (-0.130 / -0.650))) + ((p[2] / p[0]) - (-1 * p[0]))) * p[2]) - 0.030);

	ASSERT_NEAR(actual, 15.57, 1e-4);
}

/**
 * Expression Unit test 40
 */
TEST(Consistency_Test, expression_0040){
	auto p = GetP();
	auto actual = (-0.700 - (-1 * (-0.600 + (((0.260 + p[2]) + p[0]) - (p[0] - p[0])))));

	ASSERT_NEAR(actual, 2.96, 1e-4);
}

/**
 * Expression Unit test 41
 */
TEST(Consistency_Test, expression_0041){
	auto p = GetP();
	auto actual = ((1.0 / 0.850) / 0.940);

	ASSERT_NEAR(actual, 1.25156, 1e-4);
}

/**
 * Expression Unit test 42
 */
TEST(Consistency_Test, expression_0042){
	auto p = GetP();
	auto actual = (((1.0 / ((0.690 / p[0]) - -0.020)) / (((-0.670 + -0.890) - p[1]) + (p[0] / 0.680))) / p[0]);

	ASSERT_NEAR(actual, -0.67409, 1e-4);
}

/**
 * Expression Unit test 43
 */
TEST(Consistency_Test, expression_0043){
	auto p = GetP();
	auto actual = (((1.0 / (0.910 + p[2])) / ((-0.290 - 0.270) - (-0.260 / -0.110))) + (0.730 / ((0.790 + p[2]) - p[0])));

	ASSERT_NEAR(actual, 0.174171, 1e-4);
}

/**
 * Expression Unit test 44
 */
TEST(Consistency_Test, expression_0044){
	auto p = GetP();
	auto actual = ((((-0.100 * -0.970) / (p[0] + 0.040)) + ((p[2] / 0.430) + (p[2] - p[1]))) * (1.0 / ((0.530 - 1.000) * (0.170 + 0.670))));

	ASSERT_NEAR(actual, -20.4408, 1e-4);
}

/**
 * Expression Unit test 45
 */
TEST(Consistency_Test, expression_0045){
	auto p = GetP();
	auto actual = ((((0.320 - 0.080) + (p[1] / p[0])) * ((0.970 / -0.310) + (p[1] / 0.660))) + (((-1 * p[1]) / p[2]) + (0.980 - 0.660)));

	ASSERT_NEAR(actual, -0.56782, 1e-4);
}

/**
 * Expression Unit test 46
 */
TEST(Consistency_Test, expression_0046){
	auto p = GetP();
	auto actual = ((-0.520 - (-1 * (p[0] - -0.700))) - (((1.0 / p[2]) - p[0]) - ((-0.310 - p[0]) / (-0.840 * p[1]))));

	ASSERT_NEAR(actual, 2.62643, 1e-4);
}

/**
 * Expression Unit test 47
 */
TEST(Consistency_Test, expression_0047){
	auto p = GetP();
	auto actual = ((-1 * (p[0] - ((1.0 / -0.350) - (((1.0 / p[2]) + p[1]) / p[1])))) / 0.740);

	ASSERT_NEAR(actual, -6.78893, 1e-4);
}

/**
 * Expression Unit test 48
 */
TEST(Consistency_Test, expression_0048){
	auto p = GetP();
	auto actual = (((1.0 / (p[1] + p[2])) - ((-1 * -0.800) - (0.540 / -0.100))) * (1.0 / ((0.680 - 0.050) - (0.160 + 0.320))));

	ASSERT_NEAR(actual, -40, 1e-4);
}

/**
 * Expression Unit test 49
 */
TEST(Consistency_Test, expression_0049){
	auto p = GetP();
	auto actual = (((1.0 / ((1.0 / p[2]) + (-0.270 * p[0]))) - (((-1 * 0.120) / p[0]) - (p[1] + -0.550))) / (1.0 / 0.330));

	ASSERT_NEAR(actual, 5.72863, 1e-4);
}
