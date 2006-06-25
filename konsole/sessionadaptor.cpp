/*
 * This file was generated by dbusidl2cpp version 0.5
 * when processing input file org.kde.konsole.Session.xml
 *
 * dbusidl2cpp is Copyright (C) 2006 Trolltech AS. All rights reserved.
 *
 * This is an auto-generated file.
 */

#include "sessionadaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class SessionAdaptor
 */

SessionAdaptor::SessionAdaptor(QObject *parent)
   : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

SessionAdaptor::~SessionAdaptor()
{
    // destructor
}

void SessionAdaptor::clearHistory()
{
    // handle method call org.kde.konsole.Session.clearHistory
    QMetaObject::invokeMethod(parent(), "clearHistory");

    // Alternative:
    //static_cast<YourObjectType *>(parent())->clearHistory();
}

bool SessionAdaptor::closeSession()
{
    // handle method call org.kde.konsole.Session.closeSession
    bool out0;
    QMetaObject::invokeMethod(parent(), "closeSession", Q_RETURN_ARG(bool, out0));

    // Alternative:
    //out0 = static_cast<YourObjectType *>(parent())->closeSession();
    return out0;
}

QString SessionAdaptor::encoding()
{
    // handle method call org.kde.konsole.Session.encoding
    QString out0;
    QMetaObject::invokeMethod(parent(), "encoding", Q_RETURN_ARG(QString, out0));

    // Alternative:
    //out0 = static_cast<YourObjectType *>(parent())->encoding();
    return out0;
}

QString SessionAdaptor::font()
{
    // handle method call org.kde.konsole.Session.font
    QString out0;
    QMetaObject::invokeMethod(parent(), "font", Q_RETURN_ARG(QString, out0));

    // Alternative:
    //out0 = static_cast<YourObjectType *>(parent())->font();
    return out0;
}

QString SessionAdaptor::keytab()
{
    // handle method call org.kde.konsole.Session.keytab
    QString out0;
    QMetaObject::invokeMethod(parent(), "keytab", Q_RETURN_ARG(QString, out0));

    // Alternative:
    //out0 = static_cast<YourObjectType *>(parent())->keytab();
    return out0;
}

void SessionAdaptor::renameSession(const QString &name)
{
    // handle method call org.kde.konsole.Session.renameSession
    QMetaObject::invokeMethod(parent(), "renameSession", Q_ARG(QString, name));

    // Alternative:
    //static_cast<YourObjectType *>(parent())->renameSession(name);
}

QString SessionAdaptor::schema()
{
    // handle method call org.kde.konsole.Session.schema
    QString out0;
    QMetaObject::invokeMethod(parent(), "schema", Q_RETURN_ARG(QString, out0));

    // Alternative:
    //out0 = static_cast<YourObjectType *>(parent())->schema();
    return out0;
}

bool SessionAdaptor::sendSignal(bool signal)
{
    // handle method call org.kde.konsole.Session.sendSignal
    bool out0;
    QMetaObject::invokeMethod(parent(), "sendSignal", Q_RETURN_ARG(bool, out0), Q_ARG(bool, signal));

    // Alternative:
    //out0 = static_cast<YourObjectType *>(parent())->sendSignal(signal);
    return out0;
}

QString SessionAdaptor::sessionName()
{
    // handle method call org.kde.konsole.Session.sessionName
    QString out0;
    QMetaObject::invokeMethod(parent(), "sessionName", Q_RETURN_ARG(QString, out0));

    // Alternative:
    //out0 = static_cast<YourObjectType *>(parent())->sessionName();
    return out0;
}

int SessionAdaptor::sessionPID()
{
    // handle method call org.kde.konsole.Session.sessionPID
    int out0;
    QMetaObject::invokeMethod(parent(), "sessionPID", Q_RETURN_ARG(int, out0));

    // Alternative:
    //out0 = static_cast<YourObjectType *>(parent())->sessionPID();
    return out0;
}

void SessionAdaptor::setEncoding(const QString &encoding)
{
    // handle method call org.kde.konsole.Session.setEncoding
    QMetaObject::invokeMethod(parent(), "setEncoding", Q_ARG(QString, encoding));

    // Alternative:
    //static_cast<YourObjectType *>(parent())->setEncoding(encoding);
}

void SessionAdaptor::setFont(const QString &encoding)
{
    // handle method call org.kde.konsole.Session.setFont
    QMetaObject::invokeMethod(parent(), "setFont", Q_ARG(QString, encoding));

    // Alternative:
    //static_cast<YourObjectType *>(parent())->setFont(encoding);
}

void SessionAdaptor::setKeytab(const QString &encoding)
{
    // handle method call org.kde.konsole.Session.setKeytab
    QMetaObject::invokeMethod(parent(), "setKeytab", Q_ARG(QString, encoding));

    // Alternative:
    //static_cast<YourObjectType *>(parent())->setKeytab(encoding);
}

void SessionAdaptor::setSchema(const QString &schema)
{
    // handle method call org.kde.konsole.Session.setSchema
    QMetaObject::invokeMethod(parent(), "setSchema", Q_ARG(QString, schema));

    // Alternative:
    //static_cast<YourObjectType *>(parent())->setSchema(schema);
}


#include "sessionadaptor.moc"