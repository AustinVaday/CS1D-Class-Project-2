#ifndef GOOGLECOMPUTEINTERFACE_H
#define GOOGLECOMPUTEINTERFACE_H
/*************************************************************************
 * Google Compute Server Interface
 * -----------------------------------------------------------------------
 * Developer - Erik Karlsson
 *************************************************************************
 * Easy Qt interface for Google Cloud Compute Server
 *	Additional tools will be a workaround for MySQL commands and features
 *	through google's cloud compute server.
 ************************************************************************/

#include <qprocess.h>
#include <qobject.h>
#include <QString>
#include <qsysinfo.h>
#include <sqlite3.h>

class googleComputeInterface : public QObject
{
		Q_OBJECT
	public:
		explicit googleComputeInterface(QObject *parent = 0);
		~googleComputeInterface();

		bool login(QString project, QString instance, QString user, QString zone);
		// Login into google compute servers
		//

		void systemCommand(QString command/**/);
		//

		bool copyDataBade(/*Possible parameters*/);
		//

		bool createDataBase(/**/);
		//
		//

		bool writeDataNase(/**/);

	private:

	signals:

	public slots:
};

#endif // GOOGLECOMPUTEINTERFACE_H
