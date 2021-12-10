# Lop NLTT HK202_CQ, Thi HK
# Cau 3_Fuel cell
# Matlab tinh goc theo rad!
import math

T=25+273.15 #[oK]
MW = 2*1 # H2
Pa = 3.5 # kW
Va = 50 # km/h
Sa = 1000 # km
m_H2 = 5 # kg
print('Cau a ___________________________')
 #H2 + 1/2*O2 -> H2O (liquid)
#H: 0 0 -285.8
#G: 0 0 -237.2
delta_H = (-285.8)-0-0 #[kJ/mol]: Nang luong tong
#delta_G = (-237.2)-0-0 #[kJ/mol]: Dien nang ly tuong
W_mol = abs(delta_H) #[kJ/mol H2]
W_kg = W_mol/3600*1000/MW #[kWh/kg H2]
We_kg = Sa/Va*Pa/m_H2 #[kWh/kg H2]
Eff=We_kg/W_kg #Hieu suat tong
print('Cau b ___________________________')
V_total=250 # Vdc
n_H2_tt = m_H2/(Sa/Va) # [kg/h]
n_H2_molps = n_H2_tt*1000/3600/MW #[mol/s]
I_total = n_H2_molps*(6.022e23)*(1.602e-19)*2 #[A]
Vcell_tt = Pa*1000/I_total #[V] 
n_cell_series = round(V_total/Vcell_tt)
V_pack = n_cell_series*Vcell_tt
I_cell = I_total/n_cell_series
print('Ket qua ___________________________')
print('a) Hieu suat thuc cua pin = #f [##]', Eff*100)
print('.')
print('b) Dien ap bo pin = #f [V]', V_pack)
print('b) So cell noi tiep = #f [cell]', n_cell_series)
print('b) Dong dien qua moi cell = #f [A]', I_cell)