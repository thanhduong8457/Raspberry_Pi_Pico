import math
#https://github.com/IvanFernandezGracia/delta_robot_tesis
H = 10 # Cao do tren mat bien
H0 = 65 # Do cao khao sat
Vavg_65 = 7 # [m/s]
H1 = 91.5 # Do cao lap dat
D = 117 # Duong kinh
Pr = 4.2e6 # 4MW
Tabm = 27 # [oC]
R = 8.2056e-5 # [m3.atm/(K.mol)]
T = 273 + Tabm # [oK]
MW = 28.97 # air = 28.97g/mol
Po = 1 # atm
print('Kieu My _____________________')
# Cau a
alfa1 = 0.1 # Mat dat bang phang
Vavg_91 = Vavg_65*(H1/H0)**alfa1
# Cach 1-------------------
P = Po*math.exp(-1.185e-4*(H+H1))
ro = P*MW*1e-3/R/T
A = math.pi*D**2/4
Pw_avg = 6/math.pi*1/2*ro*A*Vavg_91**3
# Cau b
E_year = 13.3e9*ro/1.225 # Tra do thi: 13.3 GWh, ung voi 7,24m/s, Pay attention to this point
CF = E_year/Pr/8760
# Cau c
T_low_3 = (1-math.exp(-math.pi/4*(3/Vavg_91)**2))*8760 # estimate the time the wind velocity is less than 3 m/s in years
# Cau d
E_year_farm = E_year*0.74*64 # San luong hang nam # 0.74 là hiệu suất ghép mảng(tra đồ thị)
M_year_farm = E_year_farm*2 - 20e9 # 2d/Wh
Mo = 64*Pr*35000
SPP = Mo/M_year_farm # nam
# Cau e
H2 = 84 # Do cao lap dat
Vavg_84 = Vavg_65*(H2/H0)**alfa1
# Cach 1-------------------
P_e = Po*math.exp(-1.185e-4*(H+H2))
ro_e = P_e*MW*1e-3/R/T
Pw_avg_e = 6/math.pi*1/2*ro_e*A*Vavg_84**3
E_year_e = 12.9e9*ro_e/1.225 # Tra do thi: 12.9GWh, ung voi 7,18m/s
Eff_ew_a = (E_year/8760)/Pw_avg
Eff_ew_e = (E_year_e/8760)/Pw_avg_e
print('___________________________Ket qua___________________________')
print('Kieu My:alfa = 0.1: Smooth hard ground, calm water___________')
print('a) Vavg_91   = ', Vavg_91, ' [m/s]')
print('a) ro        = ', ro, ' [kg/m3]')
print('a) Pw_avg    = ', Pw_avg/1e6, ' [MW]')
print('b) E_year    = ', E_year/1e9, ' [GWh]')
print('b) CF        = ', CF, ' ')
print('c) T_low_3   = ', T_low_3, ' [h]')
print('d) SPP       = ', SPP, ' [nam]')
print('e) Vavg_84   = ', Vavg_84, ' [m/s]')
print('e) ro        = ', ro_e, ' [kg/m3]' )
print('e) E_year    = ', E_year_e/1e9, ' [GWh]')
print('e) San luong giam ', (E_year - E_year_e)/E_year*100, '% = > Nen giam chieu cao.')
print('e) Hieu suat gio - dien cua a: ', Eff_ew_a, '%')
print('e) Hieu suat gio - dien cua e: ', Eff_ew_e, '% = > It thay doi')