
#include <iostream>
#include <memory>

namespace AbstractFctory
{
  namespace AB_1
  {
    class Button 
    {
      public:
        virtual ~Button(){}
        virtual void render()const = 0;
    };
    class WindowsButton : public Button
    {
      public:
        void render() const override
        {
          std::cout<<"rndering a button in windows style"<<std::endl;
        }
    };
    class MacOSButton :public Button
    {
      public:
        void render() const override
        {
          std::cout<<"rndering a button in macOS  style"<<std::endl;
        }
    };   
  
    class GUIFactory
    {

      public:
        virtual ~GUIFactory(){}
        virtual std::unique_ptr<Button> createBtn()const = 0;

    };
    class WindowsFactory :public GUIFactory
    {
      public:
        std::unique_ptr<Button> createBtn() const override
        {
          return std::make_unique<WindowsButton>();           
        }
    };

    class MacOSFactory :public GUIFactory
    {
      public:
        std::unique_ptr<Button> createBtn()const override
        {
          return std::make_unique<MacOSButton>();
        }
    };

    void renderUI(const GUIFactory& factory)
    {
      auto button = factory.createBtn();
      button->render();
    }
  }

}
