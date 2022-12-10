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

#include "SG_types.h"
#include "SG_physics.h"
#include <stdio.h>

int main()
{
	SG_IRect irects[] = {
		[0] = {
		       .x = 0,
		       .y = 0,
		       .w = 10,
		       .h = 10,
		       },

		[1] = {
		       .x = 5,
		       .y = 5,
		       .w = 10,
		       .h = 15,
		       },

		[2] = {
		       .x = 50,
		       .y = 40,
		       .w = 5,
		       .h = 5,
		       },
	};

	SG_IRect frects[3] = {
		[0] = {
		       .x = 0.0f,
		       .y = 0.0f,
		       .w = 10.0f,
		       .h = 10.0f,
		       },

		[1] = {
		       .x = 9.9f,
		       .y = 9.9f,
		       .w = 10.0f,
		       .h = 15.0f,
		       },

		[2] = {
		       .x = 50.0f,
		       .y = 40.0f,
		       .w = 5.0f,
		       .h = 5.0f,
		       },
	};

	if (SG_irect_within_irect(&irects[0], &irects[1]))
		printf("correct collision\n");

	if (SG_irect_within_irect(&irects[1], &irects[2]))
		printf("ERROR: incorrect collision\n");

	if (SG_irect_within_irect(&irects[0], &irects[2]))
		printf("ERROR: incorrect collision\n");

	if (SG_irect_within_irect(&frects[0], &frects[1]))
		printf("correct collision\n");

	if (SG_irect_within_irect(&frects[1], &frects[2]))
		printf("ERROR: incorrect collision\n");

	if (SG_irect_within_irect(&frects[0], &frects[2]))
		printf("ERROR: incorrect collision\n");

	return 0;
}
