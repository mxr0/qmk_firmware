/* Copyright 2022 Maximilian Ronniger <madhu1008@gmail.com>
 * SPDX-License-Identifier: GPL-2.0+
 */

#include "quantum.h"

#define LAYOUT( \
    K00, K01, K02, K03, \
    K10, K11, K12, K13  \
) \
{ \
    { K00, K01, K02, K03 }, \
    { K10, K11, K12, K13 }  \
}

