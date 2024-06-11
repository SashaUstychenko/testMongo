#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <iostream>
#include <bsoncxx/builder/stream/document.hpp>
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
}

