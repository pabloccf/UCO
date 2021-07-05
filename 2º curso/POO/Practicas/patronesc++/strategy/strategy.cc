#include <iostream>
#include <string>
using namespace std;

class Behaviour { //Strategy
    public:
	virtual void moveCommand()=0;
};

class AgressiveBehaviour:public Behaviour{
    public:
    void moveCommand() override
	{
		cout <<"\t**Agressive Behaviour**: if find another robot attack it \n";
	}
};

class DefensiveBehaviour: public Behaviour{
    public:
	void moveCommand() override
	{
		cout << "\t++Defensive Behaviour++: if find another robot run from it\n";
	}
};

class NormalBehaviour: public Behaviour{
    public:
	void moveCommand() override
	{
		cout << "\t$$Normal Behaviour$$: if find another robot ignore it\n";
	}
};

class Robot {
	private:
		Behaviour *behaviour_;
		string name_;
    public:
		Robot(string name){name_=name;}
		void setBehaviour(Behaviour *behaviour){behaviour_=behaviour;}
		void move()
		{
			cout << name_ + ": Based on current position " +
						 "the behaviour object decide the next move:\n";
			behaviour_->moveCommand();
		}
		string getName(){return name_;}
		void setName(string name){name_=name;}
};	

int main(void){
    Robot *r1 = new Robot("Big Robot");
	Robot *r2 = new Robot("George v.2.1");
	Robot *r3 = new Robot("R2");
	
    cout << "Robots roaming:\n";
	AgressiveBehaviour *ab= new AgressiveBehaviour();
	DefensiveBehaviour *db= new DefensiveBehaviour();
	NormalBehaviour    *nb= new NormalBehaviour();
	r1->setBehaviour(ab);
	r2->setBehaviour(db);
	r3->setBehaviour(nb);

	r1->move();
	r2->move();
	r3->move();

    cout << "--------------------------------\n";
	cout <<"\nNew behaviours: " <<
			"\n\t'Big Robot' gets really scared" <<
			"\n\t'George v.2.1' becomes really mad because" <<
			"it's always attacked by other robots" <<
			"\n\t and R2 keeps its calm\r\n";
	cout << "--------------------------------\n";
	r1->setBehaviour(db);
	r2->setBehaviour(ab);

	r1->move();
	r2->move();
	r3->move();
	delete ab;
	delete db;
	delete nb;
	delete r1;
	delete r2;
	delete r3;
}