#include "Poco/DateTime.h"
#include "Poco/Timestamp.h"
#include "Poco/LocalDateTime.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeParser.h"
#include "Poco/Timezone.h"
#include  "Poco/Timespan.h"
#include <iostream>
#include <fstream>

using namespace std;

using Poco::DateTime;
using Poco::Timespan;
using Poco::Timezone;
using Poco::Timestamp;
using Poco::LocalDateTime;
using Poco::DateTimeParser;
using Poco::DateTimeFormatter;

std::string TimestampToString(const Timestamp& utcTime, const std::string& format = "%Y-%m-%d %H:%M:%S.%i")
{
	LocalDateTime localTime(utcTime);
	return DateTimeFormatter::format(localTime, format);
}

std::string DateTimeToString(const DateTime& dateTime, const std::string& format = "%Y-%m-%d %H:%M:%S.%i")
{
	return DateTimeFormatter::format(dateTime, format);
}
Timestamp StringToTimestamp(const std::string& timeStr, const std::string& format = "%Y-%m-%d %H:%M:%S.%i")
{
	auto time = Poco::Timestamp();

	if (!timeStr.empty())
	{
		int tzd = 0;
		auto dateTime = DateTimeParser::parse(format, timeStr, tzd);

		if (tzd == 0)
			tzd = (Timezone::isDst(dateTime.timestamp())) ? Timezone::utcOffset() + 3600 : Timezone::utcOffset();

		dateTime.makeUTC(tzd);
		time = dateTime.timestamp();

	}

	return time;
}

inline DateTime StringToDateTime(const std::string& timeStr, const std::string& format = "%Y %m %d %H:%M:%S.%i")
{
	int tzd = 0;
	return DateTimeParser::parse(format, timeStr, tzd);

	//DateTime dt;
	//if (DateTimeParser::tryParse(timeStr, dt, tzd))
	//{
	//	return dt;
	//}
	//else
	//{
	//	std::cout << "not parse!!!\n";
	//	return dt;
	//}
}

void SetTextColor(int x, int y, int color, string text)
{
	COORD cursorPos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << text << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}




int main()

{

	/*LocalDateTime now;

	string data1;
	string data2;


	DateTime dt(2018, 10, 5, 14, 10, 5,100);
	//DateTime dt(2018, 10, 5, 14, 10, 5, 100);


	data1 = DateTimeToString(dt);
	cout << data1 << endl;

	ofstream saver("data.txt");
	saver << data1 << endl;
	saver.close();



	ifstream reader("data.txt");
	getline(reader, data2);
	reader.close();


	DateTime dt1 = StringToDateTime(data2);
	cout << data2 << endl;
	cout << dt1.hour() << ":" << dt1.minute() << endl;
	cout << DateTimeToString(dt1)<< endl;
	*/
	/*
	LocalDateTime now1;
	Timespan Duration;
	int timer = 10;
	int maxtimer = 50;


	auto  tstart = clock();
	while (Duration.seconds()!= maxtimer)
	{
	LocalDateTime now2;
	Duration = now2 - now1;
	if (clock() - tstart == 10)
	{
	SetTextColor(2, 10, 14, to_string(Duration.seconds()));
	tstart = clock();
	}





	}

	*/
	string data1;

	auto  tstart = clock();

	while (true)
	{
		if (clock() - tstart == 500)
		{
			LocalDateTime now;
			DateTime dt(now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second(), now.millisecond());
			tstart = clock();
			data1 = DateTimeToString(dt);
			SetTextColor(2, 10, 14, data1);
		}
	}



	return 0;
}