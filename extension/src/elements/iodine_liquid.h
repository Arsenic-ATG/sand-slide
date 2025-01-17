#ifndef IODINE_LIQUID_H
#define IODINE_LIQUID_H

#include "element.h"
#include <stdlib.h>

class IodineLiquid: public Element {
public:
    const double DECAY = 1.0 / 512;

    void process(SandSimulation *sim, int row, int col) override {
        if (sim->randf() < DECAY && sim->touch_count(row, col, 0) > 0) {
            sim->set_cell(row, col, 83);
            return;
        }

        sim->liquid_process(row, col, 4); 
    }

    double get_density() override {
        return 8.0;
    }

    double get_explode_resistance() override {
        return 0.6;
    }

    double get_acid_resistance() override {
        return 0.8;
    }
};

#endif // IODINE_LIQUID_H