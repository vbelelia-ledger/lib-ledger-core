/*
 *
 * TransactionParser
 * ledger-core
 *
 * Created by Pierre Pollastri on 27/03/2017.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
#pragma once

#include "../../../../collections/collections.hpp"
#include <cstdio>
#include <cstdint>
#include "../../../../net/HttpClient.hpp"
#include "BlockParser.hpp"
#include <rapidjson/reader.h>
#include <stack>
#include "InputParser.hpp"
#include "OutputParser.hpp"
#include <wallet/NetworkTypes.hpp>

namespace ledger {
    namespace core {
        namespace bitcoin {
            class TransactionParser {
            public:
                typedef BitcoinLikeNetwork::Transaction Result;

                TransactionParser(std::string& lastKey);
                void init(BitcoinLikeNetwork::Transaction* transaction);
                bool Null();
                bool Bool(bool b);
                bool Int(int i);
                bool Uint(unsigned i);
                bool Int64(int64_t i);
                bool Uint64(uint64_t i);
                bool Double(double d);
                bool RawNumber(const rapidjson::Reader::Ch* str, rapidjson::SizeType length, bool copy);
                bool String(const rapidjson::Reader::Ch* str, rapidjson::SizeType length, bool copy);
                bool StartObject();
                bool Key(const rapidjson::Reader::Ch* str, rapidjson::SizeType length, bool copy);
                bool EndObject(rapidjson::SizeType memberCount);
                bool StartArray();
                bool EndArray(rapidjson::SizeType elementCount);

            private:
                std::string& _lastKey;
                BitcoinLikeNetwork::Transaction* _transaction;
                std::stack<std::string> _hierarchy;
                uint32_t _arrayDepth;
                BlockParser _blockParser;
                InputParser _inputParser;
                OutputParser _outputParser;
            };
        }
    }
}
