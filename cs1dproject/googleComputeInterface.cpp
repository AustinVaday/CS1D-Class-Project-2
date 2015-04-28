#include "googleComputeInterface.h"
#include <qdebug.h>
googleComputeInterface::googleComputeInterface(QObject *parent) : QObject(parent)
{
	QString project = "CS1D-Class-Project-2";
	QString instance = "melodic-splicer-2";
	QString user = "remote_user";
	QString zone = "us-central1-b";
	if(login(project,instance,user,zone))
	{
	qDebug() << "login worked" << endl << endl;
	}
}

googleComputeInterface::~googleComputeInterface()
{


}

// Will authenticate and login the user
// Should be reduced to smaller methods
bool googleComputeInterface::login(QString project,
								   QString instance,
								   QString user,
								   QString zone)
{
	QProcess gcloudProc;
	QString	argument;
	int	exitCode;

	bool loginSuccessful = false;

	argument = project + '.' + zone + '.' + instance;

	// Attempts to activate gcloud oauthentication
	exitCode = gcloudProc.execute("gcloud auth login");

	if(exitCode == -2)
	{
		qDebug() << "Oauthentication cannot be started" << endl;
	}
	else if(exitCode == -1)
	{
		qDebug() << "Process Crashed : Oauthentication.\n\n";
	}
	else
	{
		// if authentication is successful, method will attempt to
		//	configure the ssh for the compute seerver
		exitCode = gcloudProc.execute("gcloud compute config-ssh");

		if(exitCode == -2)
		{
			qDebug() << "gcloud compute config cannot be started" << endl;
		}
		else if(exitCode == -1)
		{
			qDebug() << "Process Crashed : gcloud comput config.\n\n";
		}
		else
		{
			// Once the program has been able to authenticate and configure
			//	the ssh protocal, method will attempt to login as the
			//	user that is passed in
			exitCode = gcloudProc.execute(("ssh " + argument));

			if(exitCode == -2)
			{
				qDebug() << "gcloud ssh login cannot be started" << endl;
			}
			else if(exitCode == -1)
			{
				qDebug() << "Process Crashed : gcloud ssh login.\n\n";
			}
			else
			{
				exitCode = gcloudProc.execute("mysql --user=user_remote --password=CS1D baseball_stadiums");

				if(exitCode == -2)
				{
				qDebug() << "Process Crashed : gcloud ssh login,\n\n";
				}
				else if (exitCode == -1)
				{

				}
				else
				{
					loginSuccessful = true;
				}

			}
		}

	}

return loginSuccessful;
}

/************************************************************************
 * This is here for reference, will remove once completed
 *************************************************************************
QSqlError MainWindow::addConnection(const QString &driver, const QString &dbName, const QString &host, const QString &user, const QString &passwd, int port)
{
	static int cCount = 0;

	QSqlError err;
	QSqlDatabase db = QSqlDatabase::addDatabase(driver, QString("Browser%1").arg(++cCount));
	db.setDatabaseName(dbName);
	db.setHostName(host);
	db.setPort(port);
	if (!db.open(user, passwd)) {
		err = db.lastError();
		db = QSqlDatabase();
		QSqlDatabase::removeDatabase(QString("Browser%1").arg(cCount));
	}

	return err;
}
	// Add database type
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	bool open = false;
	// set attributes
	db.setHostName("107.178.222.186");
	db.setDatabaseName("baseball_stadiums");
	db.setUserName("root");

	if (db.open("root",""))
	   open = true;

	return open;*/
