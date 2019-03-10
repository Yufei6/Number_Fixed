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
        using underlying_type = long;
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
            value = value >> (OtherFrac-Frac);
        else if (Frac-OtherFrac > 0)
            value = value << (Frac - OtherFrac);
        }
        
/*
* copy  assignment
*/
        fixed &operator=(const fixed &other){
            value = other.value;
            return *this;
        }

        template <std::size_t OtherInt, std::size_t OtherFrac>
        fixed &operator=(const fixed<OtherInt, OtherFrac> &other){
            if(OtherFrac - Frac > 0){
                value = other.value << (OtherFrac-Frac);
            }
            if(Frac - OtherFrac > 0){
                value = other.value >> (Frac-OtherFrac);
            }
            return *this;
        }

/*
* conversions
*/
        operator float()const{
            return (float)(value/(pow(2,fractional_part)));
        }

        operator double()const{
            return (double)(value/(pow(2,fractional_part)));
        }

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
            if(OtherFrac - Frac > 0){
                this->value = this->value + (other->value << (OtherFrac-Frac));
            }
            if(Frac - OtherFrac > 0){
                this->value = this->value + (other->value >> (OtherFrac-Frac));
            }
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
            if(OtherFrac - Frac > 0){
                this->value = this->value - (other->value << (OtherFrac-Frac));
            }
            if(Frac - OtherFrac > 0){
                this->value = this->value - (other->value >> (OtherFrac-Frac));
            }
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
            if(OtherFrac - Frac > 0){
                this->value = this->value * (other->value << (OtherFrac-Frac));
            }
            if(Frac - OtherFrac > 0){
                this->value = this->value * (other->value >> (OtherFrac-Frac));
            }
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
            if(OtherFrac - Frac > 0){
                this->value = this->value / (other->value << (OtherFrac-Frac));
            }
            if(Frac - OtherFrac > 0){
                this->value = this->value / (other->value >> (OtherFrac-Frac));
            }
            return *this;
        }
    };

/*
* arithmetic  operators
*/
    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    double operator+(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        double res=0;
        res=lhs.value/(pow(2,lhs.fractional_part)) + rhs.value/(pow(2,rhs.fractional_part));
        return res;
    }

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    double operator-(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        double res=0;
        res=lhs.value/(pow(2,lhs.fractional_part)) - rhs.value/(pow(2,rhs.fractional_part));
        return res;
    }

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    double operator*(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        double res=0;
        res=lhs.value/(pow(2,lhs.fractional_part)) * rhs.value/(pow(2,rhs.fractional_part));
        return res;
    }

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    double operator/(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        double res=0;
        res=lhs.value/(pow(2,lhs.fractional_part)) / rhs.value/(pow(2,rhs.fractional_part));
        return res;
    }

/*
* comparison  operators
*/
    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    bool operator==(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        return lhs.value/(pow(2,lhs.fractional_part)) == rhs.value/(pow(2,rhs.fractional_part));
    }

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    bool operator<(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        return lhs.value/(pow(2,lhs.fractional_part)) < rhs.value/(pow(2,rhs.fractional_part));
    }

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    bool operator>(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        return lhs.value/(pow(2,lhs.fractional_part)) > rhs.value/(pow(2,rhs.fractional_part));
    }

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    bool operator<=(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        return lhs.value/(pow(2,lhs.fractional_part)) <= rhs.value/(pow(2,rhs.fractional_part));
    }

    template <std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
    bool operator>=(fixed<I1, F1> lhs, fixed<I2, F2> rhs){
        return lhs.value/(pow(2,lhs.fractional_part)) >= rhs.value/(pow(2,rhs.fractional_part));
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
        static constexpr Fixed lowest(){
            Fixed res;
            return res;
        }

        static constexpr Fixed min(){
            Fixed res;
            return res;
        }

        static constexpr Fixed max(){
            Fixed res;
            return res;
        }

        static constexpr Fixed zero(){
            Fixed res;
            return res;
        }

        static constexpr Fixed one(){
            Fixed res;
            return res;
        }
        
        static constexpr Fixed pi(){
            Fixed res;
            return res;
        }
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
    std::ostream &operator<<(std::ostream &os, Fixed f){
        os << f.to_string(f);
    }
}

#endif //FIXED_FIXED_H
