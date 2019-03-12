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
    EXPECT_EQ(std::to_string((float)(f)), "12.417969");
}

TEST(fixedTest, constructorDouble1){
    double x = 12.42;
    fp::fixed<8,8> f = fp::fixed<8,8>(x);
    ASSERT_TRUE(float(f) > 12.41);
    ASSERT_TRUE(float(f) < 12.42);
}

// Tests copy constructors
TEST(fixedTest, constructorFixed){
  double x = 12.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(f);
  EXPECT_EQ(std::to_string((float)(f)), "12.417969");
  EXPECT_EQ(std::to_string((float)(f1)), "12.417969");
}

TEST(fixedTest, constructorFixed2){
   double x = 12.42;
   fp::fixed<16,16> f = fp::fixed<16,16>(x);
   fp::fixed<8,8> f1 = f;
   EXPECT_EQ(std::to_string((float)(f)), "12.419998");
   EXPECT_EQ(std::to_string((float)(f1)), "12.417969");
}






// Tests for copy assignment
TEST(fixedTest, copyassignment){
  double x = 12.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1;
  f1 = f;
  EXPECT_EQ(std::to_string((float)(f)), "12.417969");
  EXPECT_EQ(std::to_string((float)(f1)), "12.417969");
}

TEST(fixedTest, copyassignment1){
  double x = 12.42;
  fp::fixed<16,16> f = fp::fixed<16,16>(x);
  fp::fixed<16,16> f1;
  f1 = f;
  EXPECT_EQ(std::to_string((float)(f)), "12.419998");
  EXPECT_EQ(std::to_string((float)(f1)), "12.419998");
}

TEST(fixedTest, copyassignment2){
  double x = 12.42;
  fp::fixed<16,16> f = fp::fixed<16,16>(x);
  fp::fixed<8,8> f1;
  f1 = f;
  EXPECT_EQ(std::to_string((float)(f)), "12.419998");
  EXPECT_EQ(std::to_string((float)(f)), "12.419998");
}


//Tests for comparaison
TEST(fixedTest, comparaisonFixed){
  double x = 12.42;
  double y = 14.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_FALSE(f > f1);
}

TEST(fixedTest, comparaisonFixed1){
  double x = 12.42;
  double y = 14.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_FALSE(f == f1);
}

TEST(fixedTest, comparaisonFixed2){
  double x = 12.42;
  double y = 14.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE(f < f1);
}

TEST(fixedTest, comparaisonFixed3){
  double x = 12.42;
  double y = 14.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE(f != f1);
}

TEST(fixedTest, comparaisonFixed4){
  double x = 12.42;
  double y = 14.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE(f <= f1);
}

TEST(fixedTest, comparaisonFixed5){
  double x = 12.42;
  double y = 14.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_FALSE(f >= f1);
}


TEST(fixedTest, comparaisonFixed6){
  double x = 12.42;
  double y = 12.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE(f == f1);
}

TEST(fixedTest, comparaisonFixed7){
  double x = 12.42;
  double y = 12.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE(f >= f1);
}

TEST(fixedTest, comparaisonFixed8){
  double x = 12.42;
  double y = 12.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE(f <= f1);
}

TEST(fixedTest, comparaisonFixed9){
  double x = 12.42;
  double y = 12.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<16,16> f1 = fp::fixed<16,16>(y);
  ASSERT_FALSE(f == f1);
  ASSERT_TRUE(f <= f1);
}

TEST(fixedTest, comparaisonFixed10){
  double x = 12.42;
  double y = 12.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<16,16> f1 = fp::fixed<16,16>(y);
  ASSERT_TRUE(f != f1);
  ASSERT_FALSE(f >= f1);
}


//tests for arithmetic operators
TEST(fixedTest, arithmeticoperators){
  double x = 12.42;
  double y = 12.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE((f + f1) > 24.83);
  ASSERT_TRUE((f + f1) < 24.84);
}

TEST(fixedTest, arithmeticoperators1){
  double x = 12.42;
  double y = 12.42;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<16,16> f1 = fp::fixed<16,16>(y);
  ASSERT_TRUE((f + f1) > 24.83);
  ASSERT_TRUE((f + f1) < 24.84);
}

TEST(fixedTest, arithmeticoperators2){
  double x = 12.42;
  double y = 6.21;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE((f - f1) > 6.20);
  ASSERT_TRUE((f - f1) < 6.22);
}

TEST(fixedTest, arithmeticoperators3){
  double x = 12.42;
  double y = 6.21;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<16,16> f1 = fp::fixed<16,16>(y);
  ASSERT_TRUE((f - f1) > 6.20);
  ASSERT_TRUE((f - f1) < 6.21);
}

