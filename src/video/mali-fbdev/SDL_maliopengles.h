#include "../../SDL_internal.h"

#ifndef _SDL_maliopengles_h
#define _SDL_maliopengles_h

#if SDL_VIDEO_DRIVER_MALI && SDL_VIDEO_OPENGL_EGL

#include "../SDL_sysvideo.h"
#include "../SDL_egl_c.h"

/* OpenGLES functions */
#define MALI_GLES_GetAttribute SDL_EGL_GetAttribute
#define MALI_GLES_GetProcAddress SDL_EGL_GetProcAddress
#define MALI_GLES_UnloadLibrary SDL_EGL_UnloadLibrary
#define MALI_GLES_SetSwapInterval SDL_EGL_SetSwapInterval
#define MALI_GLES_GetSwapInterval SDL_EGL_GetSwapInterval
#define MALI_GLES_DeleteContext SDL_EGL_DeleteContext

extern int MALI_GLES_LoadLibrary(_THIS, const char *path);
extern SDL_GLContext MALI_GLES_CreateContext(_THIS, SDL_Window * window);
extern int MALI_GLES_SwapWindow(_THIS, SDL_Window * window);
extern int MALI_GLES_MakeCurrent(_THIS, SDL_Window * window, SDL_GLContext context);

#endif /* SDL_VIDEO_DRIVER_MALI && SDL_VIDEO_OPENGL_EGL */

#endif
