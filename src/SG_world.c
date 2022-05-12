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

#include <stdio.h>
#include <stdlib.h>
#include "SG_entity.h"
#include "SG_world.h"

void SG_World_allocate( SG_World *world )
{
	world->blocks = malloc(world->width * sizeof(ul32_t**));
	world->block_textures = malloc(world->width * sizeof(SDL_Texture***));

	for (size_t x = 0; x < world->width; x++)
	{
		world->blocks[x] = malloc(world->height * sizeof(ul32_t*));
		world->block_textures[x] = malloc(world->height * sizeof(SDL_Texture**));

		for (size_t y = 0; y < world->height; y++)
		{
			world->blocks[x][y] = malloc(world->depth * sizeof(ul32_t));
			world->block_textures[x][y] = malloc(world->depth * sizeof(SDL_Texture*));
		}
	}

	world->entities = malloc(world->ent_count * sizeof(SG_Entity));
}

SG_World SG_World_new(
	const ul32_t block_size,
	const ul32_t width,
	const ul32_t height,
	const ul32_t depth )
{
	SG_World world = {
		.invalid = FALSE,
		.block_size = block_size,
		.width = width,
		.height = height,
		.depth = depth,
		.ent_count = 1,
	};

	// allocate
	SG_World_allocate(&world);

	return world;
}

SG_World SG_World_from_file( const char *filepath )
{
	SG_World world = {
		.invalid = FALSE,
	};
	FILE *f;

	// open file
	f = fopen(filepath, "r");

	if (f == NULL)
	{
		world.invalid = TRUE;
		return world;
	}

	// read header
	fread(&world.block_size, sizeof(world.block_size), 1, f);
	fread(&world.width, sizeof(world.width), 1, f);
	fread(&world.height, sizeof(world.height), 1, f);
	fread(&world.depth, sizeof(world.depth), 1, f);
	fread(&world.ent_count, sizeof(world.ent_count), 1, f);

	// allocate for blocks
	SG_World_allocate(&world);

	// read blocks
	for (ul32_t x = 0; x < world.width; x++)
		for (ul32_t y = 0; y < world.height; y++)
			for (ul32_t z = 0; z < world.depth; z++)
				fread(&world.blocks[x][y][z], sizeof(world.blocks[x][y][z]), 1, f);

	// read entitites
	for (size_t i = 0; i < world.ent_count; i++)
	{
		fread(&world.entities[i].id, sizeof(world.entities[i].id), 1, f);
		fread(&world.entities[i].rect.x, sizeof(world.entities[i].rect.x), 1, f);
		fread(&world.entities[i].rect.y, sizeof(world.entities[i].rect.y), 1, f);
		fread(&world.entities[i].rect.w, sizeof(world.entities[i].rect.w), 1, f);
		fread(&world.entities[i].rect.h, sizeof(world.entities[i].rect.h), 1, f);
		fread(&world.entities[i].grounded, sizeof(world.entities[i].grounded), 1, f);
		fread(&world.entities[i].velocity_x, sizeof(world.entities[i].velocity_x), 1, f);
		fread(&world.entities[i].velocity_y, sizeof(world.entities[i].velocity_y), 1, f);
	}

	fclose(f);

	return world;
}

void SG_World_write( SG_World *world, const char *filepath )
{
	FILE *f;

	// open file
	f = fopen(filepath, "w");

	// if file did not open, set flag and stop
	if (f == NULL)
	{
		world->invalid = TRUE;
		return;
	}

	// write header
	fwrite(&world->block_size, sizeof(world->block_size), 1, f);
	fwrite(&world->width, sizeof(world->width), 1, f);
	fwrite(&world->height, sizeof(world->height), 1, f);
	fwrite(&world->depth, sizeof(world->depth), 1, f);
	fwrite(&world->ent_count, sizeof(world->ent_count), 1, f);

	// write blocks
    for (ul32_t x = 0; x < world->width; x++)
    	for (ul32_t y = 0; y < world->height; y++)
    		for (ul32_t z = 0; z < world->depth; z++)
				fwrite(&world->blocks[x][y][z], sizeof(world->blocks[x][y][z]), 1, f);

    // write entities
    for (size_t i = 0; i < world->ent_count; i++)
    {
    	fwrite(&world->entities[i].id, sizeof(world->entities[i].id), 1, f);
    	fwrite(&world->entities[i].rect.x, sizeof(world->entities[i].rect.x), 1, f);
    	fwrite(&world->entities[i].rect.y, sizeof(world->entities[i].rect.y), 1, f);
    	fwrite(&world->entities[i].rect.w, sizeof(world->entities[i].rect.w), 1, f);
    	fwrite(&world->entities[i].rect.h, sizeof(world->entities[i].rect.h), 1, f);
    	fwrite(&world->entities[i].grounded, sizeof(world->entities[i].grounded), 1, f);
		fwrite(&world->entities[i].velocity_x, sizeof(world->entities[i].velocity_x), 1, f);
		fwrite(&world->entities[i].velocity_y, sizeof(world->entities[i].velocity_y), 1, f);
    }

    fclose(f);
}

void SG_World_clear( SG_World *world )
{
	for (ul32_t i = 0; i < world->width; i++)
	{
		free(world->blocks[i]);
		free(world->block_textures[i]);
	}

	free(world->blocks);
	free(world->block_textures);

	free(world->entities);
}
