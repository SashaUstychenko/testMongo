#include <iostream>
#include <string>

namespace Builder 
{
  namespace B1 
  {
    class Car
    {
      private:
        std::string engine;
        std::string body;
        std::string transmission;
        std::string interior;

      public:
        void setEngine(const std::string& engineType) { engine = engineType; }
        void setBody(const std::string& bodyType) { body = bodyType; }
        void setTransmission(const std::string& transmissionType) { transmission = transmissionType; }
        void setInterior(const std::string& interiorType) { interior = interiorType; }

        void showSpecifications() const 
        {
          std::cout << "Car Specifications:\n";
          std::cout << "Engine: " << engine << "\n";
          std::cout << "Body: " << body << "\n";
          std::cout << "Transmission: " << transmission << "\n";
          std::cout << "Interior: " << interior << "\n";
        }
    };

    class CarBuilder 
    {
      public:
        virtual ~CarBuilder() {}
        virtual void buildEngine() = 0;
        virtual void buildBody() = 0;
        virtual void buildTransmission() = 0;
        virtual void buildInterior() = 0;
        virtual Car* getCar() = 0;
    };
    
  }

}



