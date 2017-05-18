// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#include "I32Callback.hpp"  // my header
#include "Error.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

I32Callback::I32Callback() : ::djinni::JniInterface<::ledger::core::api::I32Callback, I32Callback>() {}

I32Callback::~I32Callback() = default;

I32Callback::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

I32Callback::JavaProxy::~JavaProxy() = default;

void I32Callback::JavaProxy::onCallback(std::experimental::optional<int32_t> c_result, const std::experimental::optional<::ledger::core::api::Error> & c_error) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::I32Callback>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onCallback,
                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::I32>::fromCpp(jniEnv, c_result)),
                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni_generated::Error>::fromCpp(jniEnv, c_error)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated