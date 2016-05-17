//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <array>

namespace Bell { namespace Uuids {

	/**
	 * @brief      UUID
	 */
	class Uuid
	{
		std::array<std::uint8_t, 16> uuid_;

	public:
		using value_type				= std::array<std::uint8_t, 16>::value_type;
		using pointer					= std::array<std::uint8_t, 16>::pointer;
		using const_pointer				= std::array<std::uint8_t, 16>::const_pointer;
		using reference					= std::array<std::uint8_t, 16>::reference;
		using const_reference			= std::array<std::uint8_t, 16>::const_reference;
		using iterator					= std::array<std::uint8_t, 16>::iterator;
		using const_iterator			= std::array<std::uint8_t, 16>::const_iterator;
		using reverse_iterator			= std::array<std::uint8_t, 16>::reverse_iterator;
		using const_reverse_iterator	= std::array<std::uint8_t, 16>::const_reverse_iterator;
		using size_type					= std::array<std::uint8_t, 16>::size_type;
		using difference_type			= std::array<std::uint8_t, 16>::difference_type;

		/**
		 * @brief      バージョン
		 */
		enum class Version
			: std::int32_t
		{
			Unknown				= -1,

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

		/**
		 * @brief      生成されたUUIDのバージョン
		 *
		 * @return     バージョン
		 */
		Version version() const noexcept;
	};

}}	//	namespace Bell::Uuid_
