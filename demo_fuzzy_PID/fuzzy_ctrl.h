#ifndef FUZZY_CTRL_H_INCLUDED
#define FUZZY_CTRL_H_INCLUDED
class FUZZY {
private:
	float data_hlt_e[9] = {-20, -15, -10, -5, 0, 5, 10, 15, 20};
	float data_hlt_e_dot[3] = {-5, 0, 5};
	float data_kp[7] = {10, 9, 8, 7, 6, 5, 4};
	float data_ki[7] = {14, 12, 10, 8, 6, 4, 2};
	float data_kd[7] = {9, 8, 7, 6, 5, 4, 3};

	float rule_kp[27];
	float rule_ki[27];
	float rule_kd[27];
	float muy_e[9];
	float muy_e_dot[3];
	float beta[27];

	void initialize();
	void rule_fuzzy();

public:
	FUZZY();
	~FUZZY();
	void value_hlt_e(float);
	void value_hlt_e_dot(float);
	void find_beta();
	float defuzzy_kp();
	float defuzzy_ki();
	float defuzzy_kd(); 
};

#endif // FUZZY_CTRL_H_INCLUDED