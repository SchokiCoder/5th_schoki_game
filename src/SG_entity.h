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

#ifndef SG_ENTITY_H
#define SG_ENTITY_H

#include "SG_types.h"
#include <SM_types.h>

typedef struct SG_World SG_World;

typedef struct SG_EntityData
{
	char *name;
	ul32_t width;
	ul32_t height;
	float acceleration;
	float max_velocity;
	float decceleration;
	float jump_velocity;
} SG_EntityData ;

typedef struct SG_Entity
{
	ul32_t id;
    SG_FRect rect;
    float velocity_x, velocity_y;
    bool_t grounded;
} SG_Entity ;

/*
	Moves the entity one dimension at a time.
SM_bool Entity_move( Entity *ent, float *pos, float *velocity, float distance, World *world );
*/

#endif // SG_ENTITY_H
