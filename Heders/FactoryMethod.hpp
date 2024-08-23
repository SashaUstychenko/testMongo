#include <iostream>
#include <locale>
#include <memory>


namespace FACTORY_METHOD
{
  namespace TASK4 
  {
    class Message
    {
      public:
        virtual ~Message(){}
        virtual void send()const = 0;
        virtual void setPriority(int priority) = 0;
        virtual void setTemplate(const std::string& tmpl) = 0;
    };
    class SMS :public Message
    {
      private:
        int priority;
        std::string tmpl;
      public:
         void send() const override {
        std::cout << "Sending SMS with priority " << priority << " using template: " << tmpl << std::endl;
    }

    void setPriority(int p) override {
        priority = p;
    }

    void setTemplate(const std::string& t) override {
        tmpl = t;
    }
  };
  namespace TASK3
  {
    class User
    {
      public:
        virtual ~User(){}
        virtual void accessRights()const = 0;
    };
    class Admin :public User
    {
      public:
        void accessRights()const override
        {
          std::cout<<"Admin: full access"<<std::endl;
        }
    };
  class Moderator :public User
    {
      public:
        void accessRights()const override
        {
          std::cout<<"Moderator: full Limited"<<std::endl;
        }
    };
  class Guest :public User
    {
      public:
        void accessRights()const override
        {
          std::cout<<"Guest: view only"<<std::endl;
        }
    };
  class UserFactory
  {
    public:
     virtual ~UserFactory(){};
     virtual std::unique_ptr<User> createUser()const = 0;

  };
  class AdminFactory :public UserFactory
  {
    std::unique_ptr<User> createUser()const override
    {
      return std::make_unique<Admin>();
    }
  };
  class ModeratorFactory :public UserFactory
  {
    std::unique_ptr<User> createUser()const override
    {
      return std::make_unique<Moderator>();
    }
  };
  class GuestFactory :public UserFactory
  {
    std::unique_ptr<User> createUser()const override
    {
      return std::make_unique<Guest>();
    }
  };



  }

  namespace TASK2
  {
    class Document 
    {
      public:
        virtual ~Document(){}
        virtual void print()const = 0;
    };
    class PDF_Document :public Document
    {
      public:
        void print()const override
        {
          std::cout<<"Printing PDF document"<<std::endl;
        }

    };
   class WORD_Document :public Document
    {
      public:
        void print()const override
        {
          std::cout<<"Printing WORD document"<<std::endl;
        }

    };

   class DocumentFactory
   {
     public:
      virtual ~ DocumentFactory(){}
      virtual std::unique_ptr<Document> createDocument()const = 0;

   };
   class WORD_Document_Factory :public DocumentFactory
   {
     public:
       std::unique_ptr<Document>createDocument()const override
       {
         return std::make_unique<WORD_Document>();
       }
   };
   class PDF_Document_Factory :public DocumentFactory
   {
     public:
       std::unique_ptr<Document>createDocument()const override
       {
         return std::make_unique<PDF_Document>();
       }
   };
  }

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
