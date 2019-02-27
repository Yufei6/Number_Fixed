//
// Created by nacelnik on 23/01/19.
//

#ifndef FIXED_FIXED_H
#define FIXED_FIXED_H

#include <cstddef>
#include <fstream>
#include <string>
#include <cmath>


namespace fp {
/*
* fixed  point  type
*/
    template<std::size_t Int, std::size_t Frac>
    class fixed {
    public
        :
        using underlying_type = double;
        underlying_type value;
        static constexpr
        std::size_t integer_part = Int;
        static constexpr
        std::size_t fractional_part = Frac;

        /*
        * constructors
        */
        fixed() = default;

        constexpr explicit fixed(float x){
            if(x>0){
                if(x/pow(2,integer_part)<1){
                    value=static_cast<underlying_type>(floor(x*pow(2,fractional_part)));
                }else{
                    throw std::overflow_error("This number is too big");
                }
            }else{
                if(x/-pow(2,integer_part)<1){
                    value=static_cast<underlying_type>(ceil(x*pow(2,fractional_part)));
                }else{
                    throw std::overflow_error("This number is too small");
                }
            }
        }
        


        constexpr explicit fixed(double x){
            if(x>0){
                if(x/pow(2,integer_part)<1){
                    value=static_cast<underlying_type>(floor(x*pow(2,fractional_part)));
                }else{
                    throw std::overflow_error("This number is too big");
                }
            }else{
                if(x/-pow(2,integer_part)<1){
                    value=static_cast<underlying_type>(ceil(x*pow(2,fractional_part)));
                }else{
                    throw std::overflow_error("This number is too small");
                }
            }
        }

/*
* copy  constructors
*/
        fixed(const fixed &other)
        : value(other.value){
        }

        template <std::size_t OtherInt, std::size_t OtherFrac>
        fixed(const fixed<OtherInt, OtherFrac> &other)
        : value(other.value){ 
        if (OtherFrac-Frac > 0)
            value = value << (OtherFrac-Frac);
        if (Frac-OtherFrac > 0)
            value = value >> (Frac-OtherFrac);
        }
        
/*
* copy  assignment
*/
        fixed &operator=(const fixed &other){
            return fixed<other.integer_part,other.fractional_part>(other.value);
        }

        template <std::size_t OtherInt, std::size_t OtherFrac>
        fixed &operator=(const fixed<OtherInt, OtherFrac> &other){
            return fixed<other.integer_part,other.fractional_part>(other.value);
        }

/*
* conversions
*/
        operator float()const;

        operator double()const;

/*
* compound  assignment  operators
*/
        fixed &operator+=(const fixed &other){
            this->value = this->value + other->value;
            return *this;
        }

        fixed &operator+=(float other){
            this->value = this->value + fixed<Int,Frac>(other).value;
            return *this;
        }

        fixed &operator+=(double other){
            this->value = this->value + fixed<Int,Frac>(other).value;
            return *this;
        }

        template <std::size_t OtherInt, std::size_t OtherFrac>
        fixed &operator+=(const fixed<OtherInt, OtherFrac> &other){
            this->value = this->value + other->value;
            return *this;
        }

        fixed &operator-=(const fixed &other){
            this->value = this->value - other->value;
        }

        fixed &operator-=(float other){
            this->value = this->value - fixed<Int, Frac>(other).value;
            return *this;
        }

        fixed &operator-=(double other){
            this->value = this->value - fixed<Int, Frac>(other)->value;
            return *this;
        }

        template <std::size_t OtherInt, std::size_t OtherFrac>
        fixed &operator-=(const fixed<OtherInt, OtherFrac> &other){
            this->value = this->value - other->value;
            return *this;
        }

        fixed &operator*=(const fixed &other){
            this->value = this->value * other->value;
            return *this;
        }

        fixed &operator*=(float other){
            this->value = this->value * fixed<Int,Frac>(other).value;
            return *this;
        }

        fixed &operator*=(double other){
            this->value = this->value * fixed<Int,Frac>(other).value;
            return *this;
        }

        template <std::size_t OtherInt, std::size_t OtherFrac>
        fixed &operator*=(const fixed<OtherInt, OtherFrac> &other){
            this->value = this->value * other->value;
            return *this;
        }

        fixed &operator/=(const fixed &other){
            this->value = this->value / other->value;
            return *this;
        }

        fixed &operator/=(float other){
            this->value = this->value / fixed<Int , Frac>(other).value;
            return *this;
        }

        fixed &operator/=(double other){
            this->value = this->value / fixed<Int , Frac>(other).value;
            return *this;
        }

        template <std::size_t OtherInt, std::size_t OtherFrac>
        fixed &operator/=(const fixed<OtherInt, OtherFrac> &other){
            this->value = this->value / other->value;
            return *this;
        }
    };

/*
* arithmetic  operators
*/
    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    double operator+(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        double res=0;
        return res;
    }

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    double operator-(fixed<I1, F1> lhs, fixed<I2, F2> rhs);

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    double operator*(fixed<I1, F1> lhs, fixed<I2, F2> rhs);

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    double operator/(fixed<I1, F1> lhs, fixed<I2, F2> rhs);

/*
* comparison  operators
*/
    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    bool operator==(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        return lhs->value == rhs->value;
    }

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    bool operator<(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        return lhs->value < rhs->value;
    }

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    bool operator>(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        return lhs->value > rhs->value;
    }

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    bool operator<=(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        return lhs->value <= rhs->value;
    }

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    bool operator>=(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        return lhs->value >= rhs->value;
    }
/*
* types
*/
    using Q_8_8 = fixed<8, 8>;
    using Q_16_16 = fixed<16, 16>;
    using Q_0_32 = fixed<0, 32>;

/*
* traits
*/
    template<typename Fixed>
    struct
    fixed_traits {
        static constexpr Fixed lowest();

        static constexpr Fixed min();

        static constexpr Fixed max();

        static constexpr Fixed zero();

        static constexpr Fixed one();

        static constexpr Fixed pi();
    };

/*
* functions
*/
    template<typename Fixed>
    Fixed sqrt(Fixed f){
        if(f->value<0){
            throw std::domain_error("sqrt must use with a positif number");
        }
        else{
            f->value = sqrt(f->value);
        }
        return f;
    }

    template<typename Fixed>
    std::string to_string(Fixed f){
        return std::to_string(f->value/(pow(2,f->fractional)));
    }

    template<typename Fixed>
    std::ostream &operator<<(std::ostream &os, Fixed f);
}

#endif //FIXED_FIXED_H
