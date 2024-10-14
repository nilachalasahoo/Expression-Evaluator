template<class T>
class Converter{
    public:
        virtual void takeInput()=0;
        virtual T getValue(int &st)=0;
        virtual T eval(T value1,T value2,char op)=0;
        virtual T getResult()=0;
};
