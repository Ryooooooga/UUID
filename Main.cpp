//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "Bell/Uuids/Uuid.hpp"

int main() {
	for (int i = 0; i < 16; i++)
	{
		Bell::Uuids::Uuid { Bell::Uuids::Uuid::Version::RandomNumberBased };
	}
}
