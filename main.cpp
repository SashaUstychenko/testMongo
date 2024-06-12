#include <bsoncxx/json.hpp>
#include <iterator>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <iostream>
#include <bsoncxx/builder/stream/document.hpp>
#include <string>

int main() {


  std::string  name;
  int  age;
  mongocxx::instance instance{};
  mongocxx::client client
  {
    mongocxx::uri{"mongodb://127.0.0.1:27017/?directConnection=true&serverSelectionTimeoutMS=2000&appName=mongosh+2.2.6"}
  };
  auto collection = client["SocialApp"]["testcollection"];
  int count =0;
  while(count!=1)
  {
    count++;

  std::cout<<"Input name"<<std::endl;
  std::cin>>name;
  std::cout<<"Input age"<<std::endl;
  std::cin>>age;

  bsoncxx::builder::stream::document document{}; 
  document <<"name"<<name
           <<"age"<<age;
  collection.insert_one(document.view());
  std::cout<<"Document inserted"<<std::endl;
  }


  return 0;
}

