#include "testfp.h"
#include "gtest/gtest.h"
#include "fixed.h"
#include <ostream>

class AutomatonTestFixture : public ::testing::Test {

};

//Test constexpr explicit fixed(float x);
TEST(fixedTest, constructorFloat){
    float x = 12.42;
    fp::fixed<8,8> f = fp::fixed<8,8>(x);
    EXPECT_EQ(f.value, 3179);
}

//Test constexpr explicit fixed(double x);
TEST(fixedTest, constructorDouble){
    double x = 12.42;
    fp::fixed<8,8> f = fp::fixed<8,8>(x);
    EXPECT_EQ(float(f.value/pow(2,f.fractional_part)), 12.417969);
}

// Test fixed &operator=(const fixed &other);
TEST(fixedTest, constructorFixed){
   double x = 12.42;
   fp::fixed<8,8> f = fp::fixed<8,8>(x);
   fp::fixed<8,8> f1 = fp::fixed<8,8>(f);
   EXPECT_EQ(f.value, 3179);
   EXPECT_EQ(f1.value, 3179);
}

TEST(fixedTest, constructorFixed2){
   double x = 12.42;
   fp::fixed<16,16> f = fp::fixed<16,16>(x);
   fp::fixed<8,8> f1(f);
   EXPECT_EQ(f.value, 813957);
   EXPECT_EQ(f1.value, 3179);
}


// TEST(fixedTest, constructorFixed3){
//   double x = 12.42;
//   fp::fixed<8,8> f = fp::fixed<8,8>(x);
//   fp::fixed<16,16> f1(f);
//   EXPECT_EQ(f.value, 3179);
//   EXPECT_EQ(f1.value, 813957);
// }





//Tests pour comparaison
TEST(fixedTest, comparaisonFixed){
  double x = 12.42;
  double y = 14.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 =fp::fixed<8,8>(y);
  ASSERT_FALSE(f > f1);
  ASSERT_FALSE(f == f1);
}

// TEST(fixedTest, comparaisonFixed1){
//   double x = 12.42;
//   fp::fixed<8,8> f = fp::fixed<8,8>(x);
//   fp::fixed<16,16> f1(f);
//   EXPECT_EQ(f.value, 3179);
//   EXPECT_EQ(f1.value, 813957);
// }

// TEST(fixedTest, comparaisonFixed2){
//   double x = 12.42;
//   fp::fixed<8,8> f = fp::fixed<8,8>(x);
//   fp::fixed<16,16> f1(f);
//   EXPECT_EQ(f.value, 3179);
//   EXPECT_EQ(f1.value, 813957);
// }

// TEST(fixedTest, comparaisonFixed3){
//   double x = 12.42;
//   fp::fixed<8,8> f = fp::fixed<8,8>(x);
//   fp::fixed<16,16> f1(f);
//   EXPECT_EQ(f.value, 3179);
//   EXPECT_EQ(f1.value, 813957);
// }



int main(int argc, char **argv) {
	fp::fixed<8,8> new_f = fp::fixed<8,8>((float)12.42);
  std::cout << std::to_string(new_f.value/(pow(2,new_f.fractional_part))) << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
	// std::cout << std::to_string(new_f.value/(pow(2,new_f.fractional_part))) << std::endl;
    // new_f<<(std::cout, new_f);
    // std::cout << fp::<Fixed>.to_string(new_f) << std::endl;
    
    
    return RUN_ALL_TESTS();
}
