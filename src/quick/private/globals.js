/*
 * SPDX-FileCopyrightText: 2025 Kai Uwe Broulik <kde@broulik.de>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
*/

// Cannot create an internal singleton, so we have to hack around
// this using a JS library, we only want one of these, and created
// only when absolutely necessary as this triggers network operations ´
// on creation already.
.pragma library

var osmPlugin = null;
