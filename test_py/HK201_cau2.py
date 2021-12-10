# Lop NLTT HK201_CQ, thi HK
# Cau 2_NL Gio
# Matlab tinh goc theo rad!
import math

pi = math.pi

H=90 # Cao do so voi mat bien
H0=65 # Cao do khao sat
Vavg_65=7.2 # [m/s]
H1=110 # Cao do lap dat
D=136 # Duong kinh
P_r=4.2e6 # 4.2MW
Tabm=29 # [oC]
R=8.2056e-5 # [m3.atm/(K.mol)]
T=273+Tabm # [oK]
MW=28.97 # air=28.97g/mol
Po=1 # atm
print('Kieu My _____________________')
# Cau a
# Cach 1-------------------
KT=(0.95*4 + 0.97*1)/5 # Nhiet do 29oC
KA=0.977 # Do cao lap turbine so voi mat bien: H0+H1 = 200m
ro=1.225*KT*KA
# Cach 2-------------------
P=Po*math.exp(-1.185e-4*(H+H1))
ro=P*MW*1e-3/R/T
alfa1=0.1 # Mat dat bang phang
Vavg_110 = Vavg_65*(H1/H0)**alfa1
E_year_a=15.7*ro/1.225 # [GWh/year] - tra do thi o van toc gio 7,59 m/s
CF=E_year_a*1e9/(P_r*8760)
# Cau b
A=pi*D**2/4
v_r=(P_r/0.3*2/1.225/A)**(1/3) # m/s
T_low_r=(1-math.exp(-pi/4*(v_r/Vavg_110)**2))*8760 #[h]
T_low_25=(1-math.exp(-pi/4*(25/Vavg_110)**2))*8760 #[h]
T_pr=T_low_25-T_low_r #[h]
E_r=P_r/1e9*T_pr # [GWh/year]
p_E_r=E_r/E_year_a*100
# Cau c
N_turbine=1000/(E_year_a*0.8) # < 85.4 turbine
N_turbine = 81 # Chon N_turbine = 81 turbine, lap thanh luoi vuong 9x9
# Khoang cach 8,5D: he so mang la 0.84
hsm_c=0.85
E_farm_c=N_turbine*E_year_a*hsm_c
CF_farm_c=E_farm_c*1e9/(81*P_r*8760)
print('Ket qua ______________________')
print('Kieu My: alfa=0.1: Smooth hard ground, calm water__________')
print('a) Vavg_110 = #f [m/s]', Vavg_110)
print('a) ro = #f [kg/m3]', ro)
print('a) E_year_a = #f [GWh/turbine]', E_year_a)
print('a) CF = #f', CF)
print('.')
print('b) Vr = #f [m/s]', v_r)
print('b) Thoi gian may pha cong suat dinh muc: T_pr = #f [h]', T_pr)
print('b) Ty le san luong turbine phat o cong suat dinh muc: #f [##]', p_E_r)
print('b) Turbine gio lam viec o dinh mua trong khoang thoi gian TRUNG BINH, duong kinh canh quat va chieu cao tru thap DA PHU HOP')
print('.')
print('c) He so mang: #f ung voi khoang cach luoi vuong 8,5D.', hsm_c)
print('c) E_farm_c = #f [GWh/81 turbines]', E_farm_c)
print('c) CF_farm_c = #f', CF_farm_c)
