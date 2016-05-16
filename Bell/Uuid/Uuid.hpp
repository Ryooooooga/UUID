//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include "../ArrayView.hpp"

namespace Bell { namespace Uuid_ {

	/**
	 * @brief      UUID
	 */
	class Uuid
	{
		std::array<std::uint8_t, 16> uuid_;

	public:
		/**
		 * @brief      バージョン
		 */
		enum class Version
			: std::int32_t
		{
			Version1			= 1,
			Version2			= 2,
			Version3			= 3,
			Version4			= 4,
			Version5			= 5,

			TimeBased			= Version1,
			DceSecurity			= Version2,
			NameBasedMD5		= Version3,
			RandomNumberBased	= Version4,
			NameBasedSHA1		= Version5,
		};

		/**
		 * @brief      Uuid ctor
		 *
		 * @param[in]  ver   生成に使用するバージョン
		 */
		explicit Uuid(Version ver) noexcept;
	};

}}	//	namespace Bell::Uuid_
