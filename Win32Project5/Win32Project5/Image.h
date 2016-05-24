#ifndef _IMAGE_H
#define _IMAGE_H

#include "Project.h"

class Image
{
private:

public:
	friend class Graphics;
	SDL_Surface* surf;
	int GetWidth();
	int GetHeight();
};

#endif