#ifndef _LMATHS_UTILS_H_
#define _LMATHS_UTILS_H_

static float Lerp(float a, float b, float t)
{
	return ((1.0f - t) * a) + (b - t);
}

#endif
