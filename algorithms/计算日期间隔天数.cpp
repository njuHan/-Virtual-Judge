#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>


// tm�ṹ���е����ǵ�ǰ����1900��Ĳ�ֵ���·��Ǵ�0��11��0����1�£�11�´���12��
time_t convert(int year, int month, int day)
{
	tm info = { 0 };
	info.tm_year = year - 1900;  //��� -1900
	info.tm_mon = month - 1; //�·� -1
	info.tm_mday = day;
	return mktime(&info); //���ﴫָ��
}

int  get_days(const char* from, const char* to)
{
	int year, month, day;
	sscanf(from, "%d-%d-%d", &year, &month, &day);
	int fromSecond = (int)convert(year, month, day);
	sscanf(to, "%d-%d-%d", &year, &month, &day);
	int toSecond = (int)convert(year, month, day);
	return (toSecond - fromSecond) / 24 / 3600;

}

int main()
{
	const char* from = "2013-3-15";
	const char* to = "2015-8-14";
	int days = get_days(from, to);
	printf("From:%s\nTo:%s\n", from, to);
	printf("%d\n", days);
	system("pause");
	return 0;
}
