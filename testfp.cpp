#include "testfp.h"
#include "gtest/gtest.h"
#include "fixed.h"
#include <ostream>

class AutomatonTestFixture : public ::testing::Test {

};

//Test constexpr explicit fixed(float x);
/*TEST(fixedTest, constructorFloat){
    float x = 12.42;
    fp::fixed<8,8> f(x);
    EXPECT_EQ(f.value, 3180);
}

//Test constexpr explicit fixed(double x);
TEST(fixedTest, constructorDouble){
    double x = 12.42;
    fp::fixed<8,8> f(x);
    EXPECT_EQ(f.value, 3180);
}

//Test fixed &operator=(const fixed &other);
//TEST(fixedTest, constructorFixed){
//    double x = 12.42;
//    fp::fixed<8,8> f(x);
//    fp::fixed<8,8> f1(f);
//    EXPECT_EQ(f1.value, 3280);
//}*/

int main(int argc, char **argv) {
	fp::fixed<8,8> new_f = fp::fixed<8,8>((float)12.42);
	std::cout << new_f.value << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
