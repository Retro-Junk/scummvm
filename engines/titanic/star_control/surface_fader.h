/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef TITANIC_SURFACE_FADER_H
#define TITANIC_SURFACE_FADER_H

#include "titanic/support/video_surface.h"
#include "titanic/support/screen_manager.h"
#include "titanic/star_control/surface_area.h"

namespace Titanic {

class CSurfaceFaderBase {
protected:
	/**
	 * Sets up an internal surface to match the size of the specified one
	 */
	bool setupSurface(CScreenManager *screenManager, CVideoSurface *srcSurface);
public:
	int _index;
	int _count;
	CVideoSurface *_videoSurface;
public:
	CSurfaceFaderBase();
	virtual ~CSurfaceFaderBase();

	/**
	 * Reset fading back to the start
	 */
	virtual void reset();

	/**
	 * Creates a faded version of the passed source surface, based on a percentage
	 * visibility specified by _index of _count
	 */
	virtual CVideoSurface *fade(CScreenManager *screenManager, CVideoSurface *srcSurface) = 0;

	/**
	 * Returns true if a fade is in progress
	 */
	bool isActive() const { return _index != -1 && _index < _count; }
};

class CSurfaceFader: public CSurfaceFaderBase {
private:
	byte *_dataP;
	bool _fadeIn;
private:
	/**
	 * Create a faded version of the source surface at the given dest
	 */
	void copySurface(CSurfaceArea &srcSurface, CSurfaceArea &destSurface);
public:
	CSurfaceFader();
	virtual ~CSurfaceFader();

	/**
	 * Creates a faded version of the passed source surface, based on a percentage
	 * visibility specified by _index of _count
	 */
	virtual CVideoSurface *fade(CScreenManager *screenManager, CVideoSurface *srcSurface);

	/**
	 * Sets whether a fade in (versus a fade out) should be done
	 */
	void setFadeIn(bool fadeIn);
};

} // End of namespace Titanic

#endif /* TITANIC_SURFACE_SHADER_H */
