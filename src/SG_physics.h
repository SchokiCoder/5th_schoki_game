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

#ifndef SG_PHYSICS_H
#define SG_PHYSICS_H

#include <SM_types.h>

typedef struct SG_FPoint SG_FPoint;
typedef struct SG_IPoint SG_IPoint;
typedef struct SG_FRect SG_FRect;
typedef struct SG_IRect SG_IRect;

bool_t SG_fpoint_within_frect(SG_FPoint * pt, SG_FRect * rect);

bool_t SG_ipoint_within_irect(SG_IPoint * pt, SG_IRect * rect);

bool_t SG_frect_within_frect(SG_FRect * a, SG_FRect * b);

bool_t SG_irect_within_irect(SG_IRect * a, SG_IRect * b);

#endif				// SG_PHYSICS_H
