// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from emitter.djinni

#include "EventReceiver.hpp"  // my header
#include "Event.hpp"

namespace djinni_generated {

EventReceiver::EventReceiver() : ::djinni::JniInterface<::ledger::core::api::EventReceiver, EventReceiver>() {}

EventReceiver::~EventReceiver() = default;

EventReceiver::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

EventReceiver::JavaProxy::~JavaProxy() = default;

void EventReceiver::JavaProxy::onEvent(const std::shared_ptr<::ledger::core::api::Event> & c_event) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::EventReceiver>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onEvent,
                           ::djinni::get(::djinni_generated::Event::fromCpp(jniEnv, c_event)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated