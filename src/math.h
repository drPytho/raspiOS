#ifndef MATH
#define MATH 


//Tem simple need to fix this up
class Vector2f
{
public:
	Vector2f(float x, float y);
	~Vector2f();

	float GetX()const{return x;}
	float GetY()const{return y;}


private:
	float x;
	float y;

	/* data */
};

#endif