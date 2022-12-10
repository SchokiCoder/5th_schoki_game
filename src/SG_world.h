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

#ifndef SG_WORLD_H
#define SG_WORLD_H

#include <SM_string.h>
#include <SM_types.h>
#include <SDL_render.h>

typedef struct SG_Entity SG_Entity;

typedef struct SG_World {
	bool_t invalid;

	ul32_t block_size;
	ul32_t width;
	ul32_t height;
	ul32_t depth;
	ul32_t ***blocks;
	SDL_Texture ****block_textures;

	ul32_t ent_count;
	SG_Entity *entities;
} SG_World;

SG_World SG_World_new(const ul32_t block_size,
		      const ul32_t width,
		      const ul32_t height, const ul32_t depth);

SG_World SG_World_from_file(const char *filepath);

void SG_World_write(SG_World * world, const char *filepath);

void SG_World_clear(SG_World * world);

#endif				// SG_WORLD_H
