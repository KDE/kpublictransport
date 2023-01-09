/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "io.h"
#include "ioplugin.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QPluginLoader>

#include <optional>

using namespace OSM;

Q_IMPORT_PLUGIN(OSM_O5mIOPlugin)

IOPluginInterface::~IOPluginInterface() = default;

static std::optional<QStaticPlugin> pluginForMetaData(QLatin1String key, QStringView value)
{
    const auto plugins = QPluginLoader::staticPlugins();
    for (const auto &plugin : plugins) {
        const auto md = plugin.metaData();
        if (md.value(QLatin1String("IID")).toString() != QLatin1String(OSMIOPluginInteraface_iid)) {
            continue;
        }
        const auto exts = md.value(QLatin1String("MetaData")).toObject().value(key).toArray();
        for (const auto &ext : exts) {
            if (value.endsWith(ext.toString(), Qt::CaseInsensitive)) {
                return plugin;
            }
        }
    }

    return {};
}

std::unique_ptr<AbstractReader> IO::readerForFileName(QStringView fileName, OSM::DataSet *dataSet)
{
    const auto plugin = pluginForMetaData(QLatin1String("fileExtensions"), fileName);
    if (plugin) {
        return qobject_cast<IOPluginInterface*>(plugin->instance())->createReader(dataSet);
    }
    return {};
}

std::unique_ptr<AbstractReader> IO::readerForMimeType(QStringView mimeType, OSM::DataSet* dataSet)
{
    const auto plugin = pluginForMetaData(QLatin1String("mimetypes"), mimeType);
    if (plugin) {
        return qobject_cast<IOPluginInterface*>(plugin->instance())->createReader(dataSet);
    }
    return {};
}

std::unique_ptr<AbstractWriter> IO::writerForFileName(QStringView fileName)
{
    const auto plugin = pluginForMetaData(QLatin1String("fileExtensions"), fileName);
    if (plugin) {
        return qobject_cast<IOPluginInterface*>(plugin->instance())->createWriter();
    }
    return {};
}

std::unique_ptr<AbstractWriter> IO::writerForMimeType(QStringView mimeType)
{
    const auto plugin = pluginForMetaData(QLatin1String("mimeypes"), mimeType);
    if (plugin) {
        return qobject_cast<IOPluginInterface*>(plugin->instance())->createWriter();
    }
    return {};
}
