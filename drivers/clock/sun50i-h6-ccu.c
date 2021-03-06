/*
 * Copyright © 2017-2020 The Crust Firmware Authors.
 * SPDX-License-Identifier: BSD-3-Clause OR GPL-2.0-only
 */

#include <bitmap.h>
#include <clock.h>
#include <debug.h>
#include <device.h>
#include <stdint.h>
#include <clock/ccu.h>
#include <platform/devices.h>

#include "ccu.h"

static uint32_t
sun50i_h6_ccu_fixed_get_rate(const struct ccu *self UNUSED,
                             uint32_t rate UNUSED, uint8_t id UNUSED)
{
	assert(id == CLK_PLL_PERIPH0);

	return 600000000U;
}

static const struct ccu_clock sun50i_h6_ccu_clocks[SUN50I_H6_CCU_CLOCKS] = {
	[CLK_PLL_PERIPH0] = {
		.get_parent = ccu_get_parent_none,
		.get_rate   = sun50i_h6_ccu_fixed_get_rate,
	},
	[CLK_BUS_MSGBOX] = {
		.get_parent = ccu_get_parent_none,
		.get_rate   = ccu_get_rate_parent,
		.gate       = BITMAP_INDEX(0x071c, 0),
		.reset      = BITMAP_INDEX(0x071c, 16),
	},
};

const struct ccu ccu = {
	.dev = {
		.name  = "ccu",
		.drv   = &ccu_driver.drv,
		.state = CLOCK_DEVICE_STATE_INIT(SUN50I_H6_CCU_CLOCKS),
	},
	.clocks = sun50i_h6_ccu_clocks,
	.regs   = DEV_CCU,
};
