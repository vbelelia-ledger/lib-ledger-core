// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ethereum_like_wallet.djinni

#ifndef DJINNI_GENERATED_ETHEREUMLIKETRANSACTIONBUILDER_HPP_JNI_
#define DJINNI_GENERATED_ETHEREUMLIKETRANSACTIONBUILDER_HPP_JNI_

#include "../../api/EthereumLikeTransactionBuilder.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class EthereumLikeTransactionBuilder final : ::djinni::JniInterface<::ledger::core::api::EthereumLikeTransactionBuilder, EthereumLikeTransactionBuilder> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::EthereumLikeTransactionBuilder>;
    using CppOptType = std::shared_ptr<::ledger::core::api::EthereumLikeTransactionBuilder>;
    using JniType = jobject;

    using Boxed = EthereumLikeTransactionBuilder;

    ~EthereumLikeTransactionBuilder();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<EthereumLikeTransactionBuilder>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<EthereumLikeTransactionBuilder>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    EthereumLikeTransactionBuilder();
    friend ::djinni::JniClass<EthereumLikeTransactionBuilder>;
    friend ::djinni::JniInterface<::ledger::core::api::EthereumLikeTransactionBuilder, EthereumLikeTransactionBuilder>;

};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_ETHEREUMLIKETRANSACTIONBUILDER_HPP_JNI_
