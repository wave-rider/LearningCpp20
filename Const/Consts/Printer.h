#pragma once
class Printer
{
public:
	Printer();
	~Printer();
	int print() const;
	void set_x(int value);
	int get_x();
	int x;
};