TEST(fixedTest, arithmeticoperators4){
  double x = 12.42;
  double y = 2.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE((f * f1) > 24.80);
  ASSERT_TRUE((f * f1) < 24.84);
}

TEST(fixedTest, arithmeticoperators5){
  double x = 12.42;
  double y = 2.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<16,16> f1 = fp::fixed<16,16>(y);
  ASSERT_TRUE((f * f1) > 24.80);
  ASSERT_TRUE((f * f1) < 24.84);
}

TEST(fixedTest, arithmeticoperators6){
  double x = 12.42;
  double y = 2.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE((f / f1) > 6.20);
  ASSERT_TRUE((f / f1) < 6.22);
}

TEST(fixedTest, arithmeticoperators7){
  double x = 12.42;
  double y = 2.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<16,16> f1 = fp::fixed<16,16>(y);
  ASSERT_TRUE((f / f1) > 6.20);
  ASSERT_TRUE((f / f1) < 6.22);
}





// tests for assignment  operators

TEST(fixedTest, assignmentoperators){
  double x = 12.42;
  double y = 1.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE(float(f+=f1) > 13.41);
  ASSERT_TRUE(float(f+=f1) < 14.42);
}

TEST(fixedTest, assignmentoperators1){
  double x = 12.42;
  double y = 1.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  ASSERT_TRUE(float(f+=y) > 13.41);
  ASSERT_TRUE(float(f+=y) < 14.42);
}

TEST(fixedTest, assignmentoperators2){
  double x = 12.42;
  float y = 1.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  ASSERT_TRUE(float(f+=y) > 13.41);
  ASSERT_TRUE(float(f+=y) < 14.42);
}

TEST(fixedTest, assignmentoperators3){
  double x = 12.42;
  double y = 1.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<16,16> f1 = fp::fixed<16,16>(y);
  ASSERT_TRUE(float(f+=f1) > 13.41);
  ASSERT_TRUE(float(f+=f1) < 14.42);
}


TEST(fixedTest, assignmentoperators4){
  double x = 12.42;
  double y = 1.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE(float(f-=f1) > 11.41);
  ASSERT_TRUE(float(f-=f1) < 10.42);
}

TEST(fixedTest, assignmentoperators5){
  double x = 12.42;
  double y = 1.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  ASSERT_TRUE(float(f-=y) > 11.41);
  ASSERT_TRUE(float(f-=y) < 10.42);
}

TEST(fixedTest, assignmentoperators6){
  double x = 12.42;
  float y = 1.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  ASSERT_TRUE(float(f-=y) > 11.41);
  ASSERT_TRUE(float(f-=y) < 10.42);
}

TEST(fixedTest, assignmentoperators7){
  double x = 12.42;
  double y = 1.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<16,16> f1 = fp::fixed<16,16>(y);
  ASSERT_TRUE(float(f-=f1) > 11.41);
  ASSERT_TRUE(float(f-=f1) < 10.42);
}

TEST(fixedTest, assignmentoperators8){
  double x = 12.42;
  double y = 2.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE(float(f*=f1) > 24.82);
}

TEST(fixedTest, assignmentoperators9){
  double x = 12.42;
  double y = 2.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  ASSERT_TRUE(float(f*=y) > 24.82);
}

TEST(fixedTest, assignmentoperators10){
  double x = 12.42;
  float y = 2.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  ASSERT_TRUE(float(f*=y) > 24.82);
}

TEST(fixedTest, assignmentoperators11){
  double x = 12.42;
  double y = 2.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<16,16> f1 = fp::fixed<16,16>(y);
  ASSERT_TRUE(float(f*=f1) > 24.82);
}

TEST(fixedTest, assignmentoperators12){
  double x = 12.42;
  double y = 2.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<8,8> f1 = fp::fixed<8,8>(y);
  ASSERT_TRUE(float(f/=f1) > 6.20);
}

TEST(fixedTest, assignmentoperators13){
  double x = 12.42;
  double y = 2.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  ASSERT_TRUE(float(f/=y) > 6.20);
}

TEST(fixedTest, assignmentoperators14){
  double x = 12.42;
  float y = 2.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  ASSERT_TRUE(float(f/=y) > 6.20);
}

TEST(fixedTest, assignmentoperators15){
  double x = 12.42;
  double y = 2.0;
  fp::fixed<8,8> f = fp::fixed<8,8>(x);
  fp::fixed<16,16> f1 = fp::fixed<16,16>(y);
  ASSERT_TRUE(float(f/=f1) > 6.20);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
	  // std::cout << std::to_string(new_f.value/(pow(2,new_f.fractional_part))) << std::endl;
    // new_f<<(std::cout, new_f);
    // std::cout << fp::<Fixed>.to_string(new_f) << std::endl;
    
    
    return RUN_ALL_TESTS();
}
