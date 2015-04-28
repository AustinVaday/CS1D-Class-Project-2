#ifndef GOOGLECOMPUTEINTERFACE_H
#define GOOGLECOMPUTEINTERFACE_H

#include <qprocess.h>
#include <qobject.h>

class googleComputeInterface : public QObject
{
		Q_OBJECT
	public:
		explicit googleComputeInterface(QObject *parent = 0);
		~googleComputeInterface();

		bool connectOAuth2();

	private:


	signals:

	public slots:
};

#endif // GOOGLECOMPUTEINTERFACE_H
