#ifndef NUCLEAR_EXPLOSION_H
#define NUCLEAR_EXPLOSION_H

#include "element.h"

class NuclearExplosion: public Element {
public:
    const double PROCESS = 1.0 / 4;
    const double DECAY = 1.0 / 18.0;

    void process(SandSimulation *sim, int row, int col) override {
        // Adding a limit slows the explosion down
        if (sim->randf() > PROCESS) {
            return;
        // We eliminate explosions that reach the end, as they tend to linger for a long time if not checked
        } else if (sim->randf() < DECAY || sim->touch_count(row, col, 22) > 2 ||
            row == sim->get_height() - 1 || col == sim->get_width() - 1 || col == 0 || row == 0) {
            sim->set_cell(row, col, 22);
        } else {
            sim->grow(row + 1, col, -1, 34);
            sim->grow(row - 1, col, -1, 34);
            sim->grow(row, col + 1, -1, 34);
            sim->grow(row, col - 1, -1, 34);
        }
    }

    double get_density() override {
        return 128.0;
    }

    double get_explode_resistance() override {
        return 0.0;
    }

    double get_acid_resistance() override {
        return 0.0;
    }
};

#endif // NUCLEAR_EXPLOSION_H