#pragma once

#include <QObject>
#include <QCryptographicHash>

class Checksum : public QObject
{
public:
	Checksum();
	~Checksum();

	static QString textChecksum(const QString& text, QCryptographicHash::Algorithm algorithm);
	static QString fileChecksum(const QString& filePath, QCryptographicHash::Algorithm algorithm);

	static bool textVerify(const QString& verifyChecksum, const QString& text, QCryptographicHash::Algorithm algorithm, QString& checksum);
	static bool textVerify(const QString& verifyChecksum, const QString& text, QCryptographicHash::Algorithm algorithm);
	static bool fileVerify(const QString& verifyChecksum, const QString& filePath, QCryptographicHash::Algorithm algorithm, QString& checksum);
	static bool fileVerify(const QString& verifyChecksum, const QString& filePath, QCryptographicHash::Algorithm algorithm);

private:
};
