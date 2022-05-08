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

#include "SG_types.h"
#include "SG_physics.h"

bool_t SG_point_within_box( SG_FPoint *pt, SG_FRect *box )
{
    if (pt->x > box->x && pt->x < (box->x + box->w) &&
    	pt->y > box->y && pt->y < (box->y + box->h))
	{
		return TRUE;
	}

	return FALSE;
}

bool_t SG_box_within_box( SG_FRect *box_1, SG_FRect *box_2 )
{
    SG_FPoint pt;

    // check if box 1 within box 2
    pt.x = box_1->x;
    pt.y = box_1->y;

    if (SG_point_within_box(&pt, box_2))
		return TRUE;

	pt.x = box_1->x + box_1->w;
    pt.y = box_1->y;

    if (SG_point_within_box(&pt, box_2))
		return TRUE;

	pt.x = box_1->x;
    pt.y = box_1->y + box_1->h;

    if (SG_point_within_box(&pt, box_2))
		return TRUE;

	pt.x = box_1->x + box_1->w;
    pt.y = box_1->y + box_1->h;

    if (SG_point_within_box(&pt, box_2))
		return TRUE;

	// check if box 2 within box 1
	pt.x = box_2->x;
    pt.y = box_2->y;

    if (SG_point_within_box(&pt, box_1))
		return TRUE;

	pt.x = box_2->x + box_1->w;
    pt.y = box_2->y;

    if (SG_point_within_box(&pt, box_1))
		return TRUE;

	pt.x = box_2->x;
    pt.y = box_2->y + box_1->h;

    if (SG_point_within_box(&pt, box_1))
		return TRUE;

	pt.x = box_2->x + box_1->w;
    pt.y = box_2->y + box_1->h;

    if (SG_point_within_box(&pt, box_1))
		return TRUE;

    return FALSE;
}
