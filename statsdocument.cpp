#include "statsdocument.h"
#include "statskeyvaluemodel.h"
#include "istatsmodelprovider.h"
#include "statsserializer.h"
#include <QWidget>
#include <QFileDialog>
#include <QStandardPaths>
#include "qmessagebox.h"

namespace
{
const QLatin1String FILE_FORMAT_FILTER("*.json");
}

StatsDocument::StatsDocument(QWidget *parent, IStatsModelProvider &provider)
    : QObject(parent)
    , m_provider(provider)
{

}

void StatsDocument::createNew()
{
    StatsKeyValueModel model;
    m_provider.setStatsModel(model);
	m_openPath = "";
}

bool StatsDocument::open()
{
    QString openPath = selectOpenPath();
    if (openPath.isEmpty())
    {
        return false;
    }

    StatsKeyValueModel model;
    StatsSerializer serializer(openPath);
    if (!serializer.load(model))
    {
        return false;
    }

    m_provider.setStatsModel(model);
	m_provider.setIsSaved();
	m_openPath = openPath;
    return true;
}

bool StatsDocument::save()
{
	if (!m_provider.isSaved())
	{
		if (m_openPath.isEmpty() || !StatsSerializer::isPathExist(m_openPath))
		{
			return saveAs();
		}
		if (!m_openPath.isEmpty())
		{
			return saveToPath(m_openPath);
		}
	}
    return false;
}

bool StatsDocument::saveAs()
{
    QString savePath = selectSavePath();
	return saveToPath(savePath);
}

bool StatsDocument::saveToPath(const QString& savePath)
{
	if (savePath.isEmpty())
	{
		return false;
	}
	StatsSerializer serializer(savePath);
	bool result = serializer.save(m_provider.statsModel());
	if (result)
	{
		m_provider.setIsSaved();
		m_openPath = savePath;
	}
	return result;
}

bool StatsDocument::isSaved()
{
	return m_provider.isSaved();
}

QString StatsDocument::selectSavePath() const
{
    QString fromDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    auto parentWindow = qobject_cast<QWidget *>(parent());
    return QFileDialog::getSaveFileName(parentWindow, QString(), fromDir, FILE_FORMAT_FILTER);
}

QString StatsDocument::selectOpenPath() const
{
    QString fromDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    auto parentWindow = qobject_cast<QWidget *>(parent());
    return QFileDialog::getOpenFileName(parentWindow, QString(), fromDir, FILE_FORMAT_FILTER);
}
