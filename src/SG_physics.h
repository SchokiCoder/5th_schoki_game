/*
	schoki_game
	Copyright (C) 2022	Andy Frank Schoknecht

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef SG_PHYSICS_H
#define SG_PHYSICS_H

#include <SM_types.h>

typedef struct SG_FPoint SG_FPoint;
typedef struct SG_FRect SG_FRect;

bool_t SG_point_within_box( SG_FPoint *pt, SG_FRect *box );

bool_t SG_box_within_box( SG_FRect *box_1, SG_FRect *box_2 );

#endif // SG_PHYSICS_H
