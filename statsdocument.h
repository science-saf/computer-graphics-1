#pragma once

#include <QObject>
#include <memory>
#include "istatsmodelprovider.h"

class QWidget;
class IStatsModelProvider;

class StatsDocument : public QObject
{
    Q_OBJECT
public:
    explicit StatsDocument(QWidget *parent, IStatsModelProvider &provider);

    void createNew();
    bool open();
    bool save();
	bool saveAs();
	bool isSaved();

private:
    QString selectSavePath() const;
    QString selectOpenPath() const;
	bool saveToPath(const QString& savePath);

    IStatsModelProvider &m_provider;
	QString m_openPath = "";
};
