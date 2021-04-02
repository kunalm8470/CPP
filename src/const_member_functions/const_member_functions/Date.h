#ifndef DATE_H
#define DATE_H

class Date
{
	private:
		int m_day{};
		int m_month{};
		int m_year{};

	public:
		Date() = default;
		Date(int year, int month, int day) : m_year(year),
			m_month(month),
			m_day(day)
		{

		}

		int get_day() const;
		int get_month() const;
		int get_year() const;
};

void to_string(const Date& d);

#endif