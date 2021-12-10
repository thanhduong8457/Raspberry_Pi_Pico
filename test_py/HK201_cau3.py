# Lop NLTT HK201_CQ, thi HK
# Cau 3_Fuel cell
# Matlab tinh goc theo rad!
import math

T=25+273.15 #[oK]
Eff_e=0.93 # Ty le giai phong electron
Eff_tt=0.48 # hieu suat thuc te so voi ly thuyet
MW = 2*1 # H2
Pa = 5 # kW
Va = 70 # km/h
Sb = 2000 # km
print('Cau a ___________________________')
#H2 + 1/2*O2 -> H2O (gas)
#0 0 -228.6
delta_G = (-228.6)-0-0 #[kJ/mol-K]
Wer_mol = abs(delta_G) #[kJ/mol H2]
Wer_kg_lt = Wer_mol/3600*1000/MW #[kWh/kg H2]
Wer_kg_tt = Wer_kg_lt*Eff_tt #[kWh/kg H2], tt=thuc te
Wer_kg_total = Wer_kg_tt*Eff_e #[kWh/kg H2] - bao gom hydro khong giai phong electron
n_H2_cc = Pa/Wer_kg_total #kg/h, cc=cung cap
print('Cau b ___________________________')
t_b = Sb/Va # s
m_H2_b = t_b*n_H2_cc # kg
print('Cau c ___________________________')
V_total=100 # Vdc
n_H2_tt = n_H2_cc*Eff_e # [kg/h]
n_H2_molps = n_H2_tt*1000/3600/MW #[mol/s]
I_total = n_H2_molps*(6.022e23)*(1.602e-19)*2 #[A]
Vcell_tt = Pa*1000/I_total #[V] 
n_cell_series = math.ceil(V_total/Vcell_tt)
V_pack = n_cell_series*Vcell_tt
I_cell = I_total/n_cell_series
#I_cell = Pa*1000/V_pack
print('Ket qua ___________________________')
print('a) Luu luong hydro = #f [kg/h]', n_H2_cc)
print('b) Khoi luong hydro chay 2000km = #f [kg]', m_H2_b)
print('c) So cell noi tiep = #f [cell]', n_cell_series)
print('c) Dien ap bo pin = #f [A]', V_pack)
print('c) Dong dien qua moi cell = #f [A]', I_cell)