/*
 * schoki_game
 * Copyright (C) 2022  Andy Frank Schoknecht
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not see
 * <https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html>.
 */

#ifndef SG_TYPES_H
#define SG_TYPES_H

#include <SM_types.h>

typedef struct SG_FPoint {
	float x;
	float y;
} SG_FPoint;

typedef struct SG_IPoint {
	sl32_t x;
	sl32_t y;
} SG_IPoint;

typedef struct SG_UPoint {
	ul32_t x;
	ul32_t y;
} SG_UPoint;

typedef struct SG_FRect {
	float x;
	float y;
	float w;
	float h;
} SG_FRect;

typedef struct SG_IRect {
	sl32_t x;
	sl32_t y;
	sl32_t w;
	sl32_t h;
} SG_IRect;

typedef struct SG_URect {
	ul32_t x;
	ul32_t y;
	ul32_t w;
	ul32_t h;
} SG_URect;

#endif				// SG_TYPES_H
