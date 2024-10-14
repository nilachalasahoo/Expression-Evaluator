#include <iostream>
#include<string>
#include"Converter.h"
#include"Stack.h"
class Integer:public Converter<int>{
   private:
      std::string expression_string;
      int length;
    public:
      void takeInput();
      int getValue(int &st);
      int eval(int value1,int value2,char op);
      int getResult();
};

void Integer::takeInput(){
   std::cout<<"Enter an valid expression string to evaluate result : ";
   std::cin.ignore();
   getline(std::cin,expression_string);
   length=expression_string.length();
}
int Integer::getValue(int &st){
   int value=0;
   while(st<length){
      char ch=expression_string[st];
      if(ch<'0'||ch>'9')
         return value;
      value=value*10+(ch-48);
      st++;
   }
   return value;
}
int Integer::eval(int value1,int value2,char op){
   if(op=='+') return value1+value2;
   else if(op=='-') return value1-value2;
   else if(op=='*') return value1*value2;
   else if(op=='/') return value1/value2;
   return 0;
}
int Integer::getResult(){
    Stack<int> values;
    Stack<char> operators;
    bool occure_number=false;
    for(int st=0;st<length;st++){
        char ch=expression_string[st];
        if(ch>='0'&&ch<='9'){
            int value=getValue(st);
            values.push(value);
            st--;
            occure_number=true;
        }else if(occure_number&&(ch=='*'||ch=='/')){
            occure_number=false;
            if(!operators.empty()&&(operators.top()=='*'||operators.top()=='/')){
                int value=eval(values.pop(),values.pop(),operators.pop());
                values.push(value);
            }
            operators.push(ch);
        }else if(occure_number&&(ch=='+'||ch=='-')){
            occure_number=false;
            while(!operators.empty()){
                int value=eval(values.pop(),values.pop(),operators.pop());
                values.push(value);
            }
            operators.push(ch);
        }else{
            throw std::runtime_error("This is a wrong Expression...");
        }
    }
    int result=values.pop();
    while(!operators.empty()){
        if(values.empty())
            throw std::runtime_error("This is a wrong Expression...");
        result=eval(values.pop(),result,operators.pop());
    }
    return result;
}



class Decimal:public Converter<double>{
   private:
      std::string expression_string;
      int length;
    public:
      void takeInput();
      double getValue(int &st);
      double eval(double value1,double value2,char op);
      double getResult();
};

void Decimal::takeInput(){
   std::cout<<"Enter an valid expression string to evaluate result : ";
   std::cin.ignore();
   getline(std::cin,expression_string);
   length=expression_string.length();
}
double Decimal::getValue(int &st){
   double value=0;
   while(st<length){
      char ch=expression_string[st];
      if(ch<'0'||ch>'9'){
         if(ch=='.')
            break;
         return value;
      }
      value=value*10+(ch-48);
      st++;
   }
   st++;
   double div=10;
   while(st<length){
      char ch=expression_string[st];
      if(ch<'0'||ch>'9')
         return value;
      value=value+(ch-48)/div;
      div=div*10;
      st++;
   }
   return value;
}
double Decimal::eval(double value1,double value2,char op){
   if(op=='+') return value1+value2;
   else if(op=='-') return value1-value2;
   else if(op=='*') return value1*value2;
   else if(op=='/') return value1/value2;
   return 0;
}
double Decimal::getResult(){
   Stack<double> values;
    Stack<char> operators;
    bool occure_number=false;
    for(int st=0;st<length;st++){
        char ch=expression_string[st];
        if(ch>='0'&&ch<='9'){
            double value=getValue(st);
            values.push(value);
            st--;
            if(expression_string[st]=='.')
               throw std::runtime_error("This is a wrong Expression...");
            occure_number=true;
        }else if(occure_number&&(ch=='*'||ch=='/')){
            occure_number=false;
            if(!operators.empty()&&(operators.top()=='*'||operators.top()=='/')){
                double value=eval(values.pop(),values.pop(),operators.pop());
                values.push(value);
            }
            operators.push(ch);
        }else if(occure_number&&(ch=='+'||ch=='-')){
            occure_number=false;
            while(!operators.empty()){
                double value=eval(values.pop(),values.pop(),operators.pop());
                values.push(value);
            }
            operators.push(ch);
        }else{
            throw std::runtime_error("This is a wrong Expression...");
        }
    }
    double result=values.pop();
    while(!operators.empty()){
        if(values.empty())
            throw std::runtime_error("This is a wrong Expression...");
        result=eval(values.pop(),result,operators.pop());
    }
    return result;
}
