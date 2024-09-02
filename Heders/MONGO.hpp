#include <bsoncxx/document/view.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/collection.hpp>
#include <mongocxx/database.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri-fwd.hpp>
#include <string>

class MongoTest
{
  private:
    mongocxx::instance instance_;
    mongocxx::client client_;
    mongocxx::database db_;
    mongocxx::collection coll_;

  public:
    MongoTest(const std::string& uri,const std::string& dbName,const std::string& dbColl);
    ~MongoTest();

    void inserDocument(bsoncxx::document::view& doc);
    static bool isValidUri(const std::string& uri);
};
