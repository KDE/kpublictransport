/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_IDENTIFIER_H
#define KPUBLICTRANSPORT_IDENTIFIER_H

#include <QString>

class QJsonObject;

namespace KPublicTransport {

class Identifier {
public:
    QString type;
    QString value;
};

class IdentifierSet {
public:
    [[nodiscard]] inline bool isEmpty() const { return m_identifiers.empty(); }
    [[nodiscard]] bool hasIdentifier(QAnyStringView type) const;
    [[nodiscard]] QString identifier(QAnyStringView type) const;
    void setIdentifier(const QString &type, const QString &value);
    [[nodiscard]] QStringList identifierTypes() const;

    enum PartialCompare {
        NoIntersection,
        Equal,
        NotEqual,
    };
    [[nodiscard]] PartialCompare compare(const IdentifierSet &other) const;

    void merge(const IdentifierSet &other);

    [[nodiscard]] QJsonObject toJson() const;
    void fromJson(const QJsonObject &ids);

private:
    std::vector<Identifier> m_identifiers;
};

}

#endif
