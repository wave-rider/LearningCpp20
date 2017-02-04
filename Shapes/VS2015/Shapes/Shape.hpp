#pragma once
class Shape
{
public:
	Shape();
	virtual ~Shape();
	virtual void rotate(int angle) = 0;
};

