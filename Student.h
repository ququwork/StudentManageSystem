#ifndef STUDENT_H
#define STUDENT_H
class Student {
	public:
		Student()=default;
        Student(long i,std::string n,double p,double nn,double n2);
        Student(std::string n,double p,double nn,double k);
		void steMid(double mid) {
			this->mid=mid;
		}
		void setFinal(int final) {
			this->final=final;
		}
		void setAvg(double avg) {
			this->avg=avg;
		}
		void setName(std::string name) {
			this->name=name;
		}
		std::string getName()const {
			return name;
		}
		double getMid()const {
			return mid;
		}
		double getFinal()const {
			return final;
		}
		double getId()const {
			return id;
		}
		double getAvg()const {
			return avg;
		}

         void output()const;

         std::string getInfo()const;

        static void setNextId(long id){nextId=id;}
        static long getNextId(){return nextId;}

        long autoNextId() {
        return nextId++;
        }
	private:
		long id;
		std::string name;
		double mid; //学生 期末成绩
        int final; //    期末成绩
        static long nextId;

		double avg;

};
#endif // STUDENT_H

