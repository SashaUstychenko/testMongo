#include <iostream>
#include <memory>


namespace FACTORY_METHOD
{


  namespace TASK1 
  {
    class Product
    {
      public:
        virtual ~Product() {}
        virtual void use()const = 0;
    };
    class ConcreteProductA :public Product
    {
      public:
        void use()const override
        {
          std::cout<<"using conreateProducA"<<std::endl;
        }
    };
    class ConcreteProductB :public Product
    {
      public:
        void use()const override
        {
          std::cout<<"using conreateProducB"<<std::endl;
        }
    };

    //abstact factory

    class Creator
    {
      public:
        virtual ~Creator(){};
        virtual std::unique_ptr<Product>factory_method()const = 0;

        void someOperation()const
        {
          std::unique_ptr<Product>product = factory_method();
          product->use();
        }


    };
    class ConcreteCreateA :public Creator
    {
      public:
        std::unique_ptr<Product>factory_method()const override
        {
          return std::make_unique<ConcreteProductA>();
        }

    };
    class ConcreteCreateB :public Creator
    {
      public:
        std::unique_ptr<Product>factory_method()const override
        {
          return std::make_unique<ConcreteProductB>();
        }

    };
  
  
  
  }


}
