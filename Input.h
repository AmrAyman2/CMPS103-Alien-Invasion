#pragma once
class Input
{
	private:

		int N;
		//Number of army units to generate each time step

		int ES, ET, EG, HU;
		//Percentages for Earth units
		int AS, AM, AD;
		//Percentages for Alien unis

		int Prob;
		// If number generated by URG "A" is less than prob then units will be generated

		int eHealth_lower, eHealth_upper;
		//ranges for health of earth army units
		int ePower_lower, ePower_upper;
		//ranges for power of earth army units
		int eAttack_lower, eAttack_upper;
		//ranges for attack_capacity of earth army units

		int aHealth_lower, aHealth_upper;
		//ranges for health of alien army units
		int aPower_lower, aPower_upper;
		//ranges for power of alien army units
		int aAttack_lower, aAttack_upper;
		//ranges for attack_capacity of alien army units
		int virus_prob;

	public:

		Input();
		// constructor reads theinput file nd assigns the values

		int getN();

		int getES(); int getET(); int getEG(); int getHU();
		int getAS(); int getAM(); int getAD();

		int getProb();

		int geteHealth_lower(); int geteHealth_upper();
		int getePower_lower(); int getePower_upper();
		int geteAttack_lower(); int geteAttack_upper();

		int getaHealth_lower(); int getaHealth_upper();
		int getaPower_lower(); int getaPower_upper();
		int getaAttack_lower(); int getaAttack_upper();
		int getVirus_prob();
};