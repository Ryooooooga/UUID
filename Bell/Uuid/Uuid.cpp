//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include <random>
#include <cassert>
#include "Uuid.hpp"

namespace Bell { namespace Uuid_ {

	namespace {

		//	version 4 乱数による生成
		void generateRandom(std::array<std::uint8_t, 16>& uuid)
		{
			thread_local std::mt19937 mt { std::random_device()() };

			std::uint32_t v0 = mt();
			std::uint32_t v1 = mt();
			std::uint32_t v2 = mt();
			std::uint32_t v3 = mt();

			uuid[ 0] = static_cast<std::uint8_t>((v0 >>  0) & 0xff);
			uuid[ 1] = static_cast<std::uint8_t>((v0 >>  8) & 0xff);
			uuid[ 2] = static_cast<std::uint8_t>((v0 >> 16) & 0xff);
			uuid[ 3] = static_cast<std::uint8_t>((v0 >> 24) & 0xff);
			uuid[ 4] = static_cast<std::uint8_t>((v1 >>  0) & 0xff);
			uuid[ 5] = static_cast<std::uint8_t>((v1 >>  8) & 0xff);
			uuid[ 6] = static_cast<std::uint8_t>((v1 >> 16) & 0x0f | 0x40);
			uuid[ 7] = static_cast<std::uint8_t>((v1 >> 24) & 0xff);
			uuid[ 8] = static_cast<std::uint8_t>((v2 >>  0) & 0xbf | 0x80);
			uuid[ 9] = static_cast<std::uint8_t>((v2 >>  8) & 0xff);
			uuid[10] = static_cast<std::uint8_t>((v2 >> 16) & 0xff);
			uuid[11] = static_cast<std::uint8_t>((v2 >> 24) & 0xff);
			uuid[12] = static_cast<std::uint8_t>((v3 >>  0) & 0xff);
			uuid[13] = static_cast<std::uint8_t>((v3 >>  8) & 0xff);
			uuid[14] = static_cast<std::uint8_t>((v3 >> 16) & 0xff);
			uuid[15] = static_cast<std::uint8_t>((v3 >> 24) & 0xff);
		}

	}

	//	Uuid ctor
	Uuid::Uuid(Version ver) noexcept
	{
		switch (ver)
		{
		case Version::RandomNumberBased:
			generateRandom(uuid_);
			break;

		default:
			assert(false && "unknown version");
			break;
		}
	}


}}	//	namespace Bell::Uuid_
