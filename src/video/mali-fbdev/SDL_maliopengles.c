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

int MALI_GLES_SwapWindow(_THIS, SDL_Window * window)
{
    SDL_WindowData *windowdata;
    SDL_DisplayData *displaydata;

    windowdata = (SDL_WindowData*)_this->windows->driverdata;
    displaydata = SDL_GetDisplayDriverData(0);

    if (displaydata->vsync_en) {
        long long _arg; // dummy
        ioctl(displaydata->fb, OWLFB_WAITFORVSYNC, &_arg);
    }
    return SDL_EGL_SwapBuffers(_this, windowdata->egl_surface);
}

SDL_EGL_CreateContext_impl(MALI)
SDL_EGL_MakeCurrent_impl(MALI)

#endif /* SDL_VIDEO_DRIVER_MALI && SDL_VIDEO_OPENGL_EGL */
