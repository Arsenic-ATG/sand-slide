#ifndef IODINE_GAS_H
#define IODINE_GAS_H

#include "element.h"

class IodineGas: public Element {
public:
    const double DECAY = 1.0 / 1024;
    const double UP = 1.0 / 1.5;
    const double UP_BLOCK = 1.0 / 16;

    void process(SandSimulation *sim, int row, int col) override {
        if (sim->randf() < DECAY) {
            sim->set_cell(row, col, 0);
        }

        bool blocked = !sim->in_bounds(row - 1, col) || sim->get_cell(row - 1, col) == 6;
        if (sim->randf() < (blocked ? UP_BLOCK : UP)) {
            sim->move_and_swap(row, col, row - 1, col);
        } else {
            sim->move_and_swap(row, col, row, col + (sim->randf() < 0.5 ? 1 : -1));
        }
    }

    double get_density() override {
        return 9.0;
    }

    double get_explode_resistance() override {
        return 0.4;
    }

    double get_acid_resistance() override {
        return 0.8;
    }
};

#endif // IODINE_GAS_H