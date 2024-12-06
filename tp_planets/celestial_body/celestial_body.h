#ifndef _CELESTIAL_BODY_H_
#define _CELESTIAL_BODY_H_

#include "../vec2/vec2.h"
#include "../gfx/gfx.h"

typedef struct _celestial_body
{
    double mass;
    vec2 pos;      // x(t)
    vec2 prec_pos; // x(t - dt)
} celestial_body_t;

typedef struct _system
{
    celestial_body_t star;       // ex. The sun
    uint32_t nb_planets; // The number of orbiting planets
    celestial_body_t *planets;   // An array of orbiting planets
} system_t;

// Those function are not mandatory to implement,
// it's rather a hint of what you should have.
celestial_body_t create_celestial_body(double mass, vec2 pos);
system_t create_system(double delta_t);
void show_system(struct gfx_context_t *ctxt, system_t *system);
void update_system(system_t *system, double delta_t);
void free_system(system_t *system);

#endif