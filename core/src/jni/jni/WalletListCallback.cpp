// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#include "WalletListCallback.hpp"  // my header
#include "Error.hpp"
#include "Marshal.hpp"
#include "Wallet.hpp"

namespace djinni_generated {

WalletListCallback::WalletListCallback() : ::djinni::JniInterface<::ledger::core::api::WalletListCallback, WalletListCallback>() {}

WalletListCallback::~WalletListCallback() = default;

WalletListCallback::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

WalletListCallback::JavaProxy::~JavaProxy() = default;

void WalletListCallback::JavaProxy::onCallback(const std::experimental::optional<std::vector<std::shared_ptr<::ledger::core::api::Wallet>>> & c_result, const std::experimental::optional<::ledger::core::api::Error> & c_error) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::WalletListCallback>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onCallback,
                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::List<::djinni_generated::Wallet>>::fromCpp(jniEnv, c_result)),
                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni_generated::Error>::fromCpp(jniEnv, c_error)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
