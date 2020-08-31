/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_POINTER_HELPER_P_H
#define KPUBLICTRANSPORT_POINTER_HELPER_P_H

#include <qglobal.h>
#include <memory>

template <typename T>
static inline typename std::unique_ptr<T>::pointer qGetPtrHelper(const std::unique_ptr<T> &p)
{
    return p.get();
}

#endif
