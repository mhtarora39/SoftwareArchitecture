#include <stack>
#include <unordered_map>
#include <exception>
#include <iostream>


class Calculator {
    enum OPS {
        MINUS = 1,
        PLUS = 2,
        MUL = 3,
        DIV = 4
    };
    
    int op_order(char op) {
       return static_cast<int>(order[op]);
    }
    

    bool add_operator(char op) {
        if(ops.size() > 0 && op_order(ops.front()) > op_order(op)) {
           return false;  
        }
        ops.push_back(op);
        return true;
    }

    void add_number(char num) {

        nums.push_back(to_number(num));
    }
    
    float to_number(char c) { return float(c - '0');}

    float eval_helper(float num1, float num2 , char op) {
        if(op == '-') { return num1 - num2;}
        if(op == '+') {return num1 + num2;}
        if(op == '*') {return num1*num2;}
        if(op == '/') {return num1 / num2;}
    
        throw std::runtime_error(op + " is in supported. ");

    }
    
protected:
    void init_eq(std::string& equ) {
        // 1 + 5 / 2
        for(int i = 0; i < equ.size(); i++) {
            if(i%2 == 0) {
              add_number(equ[i]);
            }

            else {
               if(!add_operator(equ[i])) {
                  auto last_ele = nums.back();
                  nums.pop_back();
                  auto res = eval_helper(last_ele,to_number(equ[i+1]),equ[i]);
                  nums.push_back(res);
               }
            } 
        }
    }

    std::deque<char> ops;
    std::deque<float> nums;
    std::unordered_map<char,OPS> order;


public:

    Calculator(std::string& equ) {
      order['-'] = OPS::MINUS;
      order['+'] = OPS::PLUS;
      order['*'] = OPS::MUL;
      order['/'] = OPS::DIV;
      init_eq(equ);
    }
    
    int eval() {
        int res = 0;
        while(ops.size() > 0) {
           auto op = ops.back();
           auto num1 = nums.back();
           nums.pop_back();
           auto num2 = nums.back();
           nums.pop_back();
           res = eval_helper(num1,num2,op);
           ops.pop_back();
           nums.push_back(res);
        }
        return res;

    }
};


int main() {
    std::string eq1 = "1+6/4";
    std::string eq2 = "8/2+1";
    auto calc1 =  Calculator(eq1);
    auto calc2 =  Calculator(eq2);

    std::cout << " Answer of " << eq1 << " : "<< calc1.eval()<< std::endl;
    std::cout << " Answer of " << eq2 << " : "<< calc2.eval()<< std::endl; 
}
