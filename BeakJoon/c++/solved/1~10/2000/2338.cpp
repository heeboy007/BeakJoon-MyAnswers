#include<iostream>
#include<algorithm>

   /*
    * Made by heeboy007.
    * I made this because I didn't want to rewrite the entire code every time I use bignum.
    */

class MyBigNumber{

private:
    std::string real_number;
    bool is_minus;
    bool is_inversed;

    std::string add_string(std::string &s1, std::string &s2){
        int prev = 0, s1_size = s1.length(), s2_size = s2.length();
        int max_iter = s1_size > s2_size ? s1_size : s2_size;
        std::string added = "";
        
        for(int i = 0; i < max_iter || prev; i++){
            char a = i < s1_size ? s1[i] : '0' , b = i < s2_size ? s2[i] : '0';
            
            int temp = (int)(a + b - 96) + prev;
            added += (char)(temp % 10 + 48);
            prev = temp / 10;
        }
        return std::move(added);
    }

    std::string sub_string(std::string &s1, std::string &s2){
        int prev = 0, s1_size = s1.length(), s2_size = s2.length();
        int max_iter = s1_size > s2_size ? s1_size : s2_size;
        if(s1 == s2)
            return "0";
        std::string subbed = "";
        for(int i = 0; i < max_iter || prev; i++){
            char a = i < s1_size ? s1[i] : '0' , b = i < s2_size ? s2[i] : '0';
            
            int temp = (int)(a - b) + prev;
            subbed += (char)((temp + 10) % 10 + 48);
            prev = temp < 0 ? -1 : 0;
        }
        int zeros = 0;
        for(int i = (subbed.length() - 1); (subbed[i] == '0'); i--)
            zeros++;
        if(zeros)
            subbed = subbed.substr(0, subbed.length() - zeros);
        return std::move(subbed);
    }
    
    std::string mul_single_digit(std::string &base, int mul, int digit){
        std::string mul_single = "";
        int prev = 0, s1_size = base.length();
        while(digit--)
            mul_single += '0';
        for(int i = 0; i < s1_size || prev; i++){
            char a = i < s1_size ? base[i] : '0';
            
            int temp = (int)(a - 48) * mul + prev;
            mul_single += (char)(temp % 10 + 48);
            prev = temp / 10;
        }
        return std::move(mul_single);
    }

    std::string mul_string(std::string &s1, std::string &s2){
        std::string multi = "0", temp;
        int s2_size = s2.length();
        
        for(int i = 0; i < s2_size; i++){
            int mul = (int)(s2[i] - 48);
            if(mul){ //skip 0, no need.
                temp = mul_single_digit(s1, mul, i);
                multi = add_string(multi, temp);
            }
        }
        return std::move(multi);
    }
    /*
    std::string div_string(){

    }

    std::string mod_string(){

    }*/
    
    //some state fucntions
    void to_inverse_state(){
        if(!is_inversed){
            std::reverse(real_number.begin(), real_number.end());
            is_inversed = true;
        }
    }

    void to_normal_state(){
        if(is_inversed){
            std::reverse(real_number.begin(), real_number.end());
            is_inversed = false;
        }
    }

public:

    bool operator< (MyBigNumber &other){
        if(is_minus == other.is_minus){
            int size_this = real_number.length(), size_other = other.length();
            if(size_this == size_other){
                to_normal_state();
                other.to_normal_state();
                std::string other_string = other.real_number;
                for(int i = 0; i < size_this; i++){
                    if(real_number[i] != other_string[i]){
                        bool res = real_number[i] < other_string[i];
                        return is_minus ? !res : res;
                    }
                }
                return false; //same
            } else{
                if(is_minus)
                    return !(size_this < size_other);
                else
                    return (size_this < size_other);
            }
        } else {
            if(is_zero() && other.is_zero())
                return false;
            else
                return is_minus;
        }
    }

