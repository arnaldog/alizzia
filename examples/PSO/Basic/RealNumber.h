/*
 * File:	RealNumber.h
 * Author:	arnaldogaspar
 *
 * Created on 23 de febrero del 2013, 17:58-
 */


#ifndef REALNUMBER_H
#define REALNUMBER_H

class RealNumber {
	public:
		RealNumber();
		RealNumber(const RealNumber& orig);
		virtual ~RealNumber();

		RealNumber operator>(const RealNumber &b);
		RealNumber operator+(const RealNumber &b);
		RealNumber operator-(const RealNumber &b);
		RealNumber operator*(float m);
		float fitnessFunction(RealNumber &r);
		void initRandomPosition(RealNumber &r);
		void initRandomVelocity(RealNumber &r);
		float value;
};

#endif /* REALNUMBER_H */
