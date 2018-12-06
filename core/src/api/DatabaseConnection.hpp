// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from database.djinni

#ifndef DJINNI_GENERATED_DATABASECONNECTION_HPP
#define DJINNI_GENERATED_DATABASECONNECTION_HPP

#include <memory>
#include <string>

namespace ledger { namespace core { namespace api {

class DatabaseBlob;
class DatabaseRowId;
class DatabaseStatement;

class DatabaseConnection {
public:
    virtual ~DatabaseConnection() {}

    virtual std::shared_ptr<DatabaseStatement> prepareStatement(const std::string & query, bool repeatable) = 0;

    virtual void begin() = 0;

    virtual void rollback() = 0;

    virtual void commit() = 0;

    virtual void close() = 0;

    virtual std::shared_ptr<DatabaseBlob> newBlob() = 0;

    virtual std::shared_ptr<DatabaseRowId> newRowId() = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_DATABASECONNECTION_HPP
