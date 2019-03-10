#include "testfp.h"
#include "gtest/gtest.h"
#include "fixed.h"
#include <ostream>

class AutomatonTestFixture : public ::testing::Test {

};

//Test constexpr explicit fixed(float x);
TEST(fixedTest, constructorFloat){
    float x = 12.42;
    fp::fixed<8,8> f(x);
    EXPECT_EQ(f.value, 3179);
}

//Test constexpr explicit fixed(double x);
TEST(fixedTest, constructorDouble){
    double x = 12.42;
    fp::fixed<8,8> f(x);
    EXPECT_EQ(f.value, 3179);
}

// Test fixed &operator=(const fixed &other);
TEST(fixedTest, constructorFixed){
   double x = 12.42;
   fp::fixed<8,8> f(x);
   fp::fixed<8,8> f1(f);
   EXPECT_EQ(f.value, 3179);
   EXPECT_EQ(f1.value, 3179);
}

TEST(fixedTest, constructorFixed2){
   double x = 12.42;
   fp::fixed<16,16> f(x);
   fp::fixed<8,8> f1(f);
   EXPECT_EQ(f.value, 813957);
   EXPECT_EQ(f1.value, 3179);
}



int main(int argc, char **argv) {
	fp::fixed<16,16> new_f = fp::fixed<16,16>((float)-12.42);
	// std::cout << std::to_string(new_f.value/(pow(2,new_f.fractional_part))) << std::endl;
    // new_f<<(std::cout, new_f);
    // std::cout << fp::<Fixed>.to_string(new_f) << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    
    
    return RUN_ALL_TESTS();
}
