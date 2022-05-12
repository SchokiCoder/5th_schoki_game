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

bool_t SG_fpoint_within_frect( SG_FPoint *pt, SG_FRect *rect )
{
    if (pt->x > rect->x && pt->x < (rect->x + rect->w) &&
    	pt->y > rect->y && pt->y < (rect->y + rect->h))
	{
		return TRUE;
	}

	return FALSE;
}

bool_t SG_ipoint_within_irect( SG_IPoint *pt, SG_IRect *rect )
{
	if (pt->x > rect->x && pt->x < (rect->x + rect->w) &&
    	pt->y > rect->y && pt->y < (rect->y + rect->h))
	{
		return TRUE;
	}

	return FALSE;
}

bool_t SG_frect_within_frect( SG_FRect *a, SG_FRect *b )
{
    SG_FPoint pt;

    // check if box 1 within box 2
    pt.x = a->x;
    pt.y = a->y;

    if (SG_fpoint_within_frect(&pt, b))
		return TRUE;

	pt.x = a->x + a->w;
    pt.y = a->y;

    if (SG_fpoint_within_frect(&pt, b))
		return TRUE;

	pt.x = a->x;
    pt.y = a->y + a->h;

    if (SG_fpoint_within_frect(&pt, b))
		return TRUE;

	pt.x = a->x + a->w;
    pt.y = a->y + a->h;

    if (SG_fpoint_within_frect(&pt, b))
		return TRUE;

	// check if box 2 within box 1
	pt.x = b->x;
    pt.y = b->y;

    if (SG_fpoint_within_frect(&pt, a))
		return TRUE;

	pt.x = b->x + a->w;
    pt.y = b->y;

    if (SG_fpoint_within_frect(&pt, a))
		return TRUE;

	pt.x = b->x;
    pt.y = b->y + a->h;

    if (SG_fpoint_within_frect(&pt, a))
		return TRUE;

	pt.x = b->x + a->w;
    pt.y = b->y + a->h;

    if (SG_fpoint_within_frect(&pt, a))
		return TRUE;

    return FALSE;
}

bool_t SG_irect_within_irect( SG_IRect *a, SG_IRect *b )
{
    SG_IPoint pt;

    // check if box 1 within box 2
    pt.x = a->x;
    pt.y = a->y;

    if (SG_ipoint_within_irect(&pt, b))
		return TRUE;

	pt.x = a->x + a->w;
    pt.y = a->y;

    if (SG_ipoint_within_irect(&pt, b))
		return TRUE;

	pt.x = a->x;
    pt.y = a->y + a->h;

    if (SG_ipoint_within_irect(&pt, b))
		return TRUE;

	pt.x = a->x + a->w;
    pt.y = a->y + a->h;

    if (SG_ipoint_within_irect(&pt, b))
		return TRUE;

	// check if box 2 within box 1
	pt.x = b->x;
    pt.y = b->y;

    if (SG_ipoint_within_irect(&pt, a))
		return TRUE;

	pt.x = b->x + a->w;
    pt.y = b->y;

    if (SG_ipoint_within_irect(&pt, a))
		return TRUE;

	pt.x = b->x;
    pt.y = b->y + a->h;

    if (SG_ipoint_within_irect(&pt, a))
		return TRUE;

	pt.x = b->x + a->w;
    pt.y = b->y + a->h;

    if (SG_ipoint_within_irect(&pt, a))
		return TRUE;

    return FALSE;
}
