#include "checksum.h"

#include <QFile>
#include <QDebug>

Checksum::Checksum()
{
}

Checksum::~Checksum()
{
}

QString Checksum::textChecksum(const QString& text, QCryptographicHash::Algorithm algorithm)
{
	QCryptographicHash hash(algorithm);
	hash.addData(QByteArray(text.toUtf8()));
	return QString(hash.result().toHex());
}

QString Checksum::fileChecksum(const QString& filePath, QCryptographicHash::Algorithm algorithm)
{
	QFile file(filePath);
	if (file.open(QFile::ReadOnly))
	{
		QCryptographicHash hash(algorithm);

		if (hash.addData(&file))
		{
			return QString(hash.result().toHex());
		}
	}

	return "";
}

bool Checksum::textVerify(const QString& verifyChecksum, const QString& text, QCryptographicHash::Algorithm algorithm, QString& checksum)
{
	checksum = textChecksum(text, algorithm);
	if (checksum == verifyChecksum)
	{
		return true;
	}

	return false;
}

bool Checksum::textVerify(const QString& verifyChecksum, const QString& text, QCryptographicHash::Algorithm algorithm)
{
	QString checksum;
	return textVerify(verifyChecksum, text, algorithm, checksum);
}

bool Checksum::fileVerify(const QString& verifyChecksum, const QString& filePath, QCryptographicHash::Algorithm algorithm, QString& checksum)
{
	checksum = fileChecksum(filePath, algorithm);
	if (checksum == verifyChecksum)
	{
		return true;
	}

	return false;
}

bool Checksum::fileVerify(const QString& verifyChecksum, const QString& filePath, QCryptographicHash::Algorithm algorithm)
{
	QString checksum;
	return fileVerify(verifyChecksum, filePath, algorithm, checksum);
}
