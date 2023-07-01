/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_JSONPOINTER_H
#define KPUBLICTRANSPORT_JSONPOINTER_H

class QJsonValue;
class QStringView;

namespace KPublicTransport {


/** JSONPointer according to RFC 6901.
 *  @note This does not implement the ~ quoting rules yet,
 *  as those don't matter for the uses here.
 */
namespace JsonPointer {

QJsonValue evaluate(const QJsonValue &obj, QStringView jsonPath);

}

}

#endif
