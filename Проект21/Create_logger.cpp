#include "Poco/AutoPtr.h"
#include "Poco/Path.h"
#include "Poco/Util//IniFileConfiguration.h"
#include "Poco/Util/PropertyFileConfiguration.h"
#include "Poco/Util//XMLConfiguration.h"
#include "Poco/Util//IniFileConfiguration.h"
#include "Poco/Util/PropertyFileConfiguration.h"
#include <Poco/FileChannel.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/PatternFormatter.h>
#include <Poco/Logger.h>
#include <Poco/LogStream.h>
#include <Poco/Message.h>#include "Poco/Util//XMLConfiguration.h"

#include <iostream>
#include <string>


using Poco::Path;
using Poco::AutoPtr;
using Poco::Util::IniFileConfiguration;
using Poco::Util::PropertyFileConfiguration;
using Poco::Util::XMLConfiguration;
using Poco::Logger;
using Poco::LogStream;
using Poco::FileChannel;
using Poco::ConsoleChannel;
using Poco::PatternFormatter;
using Poco::FormattingChannel;

using namespace std;

void readFromXml()
{
	AutoPtr<XMLConfiguration> pConf(new XMLConfiguration("conf.xml"));
	std::string prop1 = pConf->getString("prop1");
	std::cout << prop1 << std::endl;

	int prop2 = pConf->getInt("prop2");
	std::cout << prop2 << std::endl;

	std::string prop3 = pConf->getString("prop3"); // ""
	std::cout << prop3 << std::endl;

	std::string prop4 = pConf->getString("prop3.prop4"); // ""
	std::cout << prop4 << std::endl;

	prop4 = pConf->getString("prop3.prop4[@attr]"); // "value3"
	std::cout << prop4 << std::endl;

	prop4 = pConf->getString("prop3.prop4[1][@attr]"); // "value4
	std::cout << prop4 << "\n________________________\n\n\n";


}
void readFromPropertyFile()
{
	AutoPtr<PropertyFileConfiguration> pConf;
	pConf = new PropertyFileConfiguration("prop_file.prop");
	std::string key1 = pConf->getString("key1");
	std::cout << key1 << std::endl;

	int value = pConf->getInt("key2");
	std::cout << value << std::endl;

	std::string longVal = pConf->getString("key3.longValue");
	std::cout << longVal << "\n________________________\n\n\n";
}
void readFtomIniFile()
{
	AutoPtr<IniFileConfiguration> pConf(new IniFileConfiguration("my.ini"));
	std::string path = pConf->getString("MyApplication.somePath");
	std::cout << path << std::endl;
	int value = pConf->getInt("MyApplication.someValue");
	std::cout << value << std::endl;

	std::string str = pConf->getString("MyApplication.someValue");
	std::cout << str << std::endl;

	value = pConf->getInt("myapplication.SomeValue");
	std::cout << value << std::endl;

	value = pConf->getInt("myapplication.SomeOtherValue", 456);
	std::cout << value << "\n________________________\n\n\n";;

}

void CreateFileLogger()
{
	AutoPtr<FileChannel> pFileChannel(new FileChannel);
	AutoPtr<PatternFormatter> pPF(new PatternFormatter);
	pPF->setProperty("pattern", "%Y-%m-%d %H:%M:%S %s: Priority %l: %p %t");
	pPF->setProperty("times", "local");
	// лог-файл буде створюватись в поточній директорії виконуваного файла( або проекту - при запуску у студії)
	pFileChannel->setProperty("path", Poco::Path::current() + "PocoLogger.log");

	pFileChannel->setProperty("rotation", "100");// ротація(створення нового лог- файлу) після досягнення розміру 100 байт
												 //pFileChannel->setProperty("rotation", "2 K"); // ротація(створення нового лог- файлу) після досягнення розміру 2 Кбайт
												 //pFileChannel->setProperty("rotation", "1 days");

												 //pFileChannel->setProperty("purgeAge", "100 seconds"); // purge age - залишити лог-файли, які створені за  останні 100 секунд
												 //pFileChannel->setProperty("purgeCount", "30"); // максимальна кількість створених файлів = 30

												 //pFileChannel->setProperty("compress", "true"); //створювати архіви логів
	pFileChannel->setProperty("archive", "timestamp"); //до назви файлу додається timestamp
	AutoPtr<FormattingChannel> pFC(new FormattingChannel(pPF, pFileChannel));
	Logger::get("FileLogger").setChannel(pFC);
}

void readFromXml()
{
	AutoPtr<XMLConfiguration> pConf(new XMLConfiguration("conf.xml"));
	std::string prop1 = pConf->getString("prop1");
	std::cout << prop1 << std::endl;

	int prop2 = pConf->getInt("prop2");
	std::cout << prop2 << std::endl;

	std::string prop3 = pConf->getString("prop3"); // ""
	std::cout << prop3 << std::endl;

	std::string prop4 = pConf->getString("prop3.prop4"); // ""
	std::cout << prop4 << std::endl;

	prop4 = pConf->getString("prop3.prop4[@attr]"); // "value3"
	std::cout << prop4 << std::endl;

	prop4 = pConf->getString("prop3.prop4[1][@attr]"); // "value4
	std::cout << prop4 << "\n________________________\n\n\n";


}

void readFromPropertyFile()
{
	AutoPtr<PropertyFileConfiguration> pConf;
	pConf = new PropertyFileConfiguration("prop_file.prop");
	std::string key1 = pConf->getString("key1");
	std::cout << key1 << std::endl;

	int value = pConf->getInt("key2");
	std::cout << value << std::endl;

	std::string longVal = pConf->getString("key3.longValue");
	std::cout << longVal << "\n________________________\n\n\n";
}

void readFtomIniFile()
{
	AutoPtr<IniFileConfiguration> pConf(new IniFileConfiguration("my.ini"));
	std::string path = pConf->getString("MyApplication.somePath");
	std::cout << path << std::endl;
	int value = pConf->getInt("MyApplication.someValue");
	std::cout << value << std::endl;

	std::string str = pConf->getString("MyApplication.someValue");
	std::cout << str << std::endl;

	value = pConf->getInt("myapplication.SomeValue");
	std::cout << value << std::endl;

	value = pConf->getInt("myapplication.SomeOtherValue", 456);
	std::cout << value << "\n________________________\n\n\n";;

}





void CreateConsoleLoggerfromFile(string file)
{

	string extfile = file.substr(file.find_last_of(".") + 1);
	
	if (extfile=="ini")
	{



	} 
	else if (extfile == "prop")
	{


	}
	else if (extfile == "xml")
	{


	}
	else
	{


	}



}


void CreateFileLoggerfromFile(string file)
{

}








int main()
{


	try {
		readFtomIniFile();
		readFromPropertyFile();
		readFromXml();

		//////////////////////////


	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}