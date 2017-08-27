#include "autoaccept.h"

bool Settings::AutoAccept::enabled = false;
/*
struct CServerConfirmedReservationCheckCallback
{
	char pad[0x2200];
};
*/

typedef struct xdo_search xdo_search_t;

void AutoAccept::PlaySound(const char* filename)
{
	if (!Settings::AutoAccept::enabled)
		return;

	if (engine->IsInGame())
		return;

	if (strcmp(filename, XORSTR("UI/competitive_accept_beep.wav")) != 0) // new wav file on autoaccept, thanks @flawww
		return;
	/*
	Window *list;
	xdo_search_t search;
	unsigned int nwindows;
	memset(&search, 0, sizeof(xdo_search_t));
	search.max_depth = -1;
	search.require = xdo_search::SEARCH_ANY;
	
	search.searchmask |= SEARCH_NAME;
	search.winname = "csgo_linux64";

// the context
	xdo_t* p_xdo = xdo_new(NULL);
	Window wid = xdo_search_windows(p_xdo, &search, &list, &nwindows);
	int winsize = xdo_get_window_size(p_xdo, Window wid, unsigned int *width_ret, unsigned int *height_ret);
	*/
	//CServerConfirmedReservationCheckCallback empty_callback;
	//IsReadyCallback(&empty_callback);
}
