
/******************************************************************************
 *         MODIFIED MY JUAN PEDRO BOLIVAR FOR BETTER INTEGRATION IN           *
 * 		   THIS PROJECT.					      *
 ******************************************************************************/
/*  Only works on THIS project */


/*  SFont: a simple font-library that uses special bitmaps as fonts
    Copyright (C) 2003 Karl Bartel

    License: GPL or LGPL (at your choice)
    WWW: http://www.linux-games.com/sfont/

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Karl Bartel
    Cecilienstr. 14
    12307 Berlin
    GERMANY
    karlb@gmx.net
*/

/************************************************************************
*    SFONT - SDL Font Library by Karl Bartel <karlb@gmx.net>            *
*                                                                       *
*  All functions are explained below. For further information, take a   *
*  look at the example files, the links at the SFont web site, or       *
*  contact me, if you problem isn' addressed anywhere.                  *
*                                                                       *
************************************************************************/
#ifndef SFONT_H
#define SFONT_H

#include <SDL/SDL.h>
#include <string.h>

#include "surface.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /* Added by Juan Pedro Bolíar */
#define ALEFT 0
#define ACENTER 1
#define ARIGHT 2

// Delcare one variable of this type for each font you are using.
// To load the fonts, load the font image into YourFont->Surface
// and call InitFont( YourFont );
  typedef struct
  {
    JPB_surface *Surface;
    int CharPos[512];
    int MaxPos;
  }
  SFont_Font;

// Initializes the font
// Font: this contains the suface with the font.
//       The Surface must be loaded before calling this function
//SFont_Font* SFont_InitFont (SDL_Surface *Font);
  SFont_Font *SFont_InitFont (char *file, SDL_Surface * Surface, Uint8 gl,
			      Uint8 alpha);

// Frees the font
// Font: The font to free
//       The font must be loaded before using this function.
  void SFont_FreeFont (SFont_Font * Font);

// Blits a string to a surface
// Destination: the suface you want to blit to
// text: a string containing the text you want to blit.
  void SFont_Write (SFont_Font * Font, int x, int y, char *text);

// Returns the width of "text" in pixels
  int SFont_TextWidth (const SFont_Font * Font, const char *text);
// Returns the height of "text" in pixels (which is always equal to Font->Surface->h)
  int SFont_TextHeight (const SFont_Font * Font);

// Blits a string to Surface with centered x position
  void SFont_WriteCenter (SDL_Surface * Surface, SFont_Font * Font,
			  int y, char *text);

  /* Blits a string aligned in a square defined by X, Y and W. */
  void SFont_WriteAligned (SFont_Font * Font, int x, int y, int w,
			   int gap, int align, char *text);

  /* Returns the heigth of a multi-line text */
  int SFont_AlignedHeight (SFont_Font * Font, int w, int gap, char *text);

  int SFont_FillWith (SFont_Font * Font, int x, int y, int w, char c);

  void SFont_WriteMaxWidth (SFont_Font * Font, int x, int y, int w,
			    int align, char *tag, char *text);

  int SFont_SetAlpha (SFont_Font * font, int alpha);

#ifdef __cplusplus
}
#endif

#endif				/* SFONT_H */