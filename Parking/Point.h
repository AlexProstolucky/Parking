#pragma once
class Point
{
private:
	int x;
	int y;
	int z;
public:
	Point();
	Point(int x, int y, int z);
	int getX();
	int getY();
	int getZ();
	void set(int x, int y, int z);
};

