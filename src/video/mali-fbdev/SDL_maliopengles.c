#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_MALI && SDL_VIDEO_OPENGL_EGL

#include "SDL_maliopengles.h"
#include "SDL_malivideo.h"

/* EGL implementation of SDL OpenGL support */

int
MALI_GLES_LoadLibrary(_THIS, const char *path)
{
    return SDL_EGL_LoadLibrary(_this, path, EGL_DEFAULT_DISPLAY, 0);
}

SDL_EGL_CreateContext_impl(MALI)
SDL_EGL_SwapWindow_impl(MALI)
SDL_EGL_MakeCurrent_impl(MALI)

#endif /* SDL_VIDEO_DRIVER_MALI && SDL_VIDEO_OPENGL_EGL */
