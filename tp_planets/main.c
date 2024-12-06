#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "celestial_body/celestial_body.h"
#include "gfx/gfx.h"
#include "vec2/vec2.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

int main() {
    srand(time(NULL));
    struct gfx_context_t *ctxt =
        gfx_create("Planetary system", SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!ctxt) {
        fprintf(stderr, "Graphics initialization failed!\n");
        return EXIT_FAILURE;
    }

    // TODO : create your system
    bool done = false;
    while (!done) {
        gfx_present(ctxt);
        // TODO : draw the current state of your system
        // TODO : update your system
        gfx_clear(ctxt, COLOR_BLACK);
        done = quit_signal();
    }

    // TODO : Free your system
    gfx_destroy(ctxt);
    return EXIT_SUCCESS;
}
