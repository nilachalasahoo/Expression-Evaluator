#include"ValueConverter.h"
void integer_conveter(){
    Integer converter;
    converter.takeInput();
    try{
        int result=converter.getResult();
        std::cout<<"The result of Expression is : "<<result;
    }catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
}
void decimal_conveter(){
    Decimal converter;
    converter.takeInput();
    try{
        double result=converter.getResult();
        std::cout<<"The result of Expression is : "<<result;
    }catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
}
int main(){
    std::cout<<"This is expression conveter to evaluate string expression to Integer or Decimal Number"<<std::endl;
    std::cout<<std::endl<<"1.Integer Number Expression"<<std::endl;
    std::cout<<"2.Decimal Number Expression"<<std::endl;
    int choice;
    std::cout<<"Enter your Choice for which type of conveter you want :";
    std::cin>>choice;
    while(choice!=1 && choice!=2){
        std::cout<<"Invalid Choice. Please enter a valid choice..."<<std::endl;
        std::cout<<"1.Integer Number Expression"<<std::endl;
        std::cout<<"2.Decimal Number Expression"<<std::endl;
        std::cout<<"Enter your Choice for which type of conveter you want :"<<std::endl;
        std::cin>>choice;
    }
    if(choice==1)
        integer_conveter();
    else
        decimal_conveter();
    
    return 0;
}