    bool operator<= (MyBigNumber &other){
        if(is_minus == other.is_minus){
            int size_this = real_number.length(), size_other = other.length();
            if(size_this == size_other){
                to_normal_state();
                other.to_normal_state();
                std::string other_string = other.real_number;
                for(int i = 0; i < size_this; i++){
                    if(real_number[i] != other_string[i]){
                        bool res = real_number[i] < other_string[i];
                        return is_minus ? !res : res;
                    }
                }
                return true; //same
            } else{
                if(is_minus)
                    return !(size_this < size_other);
                else
                    return (size_this < size_other);
            }
        } else {
            if(is_zero() && other.is_zero())
                return true;
            else
                return is_minus;
        }
    }

    bool operator> (MyBigNumber &other){
        return other.operator<(*this);
    }

    bool operator>= (MyBigNumber &other){
        return other.operator<=(*this);
    }

    MyBigNumber operator+ (MyBigNumber other){
        to_inverse_state();
        other.to_inverse_state();
        if(is_minus == other.get_is_minus()){
            return MyBigNumber(add_string(real_number, other.real_number), is_minus, true);
        } else {
            MyBigNumber abs_this(real_number, false, true), abs_other(other.real_number, false, true);
            std::string abs_str;
            bool pm;
            if(abs_this > abs_other){
                abs_str = sub_string(real_number, other.real_number);
                pm = is_minus;
            } else {
                abs_str = sub_string(other.real_number, real_number);
                pm = other.get_is_minus();
            }
            return MyBigNumber(abs_str, pm, true);
        }
    }

    MyBigNumber operator- (MyBigNumber other){
        to_inverse_state();
        other.to_inverse_state();
        if(is_minus != other.get_is_minus()){
            return MyBigNumber(add_string(real_number, other.real_number), is_minus, true);
        } else {
            MyBigNumber abs_this(real_number, false, true), abs_other(other.real_number, false, true);
            std::string abs_str;
            bool pm;
            if(abs_this > abs_other){
                abs_str = sub_string(real_number, other.real_number);
                pm = is_minus;
            } else {
                abs_str = sub_string(other.real_number, real_number);
                pm = !other.get_is_minus();
            }
            return MyBigNumber(abs_str, pm, true);
        }
    }

    MyBigNumber operator* (MyBigNumber other){
        if(is_zero() || other.is_zero()){
            return MyBigNumber();
        }

        to_inverse_state();
        other.to_inverse_state();
        return MyBigNumber(mul_string(real_number, other.real_number), (is_minus != other.is_minus), true);
    }

    //equal to making a copy
    void operator= (MyBigNumber &other){
        is_minus = other.is_minus;
        is_inversed = other.is_inversed;
        real_number = other.real_number;
    }

    //utils
    int length(){
        return real_number.length();
    }

    bool is_zero(){
        return real_number == "0";
    }

    void set_with_string(std::string number){
        if(is_minus = (number[0] == '-'))
            number.erase(number.begin());
        real_number = number;
        is_inversed = false;
    }

    //print with cout
    friend std::ostream& operator<<(std::ostream& os, const MyBigNumber output){
        if(output.real_number == "0"){
            os << '0';
            return os;
        }
        if(output.is_minus)
            os << '-';
        std::string num = output.real_number;
        if(output.is_inversed)
            std::reverse(num.begin(), num.end());
        os << num;
        return os;
    }

    //getter
    std::string get_real_number(){ return real_number; }
    bool get_is_minus(){ return is_minus; }
    bool get_is_inversed(){ return is_inversed; }

    //constuctors
    MyBigNumber() : real_number("0"), is_minus(false), is_inversed(true) { }
    MyBigNumber(std::string number){ set_with_string(number); }
    MyBigNumber(std::string number, bool minus, bool inv) : real_number(number), is_minus(minus), is_inversed(inv) { }

};

int main(){
    std::string number1, number2;
    std::cin >> number1 >> number2;
    MyBigNumber cal1(number1), cal2(number2);
    std::cout << cal1 + cal2 << '\n';
    std::cout << cal1 - cal2 << '\n';
    std::cout << cal1 * cal2 << '\n';
}