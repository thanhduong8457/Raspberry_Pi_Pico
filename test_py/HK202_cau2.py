# Lop NLTT HK202_CQ, Thi HK
# Cau 2_NL Gio
# Matlab tinh goc theo rad!
import math
H=100 # Cao do so voi mat bien
H0=50 # Cao do khao sat
Vavg_50=7 # [m/s]

H1=100 # Do cao tru turbine
D=117 # Duong kinh
P_r=3.4e6 # 6 MW
Tabm=25 # [oC]
print('Kieu My _________________________________')
print('Cau a _________________________________')
# Cach 1-------------------
R=8.2056e-5 # [m3.atm/(K.mol)]
T=273+Tabm # [oK]
MW=28.97 # air=28.97g/mol
Po=1 # atm
P=Po*math.exp(-1.185e-4*(H+H1))
ro=P*MW*1e-3/R/T
# Cach 2-------------------
KT=0.97 # Nhiet do 25oC
KA=0.977 # Do cao lap turbine so voi mat bien: H0+H1 = 200m
ro=1.225*KT*KA
alfa1=0.15
Vavg_100 = Vavg_50*(H1/H0)**alfa1
print('Cau b _________________________________')
#CF_b=(0.087*Vavg_100 - 0.278)*ro/1.225
CF_b=(0.087*Vavg_100 - 0.278)
E_year_b=CF_b*P_r*8760/1e9 # [GWh/year]
print('Cau c _________________________________')
hsm_c=0.8
E_farm_c=100*E_year_b*hsm_c
CF_farm_c=E_farm_c*1e9/(100*P_r*8760)
print('Cau d _________________________________')
T_low_3=(1-math.exp(-math.pi/4*(3/Vavg_100)**2))*8760 #[h]
T_high_25=math.exp(-math.pi/4*(25/Vavg_100)**2)*8760 #[h]
T_out_3_25=T_low_3+T_high_25 #[h]
print('Ket qua ______________________')
print('a) Vavg_100 = #f [m/s]', Vavg_100)
print('a) ro = #f [kg/m3]', ro)
print('.')
print('b) E_year_b = #f [GWh/turbine]', E_year_b)
print('b) CF_b = #f', CF_b)
print('.')
print('c) E_farm_d = #f [GWh/81 turbines]', E_farm_c)
print('c) CF_farm_d = #f', CF_farm_c)
print('.')
print('d) Thoi gian turbine dung do toc do gio < 3m/s #f [gio]', T_low_3); 
print('d) Thoi gian turbine dung do toc do gio > 25m/s #f [gio]', T_high_25)
print('d) Thoi gian turbine ngoai dai lam viec #f [gio]', T_out_3_25); 
