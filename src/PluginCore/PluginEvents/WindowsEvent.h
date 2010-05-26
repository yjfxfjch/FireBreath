/**********************************************************\ 
Original Author: Richard Bateman (taxilian)

Created:    Oct 19, 2009
License:    Dual license model; choose one of two:
            New BSD License
            http://www.opensource.org/licenses/bsd-license.php
            - or -
            GNU Lesser General Public License, version 2.1
            http://www.gnu.org/licenses/lgpl-2.1.html

Copyright 2009 PacketPass, Inc and the Firebreath development team
\**********************************************************/

#ifndef H_FB_EVENTS_WINDOWSEVENT
#define H_FB_EVENTS_WINDOWSEVENT

#ifndef _WINDOWS
#define HWND void *
#else
#include "Win/win_common.h"
#endif

#include "PluginEvent.h"

namespace FB {

    class WindowsEvent : public PluginEvent
    {
    public:
        WindowsEvent(HWND hWnd, unsigned int msg, unsigned int wparam, long lparam)
            : hWnd(hWnd), uMsg(msg), wParam(wparam), lParam(lparam)
        { }

    public:
        HWND hWnd;
        unsigned int uMsg;
        unsigned int wParam;
        long lParam;
    };
};

#endif