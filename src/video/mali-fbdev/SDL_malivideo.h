#ifndef _SDL_malivideo_h
#define _SDL_malivideo_h

#include "../../SDL_internal.h"
#include "../SDL_sysvideo.h"

#include "SDL_egl.h"

#include <EGL/egl.h>
#include <linux/vt.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <linux/kd.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct fbdev_window
{
    unsigned short width;
    unsigned short height;
} fbdev_window;


typedef struct SDL_DisplayData
{
    struct fbdev_window native_display;
    int fb;
    int vsync_en;
    int mode_prev;
} SDL_DisplayData;

typedef struct SDL_WindowData
{
    EGLSurface egl_surface;
} SDL_WindowData;

struct owlfb_sync_info {
    __u8 enabled;
    __u8 disp_id;
    __u16 reserved2;
};

#define OWL_IOW(num, dtype)    _IOW('O', num, dtype)
#define OWLFB_WAITFORVSYNC            OWL_IOW(57,long long)
#define OWLFB_VSYNC_EVENT_EN          OWL_IOW(67, struct owlfb_sync_info)

/****************************************************************************/
/* SDL_VideoDevice functions declaration                                    */
/****************************************************************************/

/* Display and window functions */
int MALI_VideoInit(_THIS);
void MALI_VideoQuit(_THIS);
void MALI_GetDisplayModes(_THIS, SDL_VideoDisplay * display);
int MALI_SetDisplayMode(_THIS, SDL_VideoDisplay * display, SDL_DisplayMode * mode);
int MALI_CreateWindow(_THIS, SDL_Window * window);
void MALI_SetWindowTitle(_THIS, SDL_Window * window);
void MALI_SetWindowPosition(_THIS, SDL_Window * window);
void MALI_SetWindowSize(_THIS, SDL_Window * window);
void MALI_ShowWindow(_THIS, SDL_Window * window);
void MALI_HideWindow(_THIS, SDL_Window * window);
void MALI_DestroyWindow(_THIS, SDL_Window * window);

/* Window manager function */
int MALI_GLES_SetSwapInterval(_THIS, int interval);
int MALI_GLES_GetSwapInterval(_THIS);
SDL_bool MALI_GetWindowWMInfo(_THIS, SDL_Window * window,
                             struct SDL_SysWMinfo *info);

/* Event functions */
void MALI_PumpEvents(_THIS);

#endif /* _SDL_malivideo_h */

