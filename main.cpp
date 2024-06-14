#include <bsoncxx/json.hpp>
<<<<<<< HEAD
#include <iterator>
=======
>>>>>>> 6da55aee34b570602d502dcbb34025608f34d10f
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <iostream>
#include <bsoncxx/builder/stream/document.hpp>
<<<<<<< HEAD
#include <string>
#include <boost/filesystem.hpp>
#include <bcrypt/bcrypt.h>

namespace fs = boost::filesystem;


int main() {

   std::string password = "mysecretpassword";
    std::string salt = BCrypt::generate_salt();
    std::string hashed_password = BCrypt::generate_hash(password, salt);

    std::cout << "Password: " << password << std::endl;
    std::cout << "Salt: " << salt << std::endl;
    std::cout << "Hashed Password: " << hashed_password << std::endl;

    bool password_is_valid = BCrypt::validate_password(password, hashed_password);
    std::cout << "Password is valid: " << (password_is_valid ? "Yes" : "No") << std::endl;

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
=======
int main() {
    mongocxx::instance instance{};
    mongocxx::client client{mongocxx::uri{"mongodb://127.0.0.1:27017/?directConnection=true&serverSelectionTimeoutMS=2000&appName=mongosh+2.2.6"}};

    auto db = client["SocialApp"];
    bsoncxx::document::value doc = bsoncxx::builder::stream::document{}
        << "name" << "MongoDB"
        << "type" << "database"
        << "count" << 1
        << "versions" << bsoncxx::builder::stream::open_array
            << "v3.2" << "v3.0" << "v2.6"
        << bsoncxx::builder::stream::close_array
        << "info" << bsoncxx::builder::stream::open_document
            << "x" << 203
            << "y" << 102
        << bsoncxx::builder::stream::close_document
        << bsoncxx::builder::stream::finalize;

    auto collection = db["testcollection"];
    collection.insert_one(doc.view());

    std::cout<<"Document inserted!" << std::endl;

    return 0;
>>>>>>> 6da55aee34b570602d502dcbb34025608f34d10f
}

