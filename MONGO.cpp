
#include "Heders/MONGO.hpp"
#include "bsoncxx/document/view-fwd.hpp"
#include "mongocxx/client-fwd.hpp"
#include "mongocxx/client.hpp"
#include "mongocxx/instance.hpp"
#include "mongocxx/uri-fwd.hpp"
#include <exception>
#include <stdexcept>
#include <string>

MongoTest::MongoTest(const std::string& uri,const std::string& dbName,const std::string& dbColl)
  :instance_(),//ініціалізуємо інстансію MongoDb
   client_(mongocxx::uri(uri)),//підключеннядо сервера
   db_(client_[dbName]),//вибір  бази даних
   coll_(db_[dbColl])   //вибір колекції
{
  if (!isValidUri(uri)) 
  {
    throw std::invalid_argument("Invalid MongoDB Uri");
  }
} 

MongoTest::~MongoTest()
{ }

void MongoTest::inserDocument(bsoncxx::document::view& doc)
{
  coll_.insert_one(doc);
}
bool MongoTest::isValidUri(const std::string &uri)
{
  try
  { 
    mongocxx::client testClient{mongocxx::uri{uri}};
    return true;
  } catch (std::exception& e)
  {
    std::cerr<<"Failed to conect to MongoDB"  <<e.what()<<std::endl;
    return false;
  }
}
 



