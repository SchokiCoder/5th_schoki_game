
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

#include "SG_world.h"
#include "SG_entity.h"
#include <stdio.h>

int main()
{
	// write world
	SG_World write_world = SG_World_new(32, 16, 16, 3);

	write_world.blocks[0][0][0] = 0;
	write_world.blocks[0][0][1] = 1;
	write_world.blocks[0][1][0] = 2;
	write_world.blocks[0][1][1] = 3;
	write_world.blocks[1][0][0] = 4;
	write_world.blocks[1][0][1] = 5;
	write_world.blocks[1][1][0] = 6;
	write_world.blocks[1][1][1] = 7;

	write_world.entities[0].id = 69;
	write_world.entities[0].grounded = TRUE;
	write_world.entities[0].velocity_x = 0.0f;
	write_world.entities[0].velocity_y = 0.0f;
	write_world.entities[0].rect.x = 150;
	write_world.entities[0].rect.y = 200;
	write_world.entities[0].rect.w = 60;
	write_world.entities[0].rect.h = 20;

	SG_World_write(&write_world, "world.wld");

	// read
	SG_World read_world = SG_World_from_file("world.wld");

	if (read_world.invalid)
	{
		printf("ERROR: World not read.\n");
		return 1;
	}

	// compare
	if (read_world.block_size != write_world.block_size ||
		read_world.width != write_world.width ||
		read_world.height != write_world.height ||
		read_world.depth != write_world.depth ||
		read_world.ent_count != write_world.ent_count)
	{
        printf("ERROR: World header incorrect.\n");
        SG_World_clear(&read_world);
        SG_World_clear(&write_world);
		return 2;
	}

	for (ul32_t x = 0; x < read_world.width; x++)
	{
		for (ul32_t y = 0; y < read_world.height; y++)
		{
			for (ul32_t z = 0; z < read_world.depth; z++)
			{
				//printf("x: %u, y: %u, z: %u -> %lu\n", x, y, z, read_world.blocks[x][y][z]);

				if (read_world.blocks[x][y][z] != write_world.blocks[x][y][z])
				{
					printf("ERROR: World blocks differ.\n");
					SG_World_clear(&read_world);
        			SG_World_clear(&write_world);
        			return 3;
				}
			}
		}
	}

	for (ul32_t i = 0; i < read_world.ent_count; i++)
	{
		if (read_world.entities[i].id != write_world.entities[i].id ||
			read_world.entities[i].grounded != write_world.entities[i].grounded ||
			read_world.entities[i].velocity_x != write_world.entities[i].velocity_x ||
			read_world.entities[i].velocity_y != write_world.entities[i].velocity_y ||
			read_world.entities[i].rect.x != write_world.entities[i].rect.x ||
			read_world.entities[i].rect.y != write_world.entities[i].rect.y ||
			read_world.entities[i].rect.w != write_world.entities[i].rect.w ||
			read_world.entities[i].rect.h != write_world.entities[i].rect.h)
		{
			printf("ERROR: World entities differ.\n");
			SG_World_clear(&read_world);
        	SG_World_clear(&write_world);
			return 4;
		}
	}

	return 0;
}
