// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from amount.djinni

#ifndef DJINNI_GENERATED_AMOUNT_HPP
#define DJINNI_GENERATED_AMOUNT_HPP

#include "../utils/optional.hpp"
#include <cstdint>
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

class BigInt;
struct Currency;
struct CurrencyUnit;
struct FormatRules;
struct Locale;

/**Class representing amount of transaction, output, inputs ... */
class LIBCORE_EXPORT Amount {
public:
    virtual ~Amount() {}

    /**
     *Get amount as a BitInt
     *@return BitInt
     */
    virtual std::shared_ptr<BigInt> toBigInt() = 0;

    /**
     *Get currency in which amount was computed
     *@return Currency object
     */
    virtual Currency getCurrency() = 0;

    /**
     *Get currency unit in which amount was computed
     *@return CurrencyUnit object
     */
    virtual CurrencyUnit getUnit() = 0;

    /**
     *Convert amount in another currency unit
     *@param CurrencyUnit object, target currency unit
     *@return Amount object, amount in target currency unit
     */
    virtual std::shared_ptr<Amount> toUnit(const CurrencyUnit & unit) = 0;

    /**TODO */
    virtual std::shared_ptr<Amount> toMagnitude(int32_t magnitude) = 0;

    /**
     *Get amount as string
     *@return string
     */
    virtual std::string toString() = 0;

    /**
     *Get amount as long
     *@reutrn 64 bits integer
     */
    virtual int64_t toLong() = 0;

    /**
     *Get amount as double
     *@return double
     */
    virtual double toDouble() = 0;

    /**TODO */
    virtual std::string format(const Locale & locale, const std::experimental::optional<FormatRules> & rules) = 0;

    static std::shared_ptr<Amount> fromHex(const Currency & currency, const std::string & hex);

    static std::shared_ptr<Amount> fromLong(const Currency & currency, int64_t value);
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_AMOUNT_HPP
