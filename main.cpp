#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include <string>
#include <iterator>

#include "bcrypt/BCrypt.hpp"

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>


#include <boost/filesystem.hpp>
#include <boost/asio.hpp>

namespace fs = boost::filesystem;
int main() {

  std::string password = "test";
	std::string hash = BCrypt::generateHash(password);

	std::cout << BCrypt::validatePassword(password,hash) << std::endl;
	std::cout << BCrypt::validatePassword("test1",hash) << std::endl;


   fs::path currentPath = fs::current_path();

    std::cout << "Поточний каталог: " << currentPath << std::endl;

    // Перебір файлів та папок у поточному каталозі
    std::cout << "Список файлів та папок у поточному каталозі:\n";
    for (const auto& entry : fs::directory_iterator(currentPath)) {
        std::cout << entry.path().filename() << std::endl;
    }

    // Перевірка, чи існує певний файл у поточному каталозі
    fs::path filePath = currentPath / "example.txt";
    if (fs::exists(filePath)) {
        std::cout << "Файл example.txt існує.\n";
    } else {
        std::cout << "Файл example.txt не знайдено.\n";
    }

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

