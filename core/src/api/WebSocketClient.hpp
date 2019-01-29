// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from websocket_client.djinni

#ifndef DJINNI_GENERATED_WEBSOCKETCLIENT_HPP
#define DJINNI_GENERATED_WEBSOCKETCLIENT_HPP

#include <memory>
#include <string>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER) && _MSC_VER <= 1900
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class WebSocketConnection;

class WebSocketClient {
public:
    virtual ~WebSocketClient() {}

    virtual void connect(const std::string & url, const std::shared_ptr<WebSocketConnection> & connection) = 0;

    virtual void send(const std::shared_ptr<WebSocketConnection> & connection, const std::string & data) = 0;

    virtual void disconnect(const std::shared_ptr<WebSocketConnection> & connection) = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_WEBSOCKETCLIENT_HPP
