#include "tools/checksum.h"

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char* argv[])
{
	QCoreApplication app(argc, argv);

	QCryptographicHash::Algorithm alogorithm = QCryptographicHash::Algorithm::Sha256;

	QString file1 = "../../src/resources/test.txt";
	QString file2 = "../../src/resources/test2.txt";
	QString file3 = "../../src/resources/images/metalPanel_blue.png";

	// Verify
	QString checksum;
	qDebug() << "Verify:" << Checksum::textVerify("430904b7a17c4160534c44376d3d490406807d38693bf86e79b59a552db649dd", "Hi, This is a test", alogorithm, checksum) << "\n" << checksum;
	qDebug() << "Verify:" << Checksum::textVerify("374009697baf228ea87c15c201e5020e3b62e7834c80616b4a9662dac522ca5d", u8"中文測試", alogorithm, checksum) << "\n" << checksum;
	qDebug() << "Verify:" << Checksum::fileVerify("430904b7a17c4160534c44376d3d490406807d38693bf86e79b59a552db649dd", file1, alogorithm, checksum) << "\n" << checksum;
	qDebug() << "Verify:" << Checksum::fileVerify("374009697baf228ea87c15c201e5020e3b62e7834c80616b4a9662dac522ca5d", file2, alogorithm, checksum) << "\n" << checksum;
	qDebug() << "Verify:" << Checksum::fileVerify("1decf627a63a3bd78a43035581c8b1b11d398d8b6776d4930bd1514176a0a6b0", file3, alogorithm, checksum) << "\n" << checksum;

	// Checksum
	qDebug() << "Checksum: " << Checksum::textChecksum("Hi, This is a test", alogorithm);
	qDebug() << "Checksum: " << Checksum::textChecksum(u8"中文測試", alogorithm);
	qDebug() << "Checksum: " << Checksum::fileChecksum(file1, alogorithm);
	qDebug() << "Checksum: " << Checksum::fileChecksum(file2, alogorithm);
	qDebug() << "Checksum: " << Checksum::fileChecksum(file3, alogorithm);

	return app.exec();
}
