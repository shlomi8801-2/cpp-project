#pragma once
#include "Screen.h"

struct Layout {
	const char** layout;
	int id;
};

namespace designs
{
	inline const char* room_1[] = {
		//0123456789012345678901234567890123456789012345678901234567890123456789012345678
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 0
		"W                                                                             W", // 1
		"W                                                                             W", // 2
		"W                                                                             W", // 3
		"W                            *******************                              W", // 4
		"W                           *********************                             W", // 5
		"W                                                                             W", // 6
		"W                            ******************                               W", // 7
		"W                           **********************                            W", // 8
		"W                                 ********                                    W", // 9
		"W                                                                             W", // 10
		"W                                                                             W", // 11
		"W                                                                             W", // 12
		"W                                                                             W", // 13
		"W                                                                             W", // 14
		"W                                                                             W", // 15
		"W                                                                             W", // 16
		"W                                                                             W", // 17
		"W                                                                             W", // 18
		"W                                                                             W", // 19
		"W                                                                             W", // 20
		"W                                                                             W", // 21
		"W                                                                             W", // 22
		"W                                                                             W", // 23
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"  // 24
	};
}

void getLayout(int id);
