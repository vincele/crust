/*
 * Copyright © 2017-2019 The Crust Firmware Authors.
 * SPDX-License-Identifier: BSD-3-Clause OR GPL-2.0-only
 */

#ifndef DRIVERS_IRQ_H
#define DRIVERS_IRQ_H

#include <stdint.h>

/**
 * Get a bitmask of the pending IRQs.
 */
uint32_t irq_poll(void);

#endif /* DRIVERS_IRQ_H */